/** ==== Stacks : Push Operation ==== **/


/** ==== Documentation ==== **/
/*
 * This program shows the implementation of the push operation on the stacks which represented using Linked Lists.
 * At first, this program creates a stack with data and prints it.
 * Then, pushes a new element to the stack.
 * Finally, prints the modified stack.
*/


/** ==== Preprocessing Directives: ==== **/
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free().


/** ==== Global Declarations: ==== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};


/** ==== Function Prototypes: ==== **/
struct node* createNode(int);
int createStk(struct node*, struct node*);
int display(struct node*, struct node*);
int PUSH(struct node*);
void freeList(struct node*);


/** ==== Main Function ==== **/
int main()
{
	//Declaring the required pointers:
	struct node *top = NULL, *header = NULL;

	//Allocating memory:
	top = malloc(sizeof(struct node*));
	header = malloc(sizeof(struct node*));

	//Chacking if allocation failed:
	if(top == NULL || header == NULL)
	{
		printf("Memory allocation failed!!\n\n");
		return 1;
	}

	//Now creating the stack with the values:
	if(createStk(header, top))  return 1;

	//Now displaying the created stack:
	if(display(header, top))  return 1;

	//Now pushing a new item to the stack:
	if(PUSH(top))  return 1;

	//Now displaying the modified stack:
	if(display(header, top))  return 1;

	//Cleanup:
	freeList(header);
	free(top);  top = NULL;
	free(header);  header = NULL;


	return 0;
}


/** ==== Function Definitions ==== **/
//createNode():
//This function creates a node and returns the node with the value given.

struct node *createNode(int val)
{
	//Declaring the required pointers:
	struct node *newNode = NULL;

	//Allocating the memory for the node:
	newNode = malloc(sizeof(struct node));

	if(newNode == NULL)
	{
		printf("Memory allocation failed!!\n\n");
		return NULL;
	}

	newNode -> data = val;
	newNode -> next = NULL;

	return newNode;
}


//createStk():
//This function creates and intializes the stack with some values.

int createStk(struct node *head, struct node *top)
{
	//Declaring the required variables:
	int val, i, n;
	struct node *last = NULL;

	printf("\nEnter the total no. of elements in the stack: ");
	scanf("%d", &n);

	//Checking edge case:
	if(n < 1)
	{
		printf("No elements in the stack!!\n\n");
		return 1;
	}

	//Creating the stack now:
	printf("\nEnter the values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &val);

		struct node *new = createNode(val);

		if(head -> next == NULL)
		{
			head -> next = new;
		}

		else
		{
			last -> next = new;
		}

		last = new;
		top -> next = new;	//Updating the top pointer.
	}

	printf("Successfully created the stack.\n\n");

	return 0;
}


//display():
//This function displays all of the stack elements.

int display(struct node *head, struct node *top)
{
	//Checking if the stack is empty:
	if(head -> next == NULL)
	{
		printf("The stack is empty!!\n\n");
		return 1;
	}

	struct node *temp = head -> next;

	printf("\nThe Stack is:\n\n");
	while(temp != NULL)
	{
		printf("\t\t[ %d ]", temp -> data);

		if(temp != top -> next)
		{
			printf("\n");
		}

		else
		{
			printf("  -> TOP\n");
		}

		temp = temp -> next;
	}

	printf("Successfully displayed the stack.\n\n");

	return 0;
}


//PUSH():
//This function pushes a new item to the stack.

int PUSH(struct node *top)
{
	int val;

	printf("\nEnter the value of the new item: ");
	scanf("%d", &val);

	//Creating a new item:
	struct node *new = createNode(val);

	//Pushing the new item to the stack:
	top -> next -> next = new;
	top -> next = new;

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

