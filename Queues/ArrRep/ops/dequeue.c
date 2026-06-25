/** ==== Queues: Implementation of Dequeue using Arrays ==== **/


/** ==== Documentation ==== **/
/*
 * This program shows the implementation of dequeue operation on the Queue.
 * This takes the size of the queue MAX from the user and creates it.
 * Takes the data for the n members of the queue.
 * Displays the queue.
 * If the queue is not empty removes the element from the FRONT position.
 * And, finally displays the modified queue.
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>       //For Basic I/O functions.


/** ==== Function Prototypes ==== **/
int createQ(int *, int);
int dequeue(int *);
int displayQ(int *);


/** ==== Global Declarations ==== **/
#define MAX 100
int FRONT = -1, REAR = -1;


/** ==== Main Function ====**/
int main()
{
    int n, Q[MAX];

    printf("\nEnter the size of the Queue: ");
    scanf("%d", &n);

    //Creating Queue:
    if(createQ(&Q[0], n))  return 1;

    //Displaying the Queue:
    if(displayQ(&Q[0]))  return 1;

    //DeQueue the ITEM:
    if(dequeue(&Q[0]))  return 1;

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


//dequeue():
//This function removes an element from the FRONT position of the Queue.

int dequeue(int *Q)
{
    if((FRONT == -1) && (REAR == -1))
    {
        printf("\nQueue Underflow!!\n\n");
        return 1;
    }
    
    if(FRONT == REAR)
    {
        FRONT = REAR = -1;
    }
    else
    {
        FRONT++;
    }

    printf("\nSuccessfully Dequeued from the Queue.\n\n");
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