#include "Chaining.h"


HashTable* createHashTable(int tableSize)
{
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->Table = (List*)malloc(sizeof(List)*tableSize);
	memset(ht->Table, 0, sizeof(List)*tableSize);

	ht->TableSize = tableSize;

	return ht;
}

void destroyHashTable(HashTable* ht)
{
	// Remove each liskedList from Heap 
	int i =0;
	for(i=0;i<ht->TableSize;i++)
	{
		List list = ht->Table[i];
		destroyList(list);
	}

	// Remove hashtable from Heap
	free(ht->Table);
	free(ht);
}

Node* createNode(KeyType key, ValueType value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->Key = (char*)malloc(sizeof(char)*(strlen(key)+1));
	strcpy(newNode->Key, key);
	newNode->Value = (char*)malloc(sizeof(char)*(strlen(value)+1));
	strcpy(newNode->Value, value);

	newNode->Next = NULL;

	return newNode;
}

void destroyNode(Node* theNode)
{
	free(theNode->Key);
	free(theNode->Value);
	free(theNode);
}

void set(HashTable* ht, KeyType key, ValueType value)
{
	int address = hash(key, strlen(key), ht->TableSize);
	Node* newNode = createNode(key, value);

	if(ht->Table[address] == NULL)
		ht->Table[address] = newNode;
	else
	{
		List list = ht->Table[address];
		newNode->Next = list;
		ht->Table[address] = newNode;

		printf("Collision occured: Key(%s), Address(%d)\n", key, address);
	}
}

ValueType get(HashTable* ht, KeyType key)
{
	int address = hash(key, strlen(key), ht->TableSize);

	// get linkedList of hashing address
	List theList = ht->Table[address];
	List target = NULL;

	if(theList == NULL)
		return NULL;

	while(1)
	{
		if(strcmp(theList->Key, key) == 0)
		{
			target = theList;
			break;
		}
		if(theList->Next == NULL)
			break;
		else
			theList = theList->Next;
	}
	return target->Value;
}

void destroyList(List list)
{
	if(list == NULL)
		return;
	if(list->Next != NULL)
		destroyList(list->Next);

	destroyNode(list);
}

int hash(KeyType key, int keyLength, int tableSize)
{
	int i =0;
	int hashValue = 0;

	for(i=0;i<keyLength;i++)
	{
		hashValue = (hashValue << 3) + key[i];
	}
	return hashValue % tableSize;
}