#include "ls/json/Int.h"

using std::string;

namespace ls
{
	namespace json
	{
		Int::Int(int &value) : data(value)
		{
		}

		void Int::parse(const string &text)
		{
			data = stoi(text);
		}
		
		string Int::toString()
		{
			return std::to_string(data);
		}
	}
}