#include "string"
#include "iostream"
#include "vector"
#include "ls/json/API.h"
#include "stdio.h"

using namespace std;
using namespace ls::json;

class Member
{
	public:
		Object toJson()
		{
			Object json;
			api.push(json, "name", name);
			api.push(json, "relation", relation);
			return json;
		}
		void parseFrom(Object &json)
		{
			api.get(json, "name", name);
			api.get(json, "relation", relation);
		}
		string name;
		string relation;
};

class Skill
{
	public:
		Object toJson()
		{
			Object json;
			api.push(json, "type", type);
			api.push(json, "level", level);
			return json;
		}
		void parseFrom(Object &json)
		{
			api.get(json, "type", type);
			api.get(json, "level", level);
		}
		string type;
		int level;	
};

class Person
{
	public:
		Object toJson()
		{
			Object json;
			api.push(json, "name", name);
			api.push(json, "age", age);
			api.push(json, "male", male);
			Array _family(family.size());
			for(int i=0;i<family.size();++i)
				api.push(_family, family[i].toJson());
			api.push(json, "family", _family);
			api.push(json, "skill", skill.toJson());
			api.push(json, "fee", fee);
			return json;
		}
		void parseFrom(Object &json)
		{
			Array _family;
			Object item;
			api.get(json, "name", name);
			api.get(json, "age", age);
			api.get(json, "male", male);
			api.get(json, "family", _family);
			api.get(json, "fee", fee);
			
			family.resize(_family.size());
			for(int i=0;i<_family.size();++i)
				family[i].parseFrom(api.get(_family, i, item));
			skill.parseFrom(api.get(json, "skill", item));
		}
		string name;
		int age;
		bool male;
		vector<Member> family;
		Skill skill;
		double fee;
};

int main()
{
/* *
 *	{			
 *		"name" : "xm",
 *		"age" : 22,
 *		"male" : true,
 *		"family" : [
 *			{
 *				"name" : "xh",
 *				"relation" : "mother"
 *			},
 *			{
 *				"name" : "xg",
 *				"relation" : "father"
 *			}
 *		],
 *		"skill":{
 *			"type": "C++",
 *			"level":1
 *		},
 *		"fee" : 100.46
 * 	}
 * */
	Person person;
	person.name = "xm";
	person.age = 22;
	person.male = true;

	Member member;
	member.name = "xh";
	member.relation = "mom";
	person.family.push_back(member);

	member.name = "xg";
	member.relation = "dad";
	person.family.push_back(member);
	
	person.skill.type = "C++";
	person.skill.level = 1;

	person.fee = 100.46;

	auto text = person.toJson().toString();
	cout << "pojo toString text: " << text << endl;

	Object json;

	cout << "empty object: " << json.toString() << endl;

	json = api.decode(text);
	api.replace(json, "age", 23);
	cout << "json parseFrom Text: " << json.toString() << endl;


	Person _person;
	_person.parseFrom(json);
	cout << "pojo parseFrom json: " << _person.toJson().toString() << endl;

	Array a;
	cout << "empty array: " << a.toString() << endl;

	long long llval = -123456879123456789;
	string lltext = LongLong(llval).toString();
	cout << "long long text: "<< lltext << endl;
	LongLong(llval).parseFrom(lltext);
	cout << "long long: " << llval << endl;

	return 0;
}
