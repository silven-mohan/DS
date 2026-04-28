/** =====  Linked Lists: Node Counting Implementation ===== **/


/** ===== Documentation ===== **/
/*
 * This program creates a linked list and initializes the list with the user given values.
 * Then , by traversing through the list counts all of the nodes in the list and prints the count.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions...
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ===== Global Declarations ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};


/** ===== Function Prototypes ===== **/
struct node *createNode(int);
int createList(struct node *, int);
int display(struct node *);
int NodeCount(struct node *);


/** ===== Main Function ===== **/
int main()
{
	//Declaraing the required variables:
	struct node *header = NULL;
	int n;

	//Allocating the memory:
	header = malloc(sizeof(struct node));
	header -> next = NULL;

	//Checking if the allocation failed:
	if(header == NULL)
	{
		printf("Memory Allocation failed!!\n\n");
		return 1;
	}

	//Now creating the list:
	printf("\nEnter the size of the list: ");
	scanf("%d", &n);

	if(createList(header, n))  return 1;

	printf("\n\nThe List is: ");
	if(display(header))  return 1;

	printf("\nThe Node Count of the list is: %d\n\n", NodeCount(header));

	return 0;
}


/** ===== Function Definitions ===== **/

//createNode():
//This function allocates the memory and initializes the values of node.

struct node *createNode(int val)
{
	struct node *newNode = NULL;

	//Allocating memory:
	newNode = malloc(sizeof(struct node));

	//Checking edge cases:
	if(newNode == NULL)
	{
		printf("Memory allocation failed!!\n\n");
		return NULL;
	}

	newNode -> data = val;
	newNode -> next = NULL;

	return newNode;
}


//createList():
//This function creates the single linked list.

int createList(struct node *head, int n)
{
	//Declaring the variables:
	int i, value;
	struct node *last = NULL, *temp = NULL;

	//Checking edge case #1:
	if(n < 1)
	{
		printf("Less no. of nodes to create the list!!\n\n");
		return 1;
	}

	printf("Enter the values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &value);

		struct node *new = createNode(value);

		if(head -> next == NULL)
		{
			head -> next = new;
		}

		else
		{
			last -> next = new;
		}

		last = new;
		temp = new;
	}

	if(temp -> next != NULL)
	{
		temp -> next = NULL;
	}

	return 0;
}


//display():
//This function traverses through the list and prints the values.

int display(struct node *head)
{
	//Checking if list is empty:
	if(head -> next == NULL)
	{
		printf("\nNo elements to display!!\n\n");
		return 1;
	}	

	struct node *temp = head -> next;

	while(temp != NULL)
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf(" [NULL]\n\n");

	return 0;
}


//NodeCount():
//This function traverses through the entire list and gives the node count of that specific list.

int NodeCount(struct node *head)
{
	int count = 0;

	struct node *temp = head;

	while(temp != NULL)
	{
		count++;
		temp = temp -> next;
	}

	return count - 1;
}
