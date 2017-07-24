#include "BruteForce.h"

int bruteForce(char* text, int textSize, int start, char* pattern, int patternSize)
{
	int i = 0;
	int j = 0;

	for(i = start; i <= textSize-patternSize; i++)
	{
		for(j = 0; j < patternSize; j++)
		{
			if(text[i+j] != pattern[j])
				break;
		}
		if(j >= patternSize)
			return i;
	}
	return -1;
}