#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif

#ifndef LIST
#define LIST
#include <list>
#endif


#ifndef FORWARD_LIST
#define FORWARD_LIST
#include<forward_list>
#endif


//Recipe 7-3. Storing a Set of Elements that Is Constantly Altered

//Listing 7 - 11.  Using a forward_list
/*
A forward_list does not contain the methods emplace or emplace_back. It does contain emplace_front and also emplace_after
which allow you to add elements to the beginning of the forward_list or after a specific position in the forward_list.
*/

int mainForwardList(int argv, char* argc[])
{
	std::forward_list<int32_t> myList{ 1, 2, 3, 4, 5 };

	myList.emplace_front(6);

	auto forwardIter = myList.begin();
	++forwardIter;
	++forwardIter;
	myList.emplace_after(forwardIter, 9);

	for (auto&& number : myList)
	{
		std::cout << number << " ";
	}

	return 0;
}
//Listing 7 - 10.  Using a list
int main_ListEmplace() 
{
	std::list<int32_t> myList{ 1, 2, 3, 4, 5 };

	myList.emplace_front(6);
	myList.emplace_back(7);

	auto forwardIter = myList.begin();
	++forwardIter;//there's no + offset Index for list
	++forwardIter;
	myList.emplace(forwardIter, 9);

	auto reverseIter = myList.end();
	--reverseIter;
	--reverseIter;
	--reverseIter;
	myList.emplace(reverseIter, 8);

	for (auto&& number : myList)
	{
		std::cout << number << " ";
	}

	return 0;
}