#include "ls/json/String.h"
#include "ls/cstring/API.h"

using std::string;

static ls::cstring::API api;

namespace ls
{
	namespace json
	{
		String::String(string &value) : data(value)
		{
	
		}

		void String::parse(const string &text)
		{
			data = std::move(text.substr(1, text.size() - 2));
		}

		string String::toString()
		{
			string text;
			text.reserve(data.size() + 2);
			text.append("\"");
			text.append(data);
			text.append("\"");
			return text;
		}
	}
}
