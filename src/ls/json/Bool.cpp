#include "ls/json/Bool.h"
#include "ls/cstring/API.h"
#include "ls/Exception.h"

using std::string;

static ls::cstring::API api;

namespace ls
{
	namespace json
	{
		Bool::Bool(bool &value) : data(value)
		{

		}
		
		int Bool::parse(const string &text)
		{
			if(!text.compare("false"))
				data = false;
			else
				data = true;
			return Exception::LS_OK;
		}

		string Bool::toString()
		{
			if(data)
				return "true";
			return "false";
		}
	}
}
