#ifndef LS_JSON_DOUBLE_H
#define LS_JSON_DOUBLE_H

#include "ls/Item.h"

namespace ls
{
	namespace json
	{
		class Double : public Item
		{
			public:	
				Double(double &value);
				std::string toString() override;
			protected:
				void parse(const std::string &text) override;
				double &data;
		};
	}
}

#endif
