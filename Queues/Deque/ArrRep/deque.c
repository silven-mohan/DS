/** ==== Dequeues: Implementation using Arrays ==== **/

/** ==== Documentation ==== **/
/*
 * This program shows the implementation of the Deque.
 * This takes the size of the queue MAX from the user and creates it.
 * Takes the data for the n members of the queue.
 * Displays the queue.
 * If the queue is not empty inserts a new element at the REAR position.
 * And, finally displays the modified queue.
 * And, inserts another element at the FRONT position and displays the queue.
 * If the queue is not empty removes an element from the FRONT position.
 * And, finally displays the modified queue.
 * And, removes another element from the REAR position and displays the queue.
 */


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>       //For Basic I/O functions.


/** ==== Function Prototypes ==== **/
int createQ(int *, int);
int enqueueREAR(int *, int);
int enqueueFRONT(int *, int);
int dequeueREAR(int *);
int dequeueFRONT(int *);
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

    if(n <= 0 || n > MAX)
    {
        printf("\nInvalid Queue Size!\n\n");
        return 1;
    }

    //Creating Queue:
    if(createQ(&Q[0], n))  return 1;

    //Displaying the Queue:
    if(displayQ(&Q[0]))  return 1;

    //Taking the ITEM to insert:
    printf("\nEnter the ITEM: ");
    scanf("%d", &ITEM);

    //EnQueue the ITEM at REAR:
    if(enqueueREAR(&Q[0], ITEM))  return 1;

    //Display the modified Queue:
    if(displayQ(&Q[0]))  return 1;

    //Taking the ITEM to insert:
    printf("\nEnter the new ITEM: ");
    scanf("%d", &ITEM);

    //EnQueue the ITEM at FRONT:
    if(enqueueFRONT(&Q[0], ITEM))  return 1;

    //Display the modified Queue:
    if(displayQ(&Q[0]))  return 1;

    //Dequeue an element from REAR:
    if(dequeueREAR(&Q[0]))  return 1;

    //Display the modified Queue:
    if(displayQ(&Q[0]))  return 1;

    //Dequeue the element from FRONT:
    if(dequeueFRONT(&Q[0]))  return 1;

    //Display the modified Queue:
    if(displayQ(&Q[0]))  return 1;

    return 0;
}


/** ==== Function Definitions ==== **/

//createQ():
//This function takes the array queue and initializes with n values.

int createQ(int *Q, int n)
{
    int i;

    printf("\nEnter the %d values: ", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", (Q + i));
    }

    FRONT = 0;
    REAR = n - 1;

    printf("\nSuccessfully created the Queue.\n\n");

    return 0;
}


//enqueueREAR():
//This function inserts the given element to the REAR position of the Queue.

int enqueueREAR(int *Q, int ITEM)
{
    // Queue Full Condition
    if((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1))
    {
        printf("\nQueue Overflow!!\n\n");
        return 1;
    }

    // Empty Queue
    if((FRONT == -1) && (REAR == -1))
    {
        FRONT = REAR = 0;
    }
    else if(REAR == MAX - 1)
    {
        REAR = 0;
    }
    else
    {
        REAR++;
    }

    Q[REAR] = ITEM;

    printf("\nSuccessfully Enqueued the ITEM to the REAR.\n\n");

    return 0;
}


//enqueueFRONT():
//This function inserts the given element to the FRONT position of the Queue.

int enqueueFRONT(int *Q, int ITEM)
{
    // Queue Full Condition
    if((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1))
    {
        printf("\nQueue Overflow!!\n\n");
        return 1;
    }

    // Empty Queue
    if((FRONT == -1) && (REAR == -1))
    {
        FRONT = REAR = 0;
    }
    else if(FRONT == 0)
    {
        FRONT = MAX - 1;
    }
    else
    {
        FRONT--;
    }

    Q[FRONT] = ITEM;

    printf("\nSuccessfully Enqueued the ITEM to the FRONT.\n\n");

    return 0;
}


//dequeueFRONT():
//This function removes an element from the FRONT position of the Queue.

int dequeueFRONT(int *Q)
{
    // Empty Queue
    if((FRONT == -1) && (REAR == -1))
    {
        printf("\nQueue Underflow!!\n\n");
        return 1;
    }

    if(FRONT == REAR)
    {
        FRONT = REAR = -1;
    }
    else if(FRONT > REAR)
    {
        FRONT = 0;
    }
    else
    {
        FRONT++;
    }

    printf("\nSuccessfully Dequeued an element from the FRONT.\n\n");

    return 0;
}


//dequeueREAR():
//This function removes an element from the REAR position of the Queue.

int dequeueREAR(int *Q)
{
    // Empty Queue
    if((FRONT == -1) && (REAR == -1))
    {
        printf("\nQueue Underflow!!\n\n");
        return 1;
    }

    if(FRONT == REAR)
    {
        FRONT = REAR = -1;
    }
    else if(REAR == 0)
    {
        REAR = MAX - 1;
    }
    else
    {
        REAR--;
    }

    printf("\nSuccessfully Dequeued an element from the REARcl.\n\n");

    return 0;
}


//displayQ():
//This function displays all members of the Queue.

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

    i = FRONT;

    while(i != REAR)
    {
        printf("[ %d ] -- ", Q[i]);
        i = (i + 1) % MAX;
    }

    printf("[ %d ] <- [ REAR ]\n\n", Q[REAR]);

    return 0;
}