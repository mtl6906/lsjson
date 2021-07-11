#include "ls/json/LongLong.h"
#include "cstring"

using std::string;

namespace ls
{
	namespace json
	{
		LongLong::LongLong(long long &value) : data(value)
		{
	
		}

		void LongLong::parse(const string &text)
		{
			data = stoll(text);
		}

		string LongLong::toString()
		{
			return std::to_string(data);
		}
	}
}
