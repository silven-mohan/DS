/** ==== Circular Queues: Implementation of Dequeue using Linked Lists ==== **/


/** ==== Documentation ==== **/
/*
 * This program shows the implementation of dequeue operation on the Circular Queue.
 * Takes the data for the n members of the queue.
 * Displays the queue.
 * If the queue is not empty inserts a new element.
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
};

struct node *FRONT = NULL, *REAR = NULL;

/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void createCQ(struct node *, int n);
void freeCQ(struct node *);
int displayCQ(struct node *);
int dequeue(struct node *);



/** ===== Main Function ===== **/
int main()
{
	int n;

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
	createCQ(FRONT, n);

	//Display the created Queue:
	displayCQ(FRONT);

	//Dequeue :
	if(dequeue(FRONT))  return 1;

	//Display the modified queue:
	displayCQ(FRONT);

	//free the allocated memory:
	freeCQ(FRONT);
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

	return newNode;
}


//createCQ():
//This function initializes the list with user-provided values.

void createCQ(struct node *FRONT, int n)
{
	struct node *temp, *last = NULL;

	printf("\nEnter the values: ");
	for(int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		struct node *newNode = createNode(val);
		if(newNode == NULL)
		{
			freeCQ(FRONT);
			return;
		}

		if(FRONT->next == NULL)
		{
			FRONT->next = newNode;
		}
		else
		{
			last->next = newNode;
		}

		last = newNode;
		temp = newNode;
	}

	if(temp != NULL)
	{
		temp->next = FRONT -> next;
	}

	REAR -> next = temp;
}


void freeCQ(struct node *FRONT)
{
	struct node *curr = FRONT->next;
	do
	{
		struct node *next = curr->next;
		free(curr);
		curr = next;
	}while(curr != FRONT -> next);

	FRONT->next = NULL;
}


//displayCQ():
//This function displays all of the members and it's data.

int displayCQ(struct node *FRONT)
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
	do
	{
		printf("[ %d ] -- ", temp -> data);
		temp = temp -> next;
	}while(temp != FRONT -> next);
	printf("\b\b\b\b\b)=> [ FIRST ] ] <- [ REAR ]");

	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}


//dequeue():
//This function removes an element from front position of the queue.
int dequeue(struct node* FRONT)
{
	struct node *last = NULL;

	//Checking the edge case:
	if(FRONT -> next == NULL)
	{
		printf("\nQueue Underflow!!\n\n");
		return 1;
	}

	last = FRONT -> next;

	if(last -> next != last)
	{
		FRONT -> next = last -> next;
	}
	else
	{
		FRONT -> next = NULL;
	}

	if(FRONT -> next == NULL)
	{
		REAR -> next = NULL;
	}
	else
	{
		//Change the circular link to the last node after the deletion:
		struct node *temp = FRONT -> next;
		while(temp -> next != last)
		{
			temp = temp -> next;
		}
		temp -> next = FRONT -> next;
	}

	//free the memory of the dequeued element:
	free(last);  last = NULL;

	printf("\nSuccessfully Dequeued a member from the queue.\n\n");
	return 0;
}