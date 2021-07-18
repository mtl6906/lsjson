#include "ls/json/Double.h"
#include "cmath"
#include "ls/DefaultLogger.h"
#include "iostream"

using namespace std;

using std::string;

namespace ls
{
	namespace json
	{
		Double::Double(double &value) : data(value), precision(2)
		{
		}

		void Double::parse(const string &text)
		{
			for(int i=0;i<text.size();++i)
				if(text[i] == '.')
				{
					precision = text.size() - 1 - i;
					break;
				}
			data = stod(text);
		}
		
		string Double::toString()
		{
			string result(log10(data) + 2 + precision, '\0');
			string format = "%." + std::to_string(precision) +  "f";
			snprintf((char *)result.c_str(), result.size() + 1, format.c_str(), data);
			return result;
		}

		Double& Double::setPrecision(int _precision)
		{
			precision = _precision;
			return *this;
		}
	}
}
