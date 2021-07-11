#ifndef LS_JSON_ARRAY_H
#define LS_JSON_ARRAY_H

#include "ls/CopyableItem.h"
#include "vector"

namespace ls
{
	namespace json
	{
		class Array : public CopyableItem
		{
			public:
				Array(int n = 0);
				void push(Item *item);
				void get(int i, Item *item);
				void replace(int i, Item *item);
				int size();
				int copyTo(char *text, int len) override;
			protected:
				int lengthOfString() override;
				void parse(const std::string &text) override;
				std::vector<std::string> data;
		};
	}
}

#endif
