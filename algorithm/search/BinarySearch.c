#include <stdlib.h>
#include <stdio.h>
#include "Score.h"

Score* BinarySearch(Score ScoreList[], int size, double target)
{
	int left, right, mid;

	left = 0;
	right = size-1;

	while(left <= right)
	{
		mid = (left + right)/2;

		if(target == ScoreList[mid].score)
		{
			// return socre value
			return &(ScoreList[mid]);
		}
		else if(target > ScoreList[mid].score)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return NULL;
}

int CompareSocre(const void* _elem1, const void* _elem2)
{
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if(elem1->score > elem2->score)
		return 1;
	else if(elem1->score < elem2->score)
		return -1;
	else
		return 0;
}

int main()
{
	int length = sizeof DataSet / sizeof DataSet[0];
	int i =0;
	Score target;
	Score* found = NULL;

	// Sort by ascending score
	qsort((void*)DataSet, length, sizeof(Score), CompareSocre);

	// Search a student who scored 671.78
	found = BinarySearch(DataSet, length, 671.78);
	printf("found: %d %f \n", found->number, found->score);

	// Search a student who scored 671.78 using by bsearch
	target.number = 0;
	target.score = 671.78;
	found = bsearch(
		(void*)&target,
		(void*)DataSet,
		length,
		sizeof(Score),
		CompareSocre);
	printf("found by bsearch: %d %f \n", found->number, found->score);
	
	return 0;
}