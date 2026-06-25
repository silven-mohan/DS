/** ==== Queues: Implementation of Enqueue using Arrays ==== **/


/** ==== Documentation ==== **/
/*
 * This program shows the implementation of enqueue operation on the Queue.
 * This takes the size of the queue MAX from the user and creates it.
 * Takes the data for the n members of the queue.
 * Displays the queue.
 * If the queue is not empty inserts a new element.
 * And, finally displays the modified queue.
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>       //For Basic I/O functions.


/** ==== Function Prototypes ==== **/
int createQ(int *, int);
int enqueue(int *, int);
int displayQ(int *);


/** ==== Global Declarations ==== **/
#define MAX 100
int FRONT = -1, REAR = -1;


/** ==== Main Function ====**/
int main()
{
    int n, Q[MAX], ITEM;

    printf("\nEnter the size of the Queue: ");
    scanf("%d", &n);

    //Creating Queue:
    if(createQ(&Q[0], n))  return 1;

    //Displaying the Queue:
    if(displayQ(&Q[0]))  return 1;

    //Taking the ITEM to insert:
    printf("\nEnter the ITEM: ");
    scanf("%d", &ITEM);

    //EnQueue the ITEM:
    if(enqueue(&Q[0], ITEM))  return 1;

    //Display the modified Queue:
    if(displayQ(&Q[0]))  return 1;

    return 0;
}


/** ==== Function Definitions ====**/
//createQ():
//This function takes the array queue and initializes with n values.

int createQ(int *Q, int n)
{
    int i;
    if((FRONT == -1) && (REAR == -1))
    {
        FRONT = REAR = 0;
    }
    if(REAR == MAX-1)
    {
        printf("\nQueue Overflow!\n\n");
        return 1;
    }

    printf("\nEnter the %d values: ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", (Q+i));
    }

    FRONT = 0;
    REAR = n-1;

    printf("\nSuccessfully created the Queue.\n\n");

    return 0;
}


//enqueue():
//This function inserts the given element to the REAR position of the Queue.

int enqueue(int *Q, int ITEM)
{
    if(REAR == MAX - 1)
    {
        printf("\nQueue Overflow!!\n\n");
        return 1;
    }
    if((FRONT == -1) && (REAR == -1))
    {
        FRONT = REAR = 0;
        Q[REAR] = ITEM;
    }
    else
    {
        Q[++REAR] = ITEM;
    }
    
    printf("\nSuccessfully Enqueued the ITEM to the Queue.\n\n");
    return 0;
}


//displayQ():
//This function displays the all members of the Queue.

int displayQ(int *Q)
{
    int i;

    if((FRONT == -1) && (REAR == -1))
    {
        printf("\nQueue Underflow!\n\n");
        return 1;
    }

    printf("\nThe Queue is: ");
    printf("[ FRONT ] -> ");
    for(i=FRONT;i<=REAR;i++)
    {
        printf("[ %d ] -- ", *(Q + i));
    }
    printf("\b\b\b<- [ REAR ]\n\n");

    return 0;
}