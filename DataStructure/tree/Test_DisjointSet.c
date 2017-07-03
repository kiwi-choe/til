#include "DisjointSet.h"

int main()
{
	int a=1, b=2, c=3, d=4;
	DisjointSet* set1 = makeSet(&a);
	DisjointSet* set2 = makeSet(&b);
	DisjointSet* set3 = makeSet(&c);
	DisjointSet* set4 = makeSet(&d);

	printf("set1 == set2: %d\n", findSet(set1) == findSet(set2));

	unionSet(set1, set3);
	printf("set1 === set3: %d\n", findSet(set1) == findSet(set3));
	unionSet(set2, set4);
	printf("set2 === set4: %d\n", findSet(set2) == findSet(set4));

	return 0;
}