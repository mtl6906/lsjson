#include "ls/json/Bool.h"
#include "ls/cstring/API.h"

using std::string;

static ls::cstring::API api;

namespace ls
{
	namespace json
	{
		Bool::Bool(bool &value) : data(value)
		{

		}
		
		void Bool::parse(const string &text)
		{
			if(!text.compare("false"))
				data = false;
			else
				data = true;
		}

		string Bool::toString()
		{
			if(data)
				return "true";
			return "false";
		}
	}
}
