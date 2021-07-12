#include "ls/json/API.h"

using namespace std;

namespace ls
{
	namespace json
	{
		API api;

		Object API::decode(const string &data)
		{
			Object root;
			root.parseFrom(data);
			return root;
		}	

		string API::encode(Object &root)
		{
			return root.toString();
		}
	//	object get
		int& API::get(Object &root, const string &key, int &o)
		{
			Int i(o);
			root.get(key, &i);
			return o;
		}

		bool& API::get(Object &root, const string &key, bool &o)
		{
			Bool b(o);
			root.get(key, &b);
			return o;
		}

		string& API::get(Object &root, const string &key, string &o)
		{
			String s(o);
			root.get(key, &s);
			return o;
		}

		long long& API::get(Object &root, const string &key, long long &o)
		{
			LongLong ll(o);
			root.get(key, &ll);
			return o;
		}

		Array& API::get(Object &root, const string &key, Array &o)
		{
			root.get(key, &o);
			return o;
		}

		Object& API::get(Object &root, const string &key, Object &o)
		{
			root.get(key, &o);
			return o;
		}

		double& API::get(Object &root, const string &key, double &o)
		{
			Double d(o);
			root.get(key, &d);
			return o;
		}
	//	object push
		void API::push(Object &root, const string &key, int o)
		{
			Int i(o);
			root.push(key, &i);
		}

		void API::push(Object &root, const string &key, bool o)
		{
			Bool b(o);
			root.push(key, &b);
		}

		void API::push(Object &root, const string &key, string &o)
		{
			String s(o);
			root.push(key, &s);
		}

		void API::push(Object &root, const string &key, string &&o)
		{
			String s(o);
			root.push(key, &s);
		}

		void API::push(Object &root, const string &key, long long o)
		{
			LongLong ll(o);
			root.push(key, &ll);
		}

		void API::push(Object &root, const string &key, Array &o)
		{
			root.push(key, &o);
		}
	
		void API::push(Object &root, const string &key, Array &&o)
		{
			root.push(key, &o);
		}

		void API::push(Object &root, const string &key, Object &o)
		{
			root.push(key, &o);
		}

		void API::push(Object &root, const string &key, Object &&o)
		{
			root.push(key, &o);
		}

		void API::push(Object &root, const string &key, double o)
		{
			Double d(o);
			root.push(key, &d);
		}
	//	object replace
		void API::replace(Object &root, const string &key, int o)
		{
			Int i(o);
			root.replace(key, &i);
		}

		void API::replace(Object &root, const string &key, bool o)
		{
			Bool b(o);
			root.replace(key, &b);
		}

		void API::replace(Object &root, const string &key, string &o)
		{
			String s(s);
			root.replace(key, &s);
		}

		void API::replace(Object &root, const string &key, string &&o)
		{
			String s(s);
			root.replace(key, &s);
		}

		void API::replace(Object &root, const string &key, long long o)
		{
			LongLong ll(o);
			root.replace(key, &ll);
		}

		void API::replace(Object &root, const string &key, Array &o)
		{
			root.replace(key, &o);
		}

		void API::replace(Object &root, const string &key, Array &&o)
		{
			root.replace(key, &o);
		}
		
		void API::replace(Object &root, const string &key, Object &o)
		{
			root.replace(key, &o);
		}

		void API::replace(Object &root, const string &key, Object &&o)
		{
			root.replace(key, &o);
		}

		void API::replace(Object &root, const string &key, double o)
		{
			Double d(o);
			root.replace(key, &d);
		}
	//	array get
	  	int& API::get(Array &root, int i, int &o)
		{
			Int _i(o);
			root.get(i, &_i);
			return o;
		}

		bool& API::get(Array &root, int i, bool &o)
		{
			Bool b(o);
			root.get(i, &b);
			return o;
		}

		string& API::get(Array &root, int i, std::string &o)
		{
			String s(o);
			root.get(i, &s);
			return o;
		}

		long long& API::get(Array &root, int i, long long &o)
		{
			LongLong ll(o);
			root.get(i, &ll);
			return o;
		}

		Array& API::get(Array &root, int i, Array &o)
		{
			root.get(i, &o);
			return o;
		}

		Object& API::get(Array &root, int i, Object &o)
		{
			root.get(i, &o);
			return o;
		}

		double &API::get(Array &root, int i, double &o)
		{
			Double d(o);
			root.get(i, &d);
			return o;
		}
	//	array push
		void API::push(Array &root, int o)
		{
			Int _i(o);
			root.push(&_i);
		}

		void API::push(Array &root, bool o)
		{
			Bool b(o);
			root.push(&b);
		}

		void API::push(Array &root, std::string &o)
		{
			String s(o);
			root.push(&s);
		}

		void API::push(Array &root, std::string &&o)
		{
			String s(o);
			root.push(&s);
		}

		void API::push(Array &root, long long o)
		{
			LongLong ll(o);
			root.push(&ll);
		}

		void API::push(Array &root, Array &o)
		{
			root.push(&o);
		}

		void API::push(Array &root, Array &&o)
		{
			root.push(&o);
		}

		void API::push(Array &root, Object &o)
		{
			root.push(&o);
		}

		void API::push(Array &root, Object &&o)
		{
			root.push(&o);
		}

		void API::push(Array &root, double o)
		{
			Double d(o);
			root.push(&d);
		}
	//	array replace
		void API::replace(Array &root, int i, int o)
		{
			Int _i(o);
			root.replace(i, &_i);
		}

		void API::replace(Array &root, int i, bool o)
		{
			Bool b(o);
			root.replace(i, &b);
		}

		void API::replace(Array &root, int i, std::string &o)
		{
			String s(o);
			root.replace(i, &s);
		}

		void API::replace(Array &root, int i, std::string &&o)
		{
			String s(o);
			root.replace(i, &s);
		}

		void API::replace(Array &root, int i, long long o)
		{
			LongLong ll(o);
			root.replace(i, &ll);
		}

		void API::replace(Array &root, int i, Array &o)
		{
			root.replace(i, &o);
		}

		void API::replace(Array &root, int i, Array &&o)
		{
			root.replace(i, &o);
		}

		void API::replace(Array &root, int i, Object &o)
		{
			root.replace(i, &o);
		}

		void API::replace(Array &root, int i, Object &&o)
		{
			root.replace(i, &o);
		}

		void API::replace(Array &root, int i, double o)
		{
			Double d(o);
			root.replace(i, &d);
		}
	}
}
