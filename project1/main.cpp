#include "ADTbag.hpp"
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ArrayBag<string> bag;
	cout << "Testing the array-based bag:" <<endl;
	if (bag.isEmpty())
		cout << "The initial bag is empty.\n";
	bag.printBag();

	string items[]={"one", "two", "three", "four", "five", "one", "two"};
	cout << "Add 7 items to the bag:" <<endl;
	for (int i=0; i<7; i++)
	{
		bag.addItem(items[i]);
	}
	bag.printBag();
	cout << "The string \"one\" occurs " << bag.getFrequencyOf("one") << " times.\n";
	cout << "The string \"two\" occurs " << bag.getFrequencyOf("two") << " times.\n";
	cout << "The string \"three\" occurs " << bag.getFrequencyOf("three") << " time.\n";
	cout << "The string \"seven\" occurs " << bag.getFrequencyOf("seven") << " time.\n";
	cout<< "Remove string \"one\" ...\n";
	bag.removeItem("one");
	bag.printBag();
	cout<< "Remove string \"two\" ...\n";
	bag.removeItem("two");
	bag.printBag();
	if (bag.contains("three"))
		cout << "The bag contains the string \"three\".\n";
	else 
		cout << "The bag does NOT contain the string three.\n";

	if (bag.contains("seven"))
		cout << "The bag contains the string \"seven\".\n";
	else 
		cout << "The bag does NOT contain the string \"seven\".\n";

	cout << "add two to the bag twice\n";
	bag.addItem("two");
	bag.addItem("two");
	cout << "get vector of bag contents and print them\n";
	std::vector<std::string> vectorOfBag = bag.toVector();
	typename std::vector<std::string>::iterator i = vectorOfBag.begin();
	for (;i != vectorOfBag.end(); ++i)
	{
		std::cout << *i << "\n";
	}
	cout << "Delete all items from the bag. \n";
	bag.clear();

	bag.printBag();
}
