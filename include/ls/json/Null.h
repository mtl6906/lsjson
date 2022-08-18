#ifndef LS_JSON_NULL_H
#define LS_JSON_NULL_H

#include "ls/Item.h"

namespace ls
{
	namespace json
	{
		class Null : public Item
		{
			public:	
				Null() = default;
				std::string toString() override;
			protected:
				int parse(const std::string &text) override;
		};
	}
}

#endif
