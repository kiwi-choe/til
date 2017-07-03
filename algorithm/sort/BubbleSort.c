#include <stdio.h>

void bubbleSort(int dataSet[], int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-(i+1);j++)
		{
			if(dataSet[j] > dataSet[j+1])
			{
				tmp = dataSet[j];
				dataSet[j] = dataSet[j+1];
				dataSet[j+1] = tmp;
			}
		}
	}
}

void bubbleSort_upgradeVer(int dataSet[], int len)
{
	int i =0;
	int j=0;
	int tmp = 0;
	int countOfSortedAlready = 0;

int k =0;
	for(i=0;i<len-1;i++)
	{
		
		if(countOfSortedAlready == len-i)
		{
			printf("number of loop until finishing sort: %d\n", i);
			break;
		}
		
		// Display sorting dataSet
		for(k=0;k<len;k++)
		{
			printf("%d", dataSet[k]);
		}
		printf("\n");

		// init count
		countOfSortedAlready = 0;

		for(j=0;j<len-(i+1);j++)
		{
			if(dataSet[j] > dataSet[j+1])
			{
				tmp = dataSet[j];
				dataSet[j] = dataSet[j+1];
				dataSet[j+1] = tmp;
			}
			else 
			{
				countOfSortedAlready++;
			}			
		}
	}
	
}

int main()
{
	int dataSet[] = {6,4,2,3,1,5};
	int len = sizeof dataSet / sizeof dataSet[0];
	int i = 0;

	// bubbleSort(dataSet, len);
	bubbleSort_upgradeVer(dataSet, len);

	return 0;
}