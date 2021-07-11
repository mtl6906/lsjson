#ifndef LS_JSON_OBJECT_H
#define LS_JSON_OBJECT_H

#include "ls/CopyableItem.h"
#include "ls/OrderedMap.h"

namespace ls
{
	namespace json
	{
		class Object : public CopyableItem
		{
			public:	
				Object() = default;
				void get(const std::string &text, Item *item);
				void push(const std::string &text, Item *item);
				void replace(const std::string &key, Item *item);
				void clear();
				OrderedMap<std::string, std::string> &getData();
				int copyTo(char *text, int len) override;
				void parseFrom(const std::string &value);
			protected:
				int lengthOfString() override;
				void parse(const std::string &text) override;
				std::string clearWhiteBlank(const std::string &text);
				int countWhiteBlank(const std::string &text);
				OrderedMap<std::string, std::string> om;
		};
	}
}

#endif
