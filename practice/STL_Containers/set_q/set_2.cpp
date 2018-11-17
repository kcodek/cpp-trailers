#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif

#ifndef SET
#define SET
#include<set>
#endif


#ifndef STRING
#define STRING
#include <string>
#endif

//Listing 7 - 14
class SetObject {
private:
	int32_t m_Key{};
	std::string m_Name;
public:
	SetObject(int32_t key, const std::string& name):m_Key(key), m_Name(name) {}
	//SetObject(int32_t key) :m_Key(key), m_Name("") {}
	SetObject(int32_t key) :SetObject(key, "") {};

	const std::string& GetName() const {return m_Name;}

	int32_t GetKey() const { return m_Key; }

	bool operator<(const SetObject& other)const {
		return m_Key < other.m_Key;
	}

	bool operator>(const SetObject& other)const {
		return m_Key > other.m_Key;
	}
};

int main_SetObject() 
{
	std::set<SetObject> mySet{//default is similar to set<SetObject, less<SetObject>>
		{ 6, "Six" },
		{ 3, "Three" },
		{ 4, "Four" },
		{ 1, "One" },
		{ 2, "Two" }
	};
	
	/*set<SetObject>::iterator iter;
	for (iter = mySet.begin(); iter != mySet.end(); iter++) {
		cout << iter->GetName()<<endl;
	}*/
	std::cout << "Default - low to high: " << std::endl;
	for (auto&& number : mySet) {
		std::cout << number.GetName() << std::endl;
	}

	auto iter = mySet.find(3);
	if (iter != mySet.end())
	{
		std::cout << "Found: " << iter->GetName() << std::endl;
	}

	std::set<SetObject, std::greater<SetObject>> mySet2{
		{ 6, "Six" },
		{ 3, "Three" },
		{ 4, "Four" },
		{ 1, "One" },
		{ 2, "Two" }
	};

	std::cout<<std::endl << "high to low using greater<>: " << std::endl;
	for (auto&& number : mySet2) {
		std::cout << number.GetName() << std::endl;
	}
	mySet2.emplace(SetObject(5, "Five"));
	std::cout << "\nemplace 5" << std::endl;
	for (auto&& number : mySet2) {
		std::cout << number.GetName() << std::endl;
	}
	return 0;
}
