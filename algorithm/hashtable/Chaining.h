#ifndef CHANING_H
#define CHANING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct Node
{
	KeyType Key;
	ValueType Value;
	struct Node* Next;
} Node;

typedef Node* List;

typedef struct HashTable
{
	int TableSize;
	List* Table;
} HashTable;

HashTable* createHashTable(int tableSize);
void destroyHashTable(HashTable* ht);
void destroyList(List list);

Node* createNode(KeyType key, ValueType value);
void destroyNode(Node* theNode);

void set(HashTable* ht, KeyType key, ValueType value);
ValueType get(HashTable* ht, KeyType key);
int hash(KeyType key, int keyLength, int tableSize);

#endif