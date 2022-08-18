#ifndef LS_JSON_LONGLONG_H
#define LS_JSON_LONGLONG_H

#include "ls/Item.h"

namespace ls
{
	namespace json
	{
		class LongLong : public Item
		{
			public:
				LongLong(long long &value);
				std::string toString();
			protected:
				int parse(const std::string &text) override;
				long long &data;
		};	
	}
}

#endif
