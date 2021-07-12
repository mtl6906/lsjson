#include "ls/json/Double.h"

using std::string;

namespace ls
{
	namespace json
	{
		Double::Double(double &value) : data(value)
		{
		}

		void Double::parse(const string &text)
		{
			data = stod(text);
		}
		
		string Double::toString()
		{
			return std::to_string(data);
		}
	}
}
