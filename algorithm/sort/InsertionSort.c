#include <stdio.h>
#include <string.h>

void displayDataSet(int dataSet[], int length)
{
	int i =0;
	for(i=0;i<length;i++)
	{
		printf("%d ", dataSet[i]);
	}
	printf("\n");
}

void insertionSort(int dataSet[], int len)
{
	int i =0;
	int j= 0;
	int value = 0;

	for(i=1;i<len;i++)
	{
		displayDataSet(dataSet, len);
]
		if(dataSet[i-1] > dataSet[i])
		{
			value = dataSet[i];
			for(j=0;j<i; j++)
			{
				if(dataSet[j] > value)
				{
					/*
					* memmove(void* des, void* src, size_t size)
					*/
					memmove(&dataSet[j+1], &dataSet[j], sizeof(dataSet[0]) * (i-j));
					dataSet[j] = value;
					break;
				}
			}
		}
	}
}

int main()
{
	int dataSet[] = {5,1,6,4,2,3};
	int length = sizeof dataSet / sizeof dataSet[0];

	insertionSort(dataSet, length);

	return 0;
}