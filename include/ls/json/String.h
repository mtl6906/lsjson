#ifndef LS_JSON_STRING_H
#define LS_JSON_STRING_H

#include "ls/Item.h"

namespace ls
{
	namespace json
	{
		class String : public Item
		{
			public:
				String(std::string &data);
				std::string toString();
			protected:
				void parse(const std::string &text) override;
				std::string &data;
		};
	}
}

#endif
