#include <stdio.h>

typedef unsigned long ULONG;

ULONG Power(int base, int exponent)
{
	if(exponent == 1)
		return base;

	if(exponent == 0)
		return 1;

	if(exponent % 2 == 0)
	{
		ULONG newBase = Power(base, exponent/2);
		return newBase*newBase;
	}
	else
	{
		ULONG newBase = Power(base, (exponent-1)/2);
		return (newBase*newBase) * base;
	}
}

int main()
{
	int base = 2;
	int exponent = 30;

	printf("%d^%d = %lu\n", base, exponent, Power(base, exponent));
	return 0;
}