#ifndef LS_JSON_BOOL_H
#define LS_JSON_BOOL_H

#include "ls/Item.h"

namespace ls 
{
	namespace json 
	{
		class Bool : public Item
		{
			public:
				Bool(bool &value);
				std::string toString() override;
			protected:
				int parse(const std::string &value) override;
				bool &data;
		};
	}
}

#endif
