#include "RBTree.hpp"
#include <string>
#include <stdio.h>

int main()
{
	RBTree<std::string,int> tree;

	tree.insert("hello", 1);
	tree.insert("gfh", 167);
	tree.insert("fghgfh", 145);

	tree.printInOrder();

	printf("\nValue of 'hello': %d\n", tree.getValue("hello"));
	printf("Value of 'another': %d\n", tree.getValue("another"));
	printf("\nValue of 'gfh': %d\n\n", tree.getValue("gfh"));

	tree.insert("hello234", 1);
	tree.insert("hello6547", 1);
	tree.insert("hello67", 1);
	tree.insert("hellorw", 1);
	tree.insert("h5llo", 1);
	tree.insert("heyllo", 1);
	tree.insert("he6lo", 1);
	tree.insert("hely7ujlo", 1);
	tree.insert("ello", 1);
	tree.insert("t53hello", 1);
	tree.insert("hyllo", 1);
	tree.insert("hey6llo", 1);
	tree.insert("hel63lo", 1);
	tree.insert("t3ello", 1);
	tree.insert("herllo", 1);
	tree.insert("helo", 1);
	tree.insert("helluio57o", 1);
	tree.insert("helnjulo", 1);
	tree.insert("hehbllo", 1);
	tree.insert("another", 56);

	tree.printInOrder();

	printf("Value of 'another': %d\n", tree.getValue("another"));
	printf("Value of 'hehbllo': %d\n", tree.getValue("hehbllo"));
	printf("Value of 'ello': %d\n", tree.getValue("ello"));
	printf("Value of 't3ello': %d\n", tree.getValue("t3ello"));
	printf("number of nodes: %d", tree.getSize());
}
