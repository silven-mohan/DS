/** ==== Dequeues: Implementation  using Linked Lists ==== **/


/** ==== Documentation ==== **/
/*
 * This program shows the implementation the Queue.
 * Takes the data for the n members of the queue.
 * Displays the queue.
 * If the queue is not empty inserts a new element at REAR.
 * And, finally displays the modified queue.
 * If the queue is not empty inserts a new element at FRONT.
 * And, finally displays the modified queue.
 * If the queue is not empty removes the element from the FRONT position.
 * And, finally displays the modified queue.
 * If the queue is not empty removes the element from the REAR position.
 * And, finally displays the modified queue.
*/



/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),....
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ==== Global Declarations ==== **/
/* ---- Node Definition ---- */
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *FRONT = NULL, *REAR = NULL;

/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void createQ(struct node *, int n);
void freeQ(struct node *);
int displayQ(struct node *);
int enqueueREAR(struct node *, int);
int enqueueFRONT(struct node *, int);
int dequeueFRONT(struct node *);
int dequeueREAR(struct node *);



/** ===== Main Function ===== **/
int main()
{
	int n, ITEM;

	//Allocating the memory for the FRONT, REAR pointers:
	FRONT = malloc(sizeof(struct node));
	REAR = malloc(sizeof(struct node));

	if(FRONT == NULL || REAR == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return 1;
	}
	
	printf("\nEnter the total no. of members of the Queue: ");
	scanf("%d", &n);

	//Create and initialize the Queue:
	createQ(FRONT, n);

	//Display the created Queue:
	displayQ(FRONT);

	//Taking the ITEM that is to be inserted:
	printf("\nEnter the ITEM that is to be inserted: ");
	scanf("%d", &ITEM);

	//Enqueue the ITEM:
	if(enqueueREAR(REAR, ITEM))  return 1;

	//Display the modified queue:
	displayQ(FRONT);

	//Taking the ITEM that is to be inserted:
	printf("\nEnter the another ITEM that is to be inserted: ");
	scanf("%d", &ITEM);

	//Enqueue the ITEM:
	if(enqueueFRONT(FRONT, ITEM))  return 1;

	//Display the modified queue:
	displayQ(FRONT);

	//Dequeue the memeber of the queue:
	if(dequeueFRONT(FRONT))  return 1;

	//Display the modified queue:
	displayQ(FRONT);

	//Dequeue the memeber of the queue:
	if(dequeueREAR(REAR))  return 1;

	//Display the modified queue:
	displayQ(FRONT);

	//free the allocated memory:
	freeQ(FRONT);
	free(FRONT);  FRONT = NULL;
	free(REAR);  REAR = NULL;


	return 0;
}


/** ===== Function Definitions ===== **/
//createNode():
//This function allocates memory for a single node.

struct node* createNode(int value)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));

	if(newNode == NULL)
	{
		printf("Memory allocation failed!\n");
		return NULL;
	}

	newNode->data = value;
	newNode->next = NULL;
	newNode -> prev = NULL;

	return newNode;
}


//createQ():
//This function initializes the list with user-provided values.

void createQ(struct node *FRONT, int n)
{
	struct node *temp = NULL, *last = NULL;

	printf("\nEnter the values: ");
	for(int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		struct node *newNode = createNode(val);
		if(newNode == NULL)
		{
			freeQ(FRONT);
			return;
		}

		if(FRONT->next == NULL)
		{
			FRONT->next = newNode;
		}
		else
		{
			last->next = newNode;
			newNode -> prev = last;
		}

		last = newNode;
		temp = newNode;
	}

	if(temp != NULL)
	{
		temp->next = NULL;
	}

	REAR -> next = temp;
}


void freeQ(struct node *FRONT)
{
	struct node *curr = FRONT->next;
	while(curr != NULL)
	{
		struct node *next = curr->next;
		free(curr);
		curr = next;
	}

	FRONT->next = NULL;
}


//displayQ():
//This function displays all of the members and it's data.

int displayQ(struct node *FRONT)
{
	//Checking the edge case:
	if(FRONT -> next == NULL || REAR -> next == NULL)
	{
		printf("\nQueue Underflow!!\n\n");
		return 1;
	}

	struct node *temp = FRONT -> next;

	printf("\n\nThe Queue is: [ FRONT ] -> ");
	//Traversing through every node and printing their data values.
	while(temp != NULL)
	{
		printf("[ %d ] -- ", temp -> data);
		temp = temp -> next;
	}
	printf("\b\b\b<- [ REAR ]");

	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}


//enqueueREAR():
//This function inserts an item at the rear position of the queue.
int enqueueREAR(struct node* REAR, int ITEM)
{
	struct node *new = createNode(ITEM);

	if((REAR -> next == NULL) && (FRONT -> next == NULL))
	{
		FRONT -> next = new;
		REAR -> next = new;
		return 0;
	}

	struct node *temp = REAR -> next;
	temp -> next = new;
	new -> prev = temp;
	REAR -> next = new;

	printf("\nSuccessfully Enqueued a member to the REAR position of the queue.\n\n");
	return 0;
}


//enqueueFRONT():
//This function inserts an item at the front position of the queue.
int enqueueFRONT(struct node* FRONT, int ITEM)
{
	struct node *new = createNode(ITEM);

	if((REAR -> next == NULL) && (FRONT -> next == NULL))
	{
		FRONT -> next = new;
		REAR -> next = new;
		return 0;
	}

	struct node *temp = FRONT -> next;
	new -> next = temp;
	temp -> prev = new;
	FRONT -> next = new;

	printf("\nSuccessfully Enqueued a member to the FRONT position ov the queue.\n\n");
	return 0;
}


//dequeueFRONT():
//This function removes an element from front position of the queue.

int dequeueFRONT(struct node* FRONT)
{
	struct node *last = NULL;

	//Checking the edge case:
	if(FRONT -> next == NULL)
	{
		printf("\nQueue Underflow!!\n\n");
		return 1;
	}

	last = FRONT -> next;
	FRONT -> next = last -> next;
	FRONT -> next -> prev = NULL;

	if(FRONT -> next == NULL)
	{
		REAR -> next = NULL;
	}
	else
	{
		FRONT -> next -> prev = NULL;
	}

	//free the memory of the dequeued element:
	free(last);  last = NULL;

	printf("\nSuccessfully Dequeued a member from the queue.\n\n");
	return 0;
}


//dequeueREAR():
//This function removes an element from rear position of the queue.

int dequeueREAR(struct node* REAR)
{
	struct node *last = NULL;

	//Checking the edge case:
	if(FRONT -> next == NULL)
	{
		printf("\nQueue Underflow!!\n\n");
		return 1;
	}

	last = REAR -> next;
	REAR -> next = last -> prev;

	if(REAR -> next != NULL)
	{
		REAR -> next -> next = NULL;
	}

	if(REAR -> next == NULL)
	{
		FRONT -> next = NULL;
	}

	//free the memory of the dequeued element:
	free(last);  last = NULL;

	printf("\nSuccessfully Dequeued a member from the queue.\n\n");
	return 0;
}