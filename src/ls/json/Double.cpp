#include "ls/json/Double.h"
#include "cmath"
#include "ls/DefaultLogger.h"
#include "ls/Exception.h"
#include "iostream"

using namespace std;

using std::string;

namespace ls
{
	namespace json
	{
		int Double::precision = 2;

		Double::Double(double &value) : data(value)
		{
		}

		int Double::parse(const string &text)
		{
			for(int i=0;i<text.size();++i)
				if(text[i] == '.')
				{
					precision = text.size() - 1 - i;
					break;
				}
			data = stod(text);
			return Exception::LS_OK;
		}
		
		string Double::toString()
		{
			int extraLength = log10(data);
			if(extraLength < 0)
				extraLength = 0;
			string result(extraLength + 2 + precision, '\0');
			string format = "%." + std::to_string(precision) +  "f";
			snprintf((char *)result.c_str(), result.size() + 1, format.c_str(), data);
			return result;
		}

		void Double::setPrecision(int _precision)
		{
			precision = _precision;
		}
	}
}
