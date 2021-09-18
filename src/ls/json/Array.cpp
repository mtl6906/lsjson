#include "ls/json/Array.h"
#include "ls/cstring/API.h"
#include "ls/Exception.h"

using std::string;
using std::vector;

static ls::cstring::API api;

namespace ls
{
	namespace json
	{
		Array::Array(int n)
		{
			data.reserve(n);
		}

		void Array::parse(const string &text)
		{
			data.clear();
			if(text == "[]")
				return ;
			if(text[0] != '[')
				throw Exception(Exception::LS_EFORMAT);
			int st = 1, ed = 0, sq = 1, br = 0, qu = 0;
			while(sq)
			{
				++ed;
				if(ed >= text.size())
					break;
				if(text[ed] == '"' && text[ed - 1] != '\\')
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
				if(text[ed] == ',' && sq == 1 && br == 0)
				{
					data.push_back(text.substr(st, ed - st));
					st = ed + 1;
				}
			}
			if(ed >= text.size())
				throw Exception(Exception::LS_EFORMAT);
			data.push_back(text.substr(st, ed - st));
			if(qu || sq || br)
			{
				data.clear();
				throw Exception(Exception::LS_EFORMAT);
			}
		}

		int Array::copyTo(char *text, int len)
		{
			int los = lengthOfString();
			if(len < los)
				throw Exception(Exception::LS_EFULL);
			text = api.append(text, "[");
			for(auto &i : data)
			{
				text = api.append(text, i.c_str());
				text = api.append(text, ",");
			}
			if(data.size() == 0)
				text = api.append(text, "]");
			else
				*(text-1) = ']';
			return los;
		}

		int Array::lengthOfString()
		{
			int len = 1 + data.size();
			for(auto &i : data)
				len += i.size();
			if(len == 1)
				return len + 1;
			return len;
		}

		void Array::push(Item *item)
		{
			data.push_back(item -> toString());
		}

		void Array::get(int i, Item *item)
		{
			item -> parseFrom(data[i]);
		}

		void Array::replace(int i, Item *item)
		{
			item -> parseFrom(data[i]);
		}

		int Array::size()
		{
			return data.size();
		}
	}
}
