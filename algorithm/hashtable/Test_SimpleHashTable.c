#include "SimpleHashTable.h"

int main()
{
	HashTable* ht = createHashTable(193);

	set(ht, 418, 32114);
	set(ht, 9, 514);
	set(ht, 27, 8917);
	set(ht, 1031, 286);

	printf("Key: %d, Value: %d\n", 418, get(ht, 418));
	printf("Key: %d, Value: %d\n", 9, get(ht, 9));
	printf("Key: %d, Value: %d\n", 27, get(ht, 27));
	printf("Key: %d, Value: %d\n", 1031, get(ht, 1031));

	destroyHashTable(ht);

	return 0;
}