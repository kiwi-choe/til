#include "BruteForce.h"
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 512

int main(int argc, char** argv)
{
	char* filePath;
	FILE* fp;

	char text[MAX_BUFFER];
	char* pattern;
	int patternSize = 0;
	int line = 0;

	if(argc < 3)
	{
		printf("Usage: %s <FilePath> <Pattern>\n", argv[0]);
		return 1;
	}

	filePath = argv[1];
	pattern = argv[2];

	patternSize = strlen(pattern);

	if((fp = fopen(filePath, "r")) == NULL)
	{
		printf("Cannot open file: %s\n", filePath);
		return 1;
	}

	while(fgets(text, MAX_BUFFER, fp) != NULL)
	{
		int position = bruteForce(text, strlen(text), 0, pattern, patternSize);

		if(position >= 0)
			printf("line: %d, column: %d - %s", line++, position, text);
	}
	fclose(fp);

	return 0;
}