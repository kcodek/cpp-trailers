#include <iostream>
#include <list>


//ToDo

/* ?????
http://thispointer.com/different-ways-to-initialize-a-list-in-c/
http://thispointer.com/how-to-erase-elements-from-a-list-in-c-using-iterators/
http://thispointer.com/how-to-remove-elements-from-a-list-while-iterating/
http://thispointer.com/how-to-remove-elements-from-a-list-based-on-value/
*/


//http://thispointer.com/stdlist-tutorial-and-usage-details/
// int main()
int main_list_thispointer()
{
	std::list<int> listOfNumbers;

	//Inserting elements at end in list
	listOfNumbers.push_back(5);
	listOfNumbers.push_back(6);

	//Inserting elements at front in list
	listOfNumbers.push_front(2);
	listOfNumbers.push_front(1);

	// Iterating over list elements and display them
	std::list<int>::iterator it = listOfNumbers.begin();
	while (it != listOfNumbers.end())
	{
		std::cout << (*it) << "  ";
		it++;
	}
	std::cout << std::endl;


	//Inserting elements in between insert(pos,elem) member function. 	
	it = listOfNumbers.begin();
	it++;
	it++;
	// Iterator 'it' is at 3rd position.
	listOfNumbers.insert(it, 4);


	// Iterating over list elements and display them
	it = listOfNumbers.begin();
	while (it != listOfNumbers.end())
	{
		std::cout << (*it) << "  ";
		it++;
	}
	std::cout << std::endl;


	//Erasing elements in between the list using erase(position) member function. 
	// Let's iterate to 3rd position
	it = listOfNumbers.begin();
	it++;
	it++;
	// Iterator 'it' is at 3rd position. Now erase this element.
	listOfNumbers.erase(it);

	// Iterating over list elements and display them
	it = listOfNumbers.begin();
	while (it != listOfNumbers.end())
	{
		std::cout << (*it) << "  ";
		it++;
	}
	std::cout << std::endl; //Lets remove all elements with value greater than 3. 
	listOfNumbers.remove_if([](int elem) 
	{ if (elem > 3)
		return true;
	else
		return false;
	});

	it = listOfNumbers.begin();
	while (it != listOfNumbers.end())
	{
		std::cout << (*it) << "  ";
		it++;
	}
	std::cout << std::endl;

	return 0;
}