#include "ls/json/Object.h"
#include "ls/cstring/API.h"
#include "ls/Exception.h"
#include "utility"

using namespace std;
using std::map;
using std::vector;
using std::pair;

static ls::cstring::API api;

namespace ls
{
	namespace json
	{
		int Object::countWhiteBlank(const string &text)
		{
			int count = 0;
			bool inString = false;
			for(auto it = text.begin(); it != text.end(); ++it)
			{
				if(*it == '\"')
				{
					inString = !inString;
					continue;
				}
				if(inString)
					continue;
				if(*it == '\n' || *it == '\r' || *it == ' ' || *it == '\t')
					++count;
			}
			return count;
		}

		string Object::clearWhiteBlank(const string &text)
		{
			string result(text.size() - countWhiteBlank(text), '\0');
			char *p = (char *)result.c_str();
			bool inString = false;
			for(auto it = text.begin(); it != text.end(); ++it)
			{
				if(*it == '\"')
				{
					*p = *it;
					++p;
					inString = !inString;
					continue;
				}
				if(inString)
				{
					*p = *it;
					++p;
					continue;
				}
				if(*it == '\n' || *it == '\r' || *it == ' ' || *it == '\t')
					continue;
				*p = *it;
				++p;
			}
			return result;
		}

		int Object::parseFrom(const string &value)
		{
			string result = clearWhiteBlank(value);
			int ec = parse(result);
			if(ec < 0)
				return ec;
			return check(result);
		}

		int Object::parse(const string &text)
		{
			clear();
			int st = 1, ed = 0, br = 1, sq = 0, qu = 0;
			while(br)
			{
			//	PARSE KEY
				ed = text.find_first_of(":", ed);
				if(ed == string::npos)
					return Exception::LS_EFORMAT;
				string key = text.substr(st + 1, ed - st - 2);
				st = ed + 1;
			//	PARSE VALUE
				while(1)
				{
				//	QUIT
					if(br == 0)
						break;
					if(ed + 1 >= text.size())
						return Exception::LS_EFORMAT;
					if(text[ed] == ',' && br == 1 && sq == 0 && qu == 0)
						break;
					++ed;
				//	SKIP
					if(text[ed] == '"')
					{
						qu = (qu + 1) % 2;
						continue;
					}
					if(qu)
						continue;
					if(text[ed] == '[')
					{
						++sq;
						continue;
					}
					if(text[ed] == '{')
					{
						++br;
						continue;
					}
					if(text[ed] == ']')
					{
						--sq;
						continue;
					}
					if(text[ed] == '}')
					{
						--br;
						continue;
					}
				}
			//	SET
				string value = text.substr(st, ed - st);
				om.push(key, value);
			//	NEXT PAIR
				st = ed + 1;
			}
			if(qu || br || sq)
			{
				clear();
				return Exception::LS_EFORMAT;
			}
			return Exception::LS_OK;
		}

		int Object::copyTo(char *text, int len)
		{
			int los = lengthOfString();
			if(len < los)
				return Exception::LS_EFULL;
			text = api.append(text, "{");
			for(auto &p : om.getData())
			{
				text = api.append(text, "\"");
				text = api.append(text, p -> first.c_str());
				text = api.append(text, "\":");
				text = api.append(text, p -> second.c_str());
				text = api.append(text, ",");
			}
			if(om.getData().size() == 0)
				text = api.append(text, "}");
			else
				*(text - 1) = '}';
			return los;
		}

		int Object::lengthOfString()
		{
			int len = 1 + 4 * om.getData().size();
			for(auto &it : om.getMapper())
				len += it.first.size() + it.second.size();
			if(len == 1)
				return len + 1;
			return len;
		}

		int Object::get(const string &key, Item *value)
		{
			int ec;
			string text = om.get(ec, key);
			if(ec < 0)
				return ec;
			return value -> parseFrom(text);
		}

		int Object::push(const string &key, Item *value)
		{
			return om.push(key, value -> toString());
		}

		int Object::replace(const string &key, Item *value)
		{
			return om.replace(key, value -> toString());
		}

		void Object::clear()
		{
			om.clear();
		}

		OrderedMap<string, string> &Object::getData()
		{
			return om;
		}
	}
}
