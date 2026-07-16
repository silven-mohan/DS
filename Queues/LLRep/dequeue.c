/** ==== Queues: DeQueue Implementation ==== **/


/** ==== Documentation ==== **/
/*
 * This program creates a new queue and initializes it with some values which is represented using queues.
 * Then, deletes an item from the queue.
 * And, finally prints all of the elements in the queue.
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free(),..


/** ==== Global Declarations ==== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};


/** ==== Function Prototypes: ==== **/
struct node* createNode(int );
int createList(struct node*, struct node*);
int display(struct node *);
void freeList(struct node *);
int DeQueue(struct node *, struct node *);


/** ==== Main Function ==== **/
int main()
{
	//Declaring required variables:
	struct node *front = NULL, *rear = NULL;

	//Allocating memory for the variables:
	front = malloc(sizeof(struct node));
	rear = malloc(sizeof(struct node));

	//Creating the Queue:
	if(createList(front, rear))  return 1;

	//Displaying the queue:
	if(display(front)) return 1;

	//Adding a new element to the Queue:
	if(DeQueue(front, rear))  return 1;

	//Displaying the modified queue:
	if(display(front))  return 1;

	//Freeing the memory:
	freeList(front);  front = NULL;
	free(front);
	free(rear);  rear = NULL;

	return 0;
}


/** ==== Function Definitions ==== **/
//createNode():
//This function creates and initializes it with a value and returns it.

struct node *createNode(int val)
{
	//Declaraing the required variables:
	struct node *new = NULL;

	//Allocating the memory:
	new = malloc(sizeof(struct node));

	//Checking if allocation failed:
	if(new == NULL)
	{
		printf("Memory allocation failed!!\n\n");
		return NULL;
	}

	new -> data = val;
	new -> next = NULL;

	return new;
}


//createList():
//This function creates the list.

int createList(struct node *f, struct node *r)
{
	//Declaring the required variables:
	int i, n, val;
	struct node *temp = NULL;

	printf("\nEnter the total no. of the queue elements: ");
	scanf("%d", &n);

	//Creating the List:
	printf("\nEnter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &val);

		struct node *new = createNode(val);

		if(i==0)
		{
			f -> next = new;
			r -> next = new;
			temp = new;
			continue;
		}

		r -> next = new;
		temp -> next = new;
		temp = new;
	}

	printf("Successfully created the list.\n\n");

	return 0;
}


//display():
//This function displays all of the elements in the queue.

int display(struct node *f)
{
	//Declaring the required variables:
	struct node *temp = NULL;
	
	if(f == NULL)
	{
		printf("\nNo elements in the list!!\n\n");
		return 1;
	}
	temp = f -> next;

	printf("\nThe Queue is: FRONT -> ");
	while(temp != NULL)
	{
		printf(" [ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf("REAR\n\n");

	return 0;
}

//freeList():
//This function frees up the allocated memory.

void freeList(struct node *header)
{
        struct node *curr = header->next;
        while(curr != NULL)
        {
                struct node *next = curr->next;
                free(curr);
                curr = next;
        }

        header->next = NULL;
}


//EnQueue():
//This function adds new item to the queue.

int DeQueue(struct node *f, struct node *r)
{
	//Declaring required variables:
	struct node *temp = NULL;

	//Checking edge case:
	if(f == NULL || r == NULL)
	{
		printf("List is empty!!\n\n");
		return 1;
	}

	temp = f -> next;
	while(temp != NULL)
	{
		temp 
	}

	return 0;
}
