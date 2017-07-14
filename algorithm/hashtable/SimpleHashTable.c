#include "SimpleHashTable.h"

HashTable* createHashTable(int tableSize)
{
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->Table = (Node*)malloc(sizeof(Node)*tableSize);
	ht->TableSize = tableSize;

	return ht;
}

void set(HashTable* ht, KeyType key, ValueType value)
{
	int address = hash(key, ht->TableSize);

	ht->Table[address].Key = key;
	ht->Table[address].Value = value;
}

ValueType get(HashTable* ht, KeyType key)
{
	int address = hash(key, ht->TableSize);
	return ht->Table[address].Value;
}

void destroyHashTable(HashTable* ht)
{
	free(ht->Table);
	free(ht);
}

int hash(KeyType key, int tableSize)
{
	return key % tableSize;
}