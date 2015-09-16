#include "complex.h"

int main(int argc, char **argv)
{
	Complex comp1(3, 5);
	Complex comp2(4, 1);

	Complex comp3 = comp1 + comp2;

	comp1.printVal();
	comp2.printVal();
	comp3.printVal();
}
