#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

ULONG fibonacci(int N)
{
	int i;
	ULONG result;
	ULONG* fibonacciTable;

	if( N==0 && N==1 )
	{
		return N;
	}

	fibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N+1));

	fibonacciTable[0] = 0;
	fibonacciTable[1] = 1;

	// Recursive call -> loop
	for(i=2; i<=N; i++)
	{
		fibonacciTable[i] = fibonacciTable[i-1] + fibonacciTable[i-2];
	}
	result = fibonacciTable[N];

	free(fibonacciTable);

	return result;
}

int main()
{
	int N = 46;
	ULONG result = fibonacci(N);
	printf("Fibonacci(%d) = %lu\n", N, result);

	return 0;
}