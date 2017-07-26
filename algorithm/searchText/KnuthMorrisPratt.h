#ifndef KNUTHMORRISPRATT_H
#define KNUTHMORRISPRATT_H

#include <stdio.h>

int knuthMorrisPratt(char* text, int textSize, int start, 
						char* pattern, int patternSize);
void preprocess(char* pattern, int patternSize, int* border);

#endif