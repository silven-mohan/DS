/**==== Hashing Implementation: Collision Reducing technique - Linear Probing ====**/


/*
 * This program shows the implementation of the hashing by reducing collision using Linear Probing.
 * This takes SIZE of the hash table, no. of key entries n, and n key values.
 * Inserts all of the key values to the hash table using hash function.
 * Displays the hash table.
*/


/**==== Preprocessing Directives ====**/
#include<stdio.h>       //For Basic I/O functions.
#include<stdlib.h>          //For memory allocation functions like malloc, free.


/**==== Global Declarations ==== **/
int SIZE;


/**==== Function Prototypes ====**/
int hashFunction(int);
int init(int *, int);
int insert(int *, int);
int display(int *);


/**==== Main Function ====**/
int main()
{
    int n, key, i;
    printf("\nEnter the size of the hash table: ");
    scanf("%d", &SIZE);

    printf("\nEnter the total no. of key value entries: ");
    scanf("%d", &n);

    if(SIZE < 1)
    {
        printf("\nNot enough size for the hash table!!\n\n");
        return 1;
    }

    int *hashTable = calloc(SIZE, sizeof(int));
    for(i=0;i<SIZE;i++)
    {
        *(hashTable + i) = -1;
    }

    //Initializing the hash table with the key values:
    if(init(hashTable, n))  return 1;

    //displaying the hash table:
    if(display(hashTable))  return 1;

    //free allocated memory:
    free(hashTable);

    return 0;
}


/**==== Function Definitions  ====**/
//hashFunction():
//Using this hash function index of the hash table for a specific key value is generated.
int hashFunction(int key)
{
    return key % SIZE;
}


//init():
//This function is used to initialize the hash table with the values.
int init(int *hashTable, int n)
{
    int i, key, index, start;

    if(n < 1)
    {
        printf("\nNot enough entries!!\n\n");
        return 1;
    }

    printf("\nEnter the key values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &key);
        index = hashFunction(key);
        start = index;

        while(*(hashTable + index) != -1)
        {
            index = (index + 1) % SIZE;

            if(index == start)
            {
                printf("\nHash Table is Full!!\n\n");
                return 1;
            }
        }
        *(hashTable + index) = key;

    }

    return 0;
}


//display():
//This displays the hash table.
int display(int *hashTable)
{
    int i;

    printf("\n+---------------+");
    printf("\n+\t\t+");

    for(i=0;i<SIZE;i++)
    {
        printf("\n+ Index %d: %d\t+", i, *(hashTable + i));
    }

    printf("\n+\t\t+");
    printf("\n+---------------+\n\n");

    return 0;
}