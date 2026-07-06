/** ===== Circular Double Linked List: Backward Traversal ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the backward traversal of a Circular Double Linked List.
 * In this we do the following processes:
	* Creation of the List.
	* Initialization of the List with certain values.
	* Display the List (forward traversal).
	* Then, backward traversal of the list using the prev pointers.
 * At last, prints the backward traversed list.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>		//For DMA functions like malloc(), free(),...


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *header = NULL, *N = NULL;		//Declaring here for global access.
int n;


/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void createList(int n);
void freeList(void);
int display(struct node *);
int reverseTraverse(struct node *);


/** ===== Main Function ===== **/
int main()
{
	int status = 0;
	header = malloc(sizeof(struct node));
	if(header == NULL)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}
	header->next = NULL;
	header->prev = NULL;

	printf("\nEnter the no. of nodes of the list: ");
	scanf("%d", &n);
	if(n < 1)
	{
		printf("\nInsufficient nodes to create a list!!\n\n");
		status = 1;
		goto cleanup;
	}

	printf("\nEnter the data of all of the nodes: ");
	createList(n);
	if(header->next == NULL)
	{
		status = 1;
		goto cleanup;
	}

	printf("\nThe List is: ");
	if(display(header))
	{
		status = 1;
		goto cleanup;
	}

	printf("\nThe List when backward traversal: ");
	if(reverseTraverse(header))
	{
		status = 1;
	}

	cleanup:
	//free the allocated memory:
	freeList();
	free(header);  header = NULL;

	return status;
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
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}


//createList():
//This function initializes the list with user-provided values.

void createList(int n)
{
	struct node *temp = NULL, *last = NULL;

	for(int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		struct node *newNode = createNode(val);

		if(newNode == NULL)
		{
			freeList();
			return;
		}

		if(header->next == NULL)
		{
			header->next = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
		}
		else
		{
			newNode->next = header->next;
			newNode->prev = last;
			last->next = newNode;
			header->next->prev = newNode;
		}

		last = newNode;
		temp = newNode;
	}

	printf("\nSuccessfully initialized all the nodes with data.\n\n");
}


void freeList(void)
{
	if(header->next == NULL)
	{
		return;
	}

	struct node *first = header->next;
	struct node *curr = first->next;
	while(curr != first)
	{
		struct node *next = curr->next;
		free(curr);
		curr = next;
	}
	free(first);
	header->next = NULL;
}


//display():
//This function displays all of the nodes of the list (forward traversal).

int display(struct node *head)
{
	//Checking the edge case:
	if(head -> next == NULL)
	{
		printf("\nThe list is empty!!\n\n");
		return 1;
	}

	struct node *temp = head -> next;

	//Traversing through the list to print all the nodes:
	printf("\nThe List is: \n");
	do
	{
		printf("[ %d ] -> <- ", temp -> data);
		temp = temp -> next;
	}while(temp != head -> next);

	printf("\b\b\b [ FIRST NODE ]");
	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}


//reverseTraverse():
//This function shows the backward traversal of the Circular Double Linked List using prev pointers.

int reverseTraverse(struct node *head)
{
	if(head -> next == NULL)
	{
		printf("\nThe list is empty!!\n\n");
		return 1;
	}

	//The last node is the prev of the first node (circular prev link):
	struct node *lastNode = head -> next -> prev;
	struct node *curr = lastNode;

	//Backward Traversing using prev links:
	printf("\nThe List (backward): \n");
	do
	{
		printf("[ %d ] -> <- ", curr -> data);
		curr = curr -> prev;
	}while(curr != lastNode);

	printf("\b\b\b [ LAST NODE ]");
	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}
