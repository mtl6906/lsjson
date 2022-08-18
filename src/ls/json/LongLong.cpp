#include "ls/json/LongLong.h"
#include "ls/Exception.h"
#include "cstring"

using std::string;

namespace ls
{
	namespace json
	{
		LongLong::LongLong(long long &value) : data(value)
		{
	
		}

		int LongLong::parse(const string &text)
		{
			data = stoll(text);
			return Exception::LS_OK;
		}

		string LongLong::toString()
		{
			return std::to_string(data);
		}
	}
}
