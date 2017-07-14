#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct Node
{
	KeyType Key;
	ValueType Value;
} Node;

typedef struct HashTable
{
	int TableSize;
	Node* Table;
} HashTable;

HashTable* createHashTable(int tableSize);

void set(HashTable* ht, KeyType key, ValueType value);
ValueType get(HashTable* ht, KeyType key);

void destroyHashTable(HashTable* ht);
int hash(KeyType key, int tableSize);

#endif