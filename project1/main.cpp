#include "ADTbag.h"
#include<string>
#include<iostream>
using namespace std;

void displayBag(ArrayBag<string>& bag)
{
	cout << "The bag contains "<< bag.getCurrentSize() << " items:\n";
	vector<string> bagItems=bag.toVector();
	int numberOfEntries=(int)bagItems.size();
	for (int i=0; i<numberOfEntries; i++)
	{
		cout <<bagItems[i] << " ";
	}
	cout << endl;
}


int main()
{
	ArrayBag<string> bag;
	cout << "Testing the array-based bag:" <<endl;
	if (bag.isEmpty())
		cout << "The initial bag is empty.\n";
	displayBag(bag);

	string items[]={"one", "two", "three", "four", "five", "one", "two"};
	cout << "Add 7 items to the bag:" <<endl;
	for (int i=0; i<7; i++)
	{
		bag.add(items[i]);
	}
	displayBag(bag);
	cout << "The string \"one\" occurs " << bag.getFrequencyOf("one") << " times.\n";
	cout << "The string \"two\" occurs " << bag.getFrequencyOf("two") << " times.\n";
	cout << "The string \"three\" occurs " << bag.getFrequencyOf("three") << " time.\n";
	cout << "The string \"seven\" occurs " << bag.getFrequencyOf("seven") << " time.\n";
	cout<< "Remove string \"one\" ...\n";
	bag.remove("one");
	displayBag(bag);
	cout<< "Remove string \"two\" ...\n";
	bag.remove("two");
	displayBag(bag);
	if (bag.contains("three"))
		cout << "The bag contains the string \"three\".\n";
	else 
		cout << "The bag does NOT contain the string three.\n";

	if (bag.contains("seven"))
		cout << "The bag contains the string \"seven\".\n";
	else 
		cout << "The bag does NOT contain the string \"seven\".\n";

	cout << "Delete all items fron the bag. \n";
	bag.clear();

	displayBag(bag);


}
