#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif

#ifndef MAP
#define MAP
#include<map>
#endif


#ifndef VECTOR
#define VECTOR
#include<vector>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif


using std::make_pair;
using std::string;
using std::pair;
using std::ifstream;

//http://www.bogotobogo.com/cplusplus/stl2_map.php

/*
//map class template looks like this: 
//STP map implementations are more like a balanced binary search trees (BST). To be more specific, they are red-black trees.

std::map<Key, Data, Compare, Alloc>

namespace std {
template <class Key, class T,
	class Compare = less<Key>,
	class Allocator = allocator<pair<const Key, T> > >
	class map;
*/

//ToDo
//Multimap example - Anagrams from a dictionary
//Maps for Word Count



//read in the data to a map
int read_words(std::vector<std::string> & words, std::ifstream & in) {
	int i = 0;
	while (!in.eof()) {
		in >> words[i++];
	}
	/*return i- 1;*/
	return i;
}

int mainReadFromIfStream() {

	std::ifstream ifp("names.txt");
	std::vector<std::string> w(500);
	int number_of_words = read_words(w, ifp);
	w.resize(number_of_words);

	for (auto it : w)
		std::cout << it << " ";
	std::cout << std::endl;

	std::map<std::string, std::string> wMap;

	for (int i = 0; i < number_of_words;) {
		wMap.insert(std::pair<std::string, std::string>(w[i], w[i + 1]));
		i += 2;
	}

	std::cout << "\nwMap.size()=" << wMap.size() << std::endl;
	std::cout << std::endl;
	for (auto it = wMap.begin(); it != wMap.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;

	return 0;

}

int main()
// int mainMapInitialization() 
{
	typedef std::map<std::string, int> mapType;
	mapType populationMap;

	populationMap.insert(pair<std::string, int>("China", 1939));
	populationMap.insert(pair<std::string, int>("India", 1187));
	
	//To avoid implicit type conversion, pass the correct type explicitly by using value_type
	populationMap.insert(mapType::value_type("US", 310));	
	populationMap.insert(mapType::value_type("Indonesia", 234));
	
	populationMap.insert(make_pair("Brasil", 193));
	populationMap.insert(make_pair("Pakistan", 170));

	// Erase the end element using the erase function
	// Because it's ordered map (by key), map elements are not in the order of the entry 
	mapType::iterator iter = --populationMap.end();
	populationMap.erase(iter);// In this map it's US since it's ordered alphabetically (default??)

	// output the size of the map
	std::cout << "Size of populationMap: " << populationMap.size() << '\n';

	for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
		std::cout << iter->first << ": "
			<< iter->second << " million\n";
	}

	// find will return an iterator to the matching element if it is found
	// or to the end of the map if the key is not found
	std::string country("Indonesia");
	iter = populationMap.find(country);
	
	if (iter != populationMap.end())
		std::cout << country << "'s populations is " << iter->second << " million\n";
	else
		std::cout << "Key is not in populationMap" << '\n';

	//insert and update[] in a map - using map::insert for adding and map::operator[] for updates is recommended.
	populationMap["Indonesia"] = 244;//update
	std::cout << country << "'s populations is " << populationMap["Indonesia"] << " million after update[]\n";

	// clear the entries in the map
	populationMap.clear();


	return 0;
}