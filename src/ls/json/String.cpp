#include "ls/json/String.h"
#include "ls/cstring/API.h"
#include "ls/Exception.h"

using std::string;

static ls::cstring::API api;

namespace ls
{
	namespace json
	{
		String::String(string &value) : data(value)
		{
	
		}

		int String::parse(const string &text)
		{
			data = std::move(text.substr(1, text.size() - 2));
			return Exception::LS_OK;
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
