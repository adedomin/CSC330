#include <stdio.h>
#include <stddef.h>
#define MIN_INT -2147483648

int Fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n -2);
}

int maxArray(int *a, int size)
{
	if (size < 0)
	{
		return MIN_INT;
	}

	return a[size-1] > maxArray(a, size-1) 
		?  a[size-1] : maxArray(a, size-1); 
}

int main(void)
{
	int a[8]={4,7,3,6,8,1,9,2};
	int result=maxArray(a, 8);
	printf("biggest int: %d\n", result);

	printf("18th number in Fibonacci sequence: %d", Fibonacci(18));

	return 0;
}
