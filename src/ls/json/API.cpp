#include "ls/json/API.h"
#include "ls/json/Null.h"
#include "ls/Exception.h"

using namespace std;

namespace ls
{
	namespace json
	{
		API api;

		Object API::decode(int &ec, const string &data)
		{
			Object root;
			ec = root.parseFrom(data);
			return root;
		}	

		string API::encode(Object &root)
		{
			return root.toString();
		}
	// is null
		bool API::isNull(Object &root, const string &key)
		{
			Null null;
			int ec = root.get(key, &null);
			return ec == Exception::LS_OK; 
		}

		bool API::isNull(Array &root, int i)
		{
			Null null;
			int ec = root.get(i, &null);
			return ec == Exception::LS_OK;
		}
		

	//	object get
		int API::get(Object &root, const string &key, int &o)
		{
			Int i(o);
			return root.get(key, &i);
		}

		int API::get(Object &root, const string &key, bool &o)
		{
			Bool b(o);
			return root.get(key, &b);
		}

		int API::get(Object &root, const string &key, string &o)
		{
			String s(o);
			return root.get(key, &s);
		}

		int API::get(Object &root, const string &key, long long &o)
		{
			LongLong ll(o);
			return root.get(key, &ll);
		}

		int API::get(Object &root, const string &key, Array &o)
		{
			return root.get(key, &o);
		}

		int API::get(Object &root, const string &key, Object &o)
		{
			return root.get(key, &o);
		}

		int API::get(Object &root, const string &key, double &o)
		{
			Double d(o);
			return root.get(key, &d);
		}

	//	object push
		int API::push(Object &root, const string &key, int o)
		{
			Int i(o);
			return root.push(key, &i);
		}

		int API::push(Object &root, const string &key, bool o)
		{
			Bool b(o);
			return root.push(key, &b);
		}

		int API::push(Object &root, const string &key, string &o)
		{
			String s(o);
			return root.push(key, &s);
		}

		int API::push(Object &root, const string &key, string &&o)
		{
			String s(o);
			return root.push(key, &s);
		}

		int API::push(Object &root, const string &key, long long o)
		{
			LongLong ll(o);
			return root.push(key, &ll);
		}

		int API::push(Object &root, const string &key, Array &o)
		{
			return root.push(key, &o);
		}
	
		int API::push(Object &root, const string &key, Array &&o)
		{
			return root.push(key, &o);
		}

		int API::push(Object &root, const string &key, Object &o)
		{
			return root.push(key, &o);
		}

		int API::push(Object &root, const string &key, Object &&o)
		{
			return root.push(key, &o);
		}

		int API::push(Object &root, const string &key, double o)
		{
			Double d(o);
			return root.push(key, &d);
		}

		int API::push(Object &root, const string &key)
		{
			Null null;
			return root.push(key, &null);
		}

	//	object replace
		int API::replace(Object &root, const string &key, int o)
		{
			Int i(o);
			return root.replace(key, &i);
		}

		int API::replace(Object &root, const string &key, bool o)
		{
			Bool b(o);
			return root.replace(key, &b);
		}

		int API::replace(Object &root, const string &key, string &o)
		{
			String s(s);
			return root.replace(key, &s);
		}

		int API::replace(Object &root, const string &key, string &&o)
		{
			String s(s);
			return root.replace(key, &s);
		}

		int API::replace(Object &root, const string &key, long long o)
		{
			LongLong ll(o);
			return root.replace(key, &ll);
		}

		int API::replace(Object &root, const string &key, Array &o)
		{
			return root.replace(key, &o);
		}

		int API::replace(Object &root, const string &key, Array &&o)
		{
			return root.replace(key, &o);
		}
		
		int API::replace(Object &root, const string &key, Object &o)
		{
			return root.replace(key, &o);
		}

		int API::replace(Object &root, const string &key, Object &&o)
		{
			return root.replace(key, &o);
		}

		int API::replace(Object &root, const string &key, double o)
		{
			Double d(o);
			return root.replace(key, &d);
		}

		int API::replace(Object &root, const string &key)
		{
			Null null;
			return root.replace(key, &null);
		}

	//	array get
	  	int API::get(Array &root, int i, int &o)
		{
			Int _i(o);
			return root.get(i, &_i);
		}

		int API::get(Array &root, int i, bool &o)
		{
			Bool b(o);
			return root.get(i, &b);
		}

		int API::get(Array &root, int i, std::string &o)
		{
			String s(o);
			return root.get(i, &s);
		}

		int API::get(Array &root, int i, long long &o)
		{
			LongLong ll(o);
			return root.get(i, &ll);
		}

		int API::get(Array &root, int i, Array &o)
		{
			return root.get(i, &o);
		}

		int API::get(Array &root, int i, Object &o)
		{
			return root.get(i, &o);
		}

		int API::get(Array &root, int i, double &o)
		{
			Double d(o);
			return root.get(i, &d);
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

		void API::push(Array &root)
		{
			Null null;
			root.push(&null);
		}

	//	array replace
		int API::replace(Array &root, int i, int o)
		{
			Int _i(o);
			return root.replace(i, &_i);
		}

		int API::replace(Array &root, int i, bool o)
		{
			Bool b(o);
			return root.replace(i, &b);
		}

		int API::replace(Array &root, int i, std::string &o)
		{
			String s(o);
			return root.replace(i, &s);
		}

		int API::replace(Array &root, int i, std::string &&o)
		{
			String s(o);
			return root.replace(i, &s);
		}

		int API::replace(Array &root, int i, long long o)
		{
			LongLong ll(o);
			return root.replace(i, &ll);
		}

		int API::replace(Array &root, int i, Array &o)
		{
			return root.replace(i, &o);
		}

		int API::replace(Array &root, int i, Array &&o)
		{
			return root.replace(i, &o);
		}

		int API::replace(Array &root, int i, Object &o)
		{
			return root.replace(i, &o);
		}

		int API::replace(Array &root, int i, Object &&o)
		{
			return root.replace(i, &o);
		}

		int API::replace(Array &root, int i, double o)
		{
			Double d(o);
			return root.replace(i, &d);
		}

		int API::replace(Array &root, int i)
		{
			Null null;
			return root.replace(i, &null);
		}
	}
}
