#include "ls/json/Null.h"
#include "ls/Exception.h"

using std::string;

namespace ls
{
	namespace json
	{
		int Null::parse(const string &text)
		{
			return Exception::LS_OK;	
		}
		
		string Null::toString()
		{
			return "null";
		}
	}
}
