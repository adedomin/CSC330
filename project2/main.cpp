#include "LinkedBag.h"
#include<string>
#include<iostream>
using namespace std;


void displayBag(LinkedBag<string>& bag)
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


void main()
{
	LinkedBag<string> firstBag;
	cout << "Testing the link-based bag:" <<endl;
	if (firstBag.isEmpty())
		cout << "The initial bag (first bag) is empty.\n";
	displayBag(firstBag);

	string items[]={"one", "two", "three", "four", "five", "one", "two"};
	cout << "Add 7 items to the first bag:" <<endl;
	for (int i=0; i<7; i++)
	{
		firstBag.add(items[i]);
	}
	int value=firstBag.getFrequencyOf("one");
	displayBag(firstBag);
	cout << "The string \"one\" occurs " << firstBag.getFrequencyOf("one") << " times.\n";
	cout << "The string \"two\" occurs " << firstBag.getFrequencyOf("two") << " times.\n";
	cout << "The string \"three\" occurs " << firstBag.getFrequencyOf("three") << " time.\n";
	cout << "The string \"seven\" occurs " << firstBag.getFrequencyOf("seven") << " time.\n";
	LinkedBag<string> secondBag(firstBag);
	cout<< "Remove string \"one\" ...\n";
	secondBag.remove("one");
	displayBag(secondBag);
	cout<< "Remove string \"two\" ...\n";
	secondBag.remove("two");
	displayBag(secondBag);
	cout<< "Remove string \"four\" ...\n";
	secondBag.remove("four");
	displayBag(secondBag);
	if (secondBag.contains("three"))
		cout << "The second bag contains the string \"three\".\n";
	else 
		cout << "The second bag does NOT contain the string \"three\".\n";

	if (secondBag.contains("seven"))
		cout << "The second bag contains the string \"seven\".\n";
	else 
		cout << "The second bag does NOT contain the string \"seven\".\n";

	cout << "Delete all items from the second bag. \n";
	secondBag.clear();


	displayBag(secondBag);


}