#ifndef KARPRABIN_H
#define KARPRABIN_H

int karpRabin(char* text, int textSize, int start, char* pattern, int patternSize);

int hash(char* string, int size);
int reHash(char* string, int start, int size, int hashPrev, int coefficient);

#endif