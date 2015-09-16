#include "complex.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	Complex comp1(3, 5);
	Complex comp2(4, 1);

	Complex comp3 = comp1 + comp2;
	Complex comp4 = comp1 - comp2;

	printf("comp1   : ");
	comp1.printVal();
	printf("EXPECTED: 3.000000 + 5.000000i\n");
	printf("comp2   : ");
	comp2.printVal();
	printf("EXPECTED: 4.000000 + 1.000000i\n\n");
	printf("comp1+comp2: ");
	comp3.printVal();
	printf("EXPECTED   : 7.000000 + 6.000000i\n\n");
	printf("comp1-comp2: ");
	comp4.printVal();
	printf("EXPECTED   : -1.000000 + 4.000000i\n");
}
