#ifndef LS_JSON_API_H
#define LS_JSON_API_H

#include "ls/json/Object.h"
#include "ls/json/Array.h"
#include "ls/json/Int.h"
#include "ls/json/Bool.h"
#include "ls/json/LongLong.h"
#include "ls/json/String.h"


namespace ls
{
    namespace json
    {
        class API
        {
            public:
                Object decode(const std::string &text);
                std::string encode(Object &root);
                
                int& get(Object &root, const std::string &key, int &o);
                bool& get(Object &root, const std::string &key, bool &o);
                std::string& get(Object &root, const std::string &key, std::string &o);
                long long& get(Object &root, const std::string &key, long long &o);
                Array& get(Object &root, const std::string &key, Array &o);
                Object& get(Object &root, const std::string &key, Object &o);

                void push(Object &root, const std::string &key, int o);
                void push(Object &root, const std::string &key, bool o);
                void push(Object &root, const std::string &key, std::string &o);
                void push(Object &root, const std::string &key, std::string &&o);
                void push(Object &root, const std::string &key, long long o);
                void push(Object &root, const std::string &key, Array &o);
                void push(Object &root, const std::string &key, Array &&o);
                void push(Object &root, const std::string &key, Object &o);
                void push(Object &root, const std::string &key, Object &&o);

                void replace(Object &root, const std::string &key, int o);
                void replace(Object &root, const std::string &key, bool o);
                void replace(Object &root, const std::string &key, std::string &o);
                void replace(Object &root, const std::string &key, std::string &&o);
                void replace(Object &root, const std::string &key, long long o);
                void replace(Object &root, const std::string &key, Array &o);
                void replace(Object &root, const std::string &key, Array &&o);
                void replace(Object &root, const std::string &key, Object &o);
                void replace(Object &root, const std::string &key, Object &&o);

                int& get(Array &root, int i, int &o);
                bool& get(Array &root, int i, bool &o);
                std::string& get(Array &root, int i, std::string &o);
                long long& get(Array &root, int i, long long &o);
                Array& get(Array &root, int i, Array &o);
                Object& get(Array &root, int i, Object &o);

                void push(Array &root, int o);
                void push(Array &root, bool o);
                void push(Array &root, std::string &o);
                void push(Array &root, std::string &&o);  
                void push(Array &root, long long o);
                void push(Array &root, Array &o);
                void push(Array &root, Array &&o);
                void push(Array &root, Object &o);
                void push(Array &root, Object &&o);

                void replace(Array &root, int i, int o);
                void replace(Array &root, int i, bool o);
                void replace(Array &root, int i, std::string &o);
                void replace(Array &root, int i, std::string &&o);
                void replace(Array &root, int i, long long o);
                void replace(Array &root, int i, Array &o);
                void replace(Array &root, int i, Array &&o);
                void replace(Array &root, int i, Object &o);
                void replace(Array &root, int i, Object &&o);
        };

	extern API api;
    }
}

#endif
