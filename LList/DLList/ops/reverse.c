/** ===== Double Linked List: Reversing of the list  ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the reverse operation on a Double Linked List.
 * In this we do the following processes:
 	* Creation of the List.
	* Initialization of the List with certain values.
	* Display the List.
	* Then, reverses the list.
 * At last, prints the reversed list. 
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),....
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *header = NULL, *N = NULL;		//Declaraing here for global access.
int n;


/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void createList(int n);
void freeList(void);
int display(struct node *);
int reverse(void);



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

	if(display(header))
	{
		status = 1;
		goto cleanup;
	}
	if(reverse())
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
	struct node *temp, *last = NULL;

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
		}
		else
		{
			newNode->prev = last;
			last->next = newNode;
		}

		last = newNode;
		temp = newNode;
	}

	if(temp != NULL)
	{
		temp->next = NULL;
	}

	printf("\nSuccessfully initialized all the nodes with data.\n\n");
}

void freeList(void)
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


//display():
//This function displays all of the nodes and it's data.

int display(struct node *head)
{
	//Checking the edge case:
	if(head -> next == NULL)
	{
		printf("\nThe list is empty!!\n\n");
		return 1;
	}

	struct node *temp = head -> next;

	//Traversing through every node and printing their data values.
	while(temp != NULL)
	{
		printf("[ %d ] -> <- ", temp -> data);
		temp = temp -> next;
	}
	printf("\b\b\b [ NULL ]");

	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}


//reverse():
//This function reverses the list.

int reverse()
{
	struct node *prev = NULL, *curr = NULL, *next = NULL;

	//Store the first node in curr:
	curr = header -> next;

	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		curr -> prev = next;
		prev = curr;
		curr = next;
	}

	//Linking the last node to the header node:
	header -> next = prev;

	printf("\nThe reversed list is: ");
	if(display(header)) return 1;

	return 0;
}
