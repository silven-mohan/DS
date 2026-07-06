/** ===== Circular Double Linked List: Merge Operation ===== **/


/** ===== Documentation ===== **/
/*
 * This program creates two Circular Double Linked Lists. (Dynamically allocates the memory for the lists)
 * Initializes their data elements with the user given values.
 * And, displays these two lists.
 * Creates a new list that is a merged list of both lists.
 * And, finally displays the merged list.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>		//For Basic I/O functions.
#include<stdlib.h>	//For DMA functions like malloc(), free(),...


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *header1 = NULL, *header2 = NULL, *header3 = NULL, *header = NULL, *N1 = NULL, *N2 = NULL;
int n1, n2;


/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void createList(int n);
void freeList(struct node *head);
int display(struct node *);
int merge(struct node *, struct node *);


/** ===== Main Function ===== **/
int main()
{
	int status = 0;
	//Allocating memory for header nodes:
	header1 = malloc(sizeof(struct node));
	header2 = malloc(sizeof(struct node));
	header3 = malloc(sizeof(struct node));
	if(header1 == NULL || header2 == NULL || header3 == NULL)
	{
		printf("Memory allocation failed!\n");
		status = 1;
		goto cleanup;
	}
	header1->next = NULL;  header1->prev = NULL;
	header2->next = NULL;  header2->prev = NULL;
	header3->next = NULL;  header3->prev = NULL;


	//First list:
	printf("\nThe first list: \n");
	printf("\nEnter the no. of nodes in the list: ");
	scanf("%d", &n1);
	if(n1 < 1)
	{
		printf("\nNo elements to create the list!!\n");
		status = 1;
		goto cleanup;
	}
	printf("\nEnter the node values: ");
	header = header1;
	createList(n1);
	if(display(header1))
	{
		status = 1;
		goto cleanup;
	}

	//Second List:
	printf("\nThe second list: \n");
	printf("\nEnter the no. of nodes in the list: ");
	scanf("%d", &n2);
	if(n2 < 1)
	{
		printf("\nNo elements to create the list!!\n");
		status = 1;
		goto cleanup;
	}
	printf("\nEnter the node values: ");
	header = header2;
	createList(n2);
	if(display(header2))
	{
		status = 1;
		goto cleanup;
	}

	//Merging:
	printf("\nThe merged list: \n");
	if(merge(header1, header2))
	{
		status = 1;
		goto cleanup;
	}
	if(display(header3)) status = 1;

	cleanup:
	//Free the memory:
	if(header3 != NULL && header3->next != NULL)
	{
		freeList(header3);
		if(header1 != NULL) header1->next = NULL;
		if(header2 != NULL) header2->next = NULL;
	}
	else
	{
		if(header1 != NULL) freeList(header1);
		if(header2 != NULL) freeList(header2);
	}

	free(header1); header1 = NULL;
	free(header2); header2 = NULL;
	free(header3); header3 = NULL;

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
			freeList(header);
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

	printf("\nSuccessfully initialized the list with values.\n");
}


void freeList(struct node *head)
{
	if(head->next == NULL)
	{
		return;
	}

	struct node *first = head->next;
	struct node *curr = first->next;
	while(curr != first)
	{
		struct node *next = curr->next;
		free(curr);
		curr = next;
	}
	free(first);
	head->next = NULL;
}


//display():
//This function traverses through the list and displays the node values.

int display(struct node *head)
{
	if(head -> next == NULL)
	{
		printf("\nThe list is empty!!\n\n");
		return 1;
	}

	struct node *temp = head -> next;

	printf("\nThe list is: \n");
	do
	{
		printf("[ %d ] -> <- ", temp -> data);
		temp = temp -> next;
	}while(temp != head -> next);

	printf("\b\b\b [ FIRST NODE ]\n");

	return 0;
}


//merge():
//This function merges two Circular Double Linked Lists into a single list (header3).

int merge(struct node *h1, struct node *h2)
{
	struct node *first1 = h1 -> next;	//First node of list1
	struct node *last1  = first1 -> prev;	//Last node of list1 (circular: first->prev = last)
	struct node *first2 = h2 -> next;	//First node of list2
	struct node *last2  = first2 -> prev;	//Last node of list2

	//Link header3 to the first node of list1:
	header3 -> next = first1;

	//Link the last node of list1 to the first node of list2:
	last1 -> next = first2;
	first2 -> prev = last1;

	//Restore the circular link: last node of list2 points back to first node of list1:
	last2 -> next = header3 -> next;
	header3 -> next -> prev = last2;

	return 0;
}
