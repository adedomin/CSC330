#include "BSTree.hpp"
#include <string>
#include <stdio.h>

int main()
{
	BSTree<std::string,int> tree;

	tree.insertKey("hello", 1);
	tree.insertKey("gfh", 167);
	tree.insertKey("fghgfh", 145);
	tree.insertKey("hello234", 1);
	tree.insertKey("hello6547", 1);
	tree.insertKey("hello67", 1);
	tree.insertKey("hellorw", 1);
	tree.insertKey("h5llo", 1);
	tree.insertKey("heyllo", 1);
	tree.insertKey("he6lo", 1);
	tree.insertKey("hely7ujlo", 1);
	tree.insertKey("ello", 1903);
	tree.insertKey("t53hello", 1);
	tree.insertKey("hyllo", 1);
	tree.insertKey("hey6llo", 1);
	tree.insertKey("hel63lo", 1);
	tree.insertKey("t3ello", 2);
	tree.insertKey("herllo", 1);
	tree.insertKey("helo", 1);
	tree.insertKey("helluio57o", 1);
	tree.insertKey("helnjulo", 1);
	tree.insertKey("hehbllo", 1);
	tree.insertKey("another", 56);

	// should be 56
	printf("Value of 'another': %d\n", tree.getValue("another"));
	// should be 1
	printf("Value of 'hehbllo': %d\n", tree.getValue("hehbllo"));
	// should be 1903
	printf("Value of 'ello': %d\n", tree.getValue("ello"));
	// should be 2
	printf("Value of 't3ello': %d\n\n", tree.getValue("t3ello"));

	// should be 23
	// test using
	// should print 23
	// ./executable_name | grep Key: | wc -l
	printf("number of nodes: %d\n\n", tree.getSize());

	// should print tree in order
	// test using
	// ./executable | grep Key: >./output | sort >./output2 && diff output output2
	// shouldn't print anything to terminal if it passes
	tree.printInOrder();
}
