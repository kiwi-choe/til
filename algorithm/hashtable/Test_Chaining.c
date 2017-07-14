#include "Chaining.h"

int main( void )
{
    HashTable* HT = createHashTable( 12289 );

    set( HT, "MSFT",   "Microsoft Corporation");
    set( HT, "JAVA",   "Sun Microsystems");
    set( HT, "REDH",   "Red Hat Linux");
    set( HT, "APAC",   "Apache Org");
    set( HT, "ZYMZZ",  "Unisys Ops Check"); // Collision to APAC
    set( HT, "IBM",    "IBM Ltd.");
    set( HT, "ORCL",   "Oracle Corporation");
    set( HT, "CSCO",   "Cisco Systems, Inc.");
    set( HT, "GOOG",   "Google Inc.");
    set( HT, "YHOO",   "Yahoo! Inc.");
    set( HT, "NOVL",   "Novell, Inc.");

    printf("\n");
    printf("Key:%s, Value:%s\n", "MSFT",   get( HT, "MSFT" ) );
    printf("Key:%s, Value:%s\n", "REDH",   get( HT, "REDH" ) );
    printf("Key:%s, Value:%s\n", "APAC",   get( HT, "APAC" ) );
    printf("Key:%s, Value:%s\n", "ZYMZZ",  get( HT, "ZYMZZ" ) );
    printf("Key:%s, Value:%s\n", "JAVA",   get( HT, "JAVA" ) );
    printf("Key:%s, Value:%s\n", "IBM",    get( HT, "IBM" ) );
    printf("Key:%s, Value:%s\n", "ORCL",   get( HT, "ORCL" ) );
    printf("Key:%s, Value:%s\n", "CSCO",   get( HT, "CSCO" ) );
    printf("Key:%s, Value:%s\n", "GOOG",   get( HT, "GOOG" ) );
    printf("Key:%s, Value:%s\n", "YHOO",   get( HT, "YHOO" ) );
    printf("Key:%s, Value:%s\n", "NOVL",   get( HT, "NOVL" ) );

    destroyHashTable( HT );

    return 0;
}