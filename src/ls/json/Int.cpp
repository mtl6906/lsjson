#include "ls/json/Int.h"
#include "ls/Exception.h"

using std::string;

namespace ls
{
	namespace json
	{
		Int::Int(int &value) : data(value)
		{
		}

		int Int::parse(const string &text)
		{
			data = stoi(text);
			return Exception::LS_OK;
		}
		
		string Int::toString()
		{
			return std::to_string(data);
		}
	}
}
