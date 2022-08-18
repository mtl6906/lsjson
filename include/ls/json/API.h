#ifndef LS_JSON_API_H
#define LS_JSON_API_H

#include "ls/json/Object.h"
#include "ls/json/Array.h"
#include "ls/json/Int.h"
#include "ls/json/Bool.h"
#include "ls/json/LongLong.h"
#include "ls/json/String.h"
#include "ls/json/Double.h"

namespace ls
{
    namespace json
    {
        class API
        {
            public:
                Object decode(int &ec, const std::string &text);
                std::string encode(Object &root);

		bool isNull(Object &root, const std::string &key);
		bool isNull(Array &root, int i);

                int get(Object &root, const std::string &key, int &o);
                int get(Object &root, const std::string &key, bool &o);
		int get(Object &root, const std::string &key, std::string &o);
                int get(Object &root, const std::string &key, long long &o);
                int get(Object &root, const std::string &key, Array &o);
                int get(Object &root, const std::string &key, Object &o);
		int get(Object &root, const std::string &key, double &o);

                int push(Object &root, const std::string &key, int o);
                int push(Object &root, const std::string &key, bool o);
                int push(Object &root, const std::string &key, std::string &o);
                int push(Object &root, const std::string &key, std::string &&o);
                int push(Object &root, const std::string &key, long long o);
                int push(Object &root, const std::string &key, Array &o);
                int push(Object &root, const std::string &key, Array &&o);
                int push(Object &root, const std::string &key, Object &o);
                int push(Object &root, const std::string &key, Object &&o);
		int push(Object &root, const std::string &key, double o);
		int push(Object &root, const std::string &key);
			
                int replace(Object &root, const std::string &key, int o);
                int replace(Object &root, const std::string &key, bool o);
                int replace(Object &root, const std::string &key, std::string &o);
                int replace(Object &root, const std::string &key, std::string &&o);
                int replace(Object &root, const std::string &key, long long o);
                int replace(Object &root, const std::string &key, Array &o);
                int replace(Object &root, const std::string &key, Array &&o);
                int replace(Object &root, const std::string &key, Object &o);
                int replace(Object &root, const std::string &key, Object &&o);
		int replace(Object &root, const std::string &key, double o);
		int replace(Object &root, const std::string &key);

                int get(Array &root, int i, int &o);
                int get(Array &root, int i, bool &o);
                int get(Array &root, int i, std::string &o);
                int get(Array &root, int i, long long &o);
                int get(Array &root, int i, Array &o);
               	int get(Array &root, int i, Object &o);
		int get(Array &root, int i, double &o);

                void push(Array &root, int o);
                void push(Array &root, bool o);
                void push(Array &root, std::string &o);
                void push(Array &root, std::string &&o);  
                void push(Array &root, long long o);
                void push(Array &root, Array &o);
                void push(Array &root, Array &&o);
                void push(Array &root, Object &o);
                void push(Array &root, Object &&o);
		void push(Array &root, double o);
		void push(Array &root);

                int replace(Array &root, int i, int o);
                int replace(Array &root, int i, bool o);
                int replace(Array &root, int i, std::string &o);
                int replace(Array &root, int i, std::string &&o);
                int replace(Array &root, int i, long long o);
                int replace(Array &root, int i, Array &o);
                int replace(Array &root, int i, Array &&o);
                int replace(Array &root, int i, Object &o);
                int replace(Array &root, int i, Object &&o);
		int replace(Array &root, int i, double o);
		int replace(Array &root, int i);
        };

	extern API api;
    }
}

#endif
