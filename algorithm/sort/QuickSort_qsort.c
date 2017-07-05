#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compareScore(const void* _elem1, const void* _elem2)
{
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;
	if(*elem1 > *elem2)
	{
		return 1;
	}
	else if(*elem1 < *elem2)
	{
		return -1;
	}
	else
		return 0;
}

int main()
{
	int dataSet[] = {6,4,2,3,1,5};
	int length = sizeof dataSet / sizeof dataSet[0];
	int i =0;

	qsort((void*) dataSet, length, sizeof(int), compareScore);

	for(i=0;i<length;i++)
	{
		printf("%d ", dataSet[i]);
	}
	printf("\n");
	
	return 0;
}