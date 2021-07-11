#ifndef LS_JSON_INT_H
#define LS_JSON_INT_H

#include "ls/Item.h"

namespace ls
{
	namespace json
	{
		class Int : public Item
		{
			public:	
				Int(int &value);
				std::string toString() override;
			protected:
				void parse(const std::string &text) override;
				int &data;
		};
	}
}

#endif
