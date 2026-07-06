/** ===== Circular Double Linked List: Deletion Operation Implementation ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the Node Deletion operation on a Circular Double Linked List.
 * In this we do the following processes:
	* Creation of the List.
	* Initialization of the List with certain values.
	* Display the List.
	* Deletion of a node at the front or middle(any position) or at the end of the list.
	* Again, display the new list.
 * Thus, we finally delete the node at the required position of the list.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>		//For DMA functions like malloc(), free(),...


/** ===== Global Declarations ===== **/
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
int deleteMain(void);
int deleteFront(void);
int deletePos(void);
int deleteEnd(void);


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

	printf("\nEnter the no. of nodes: ");
	scanf("%d", &n);
	if(n < 1)
	{
		printf("\nNot enough nodes to create!!\n");
		status = 1;
		goto cleanup;
	}

	printf("\nEnter all the values of the nodes in the list: ");
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
	if(deleteMain())
	{
		status = 1;
	}

	cleanup:
	//Free memory:
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
			newNode->next = newNode;	// circular
			newNode->prev = newNode;	// circular (points to itself initially)
		}
		else
		{
			newNode->next = header->next;	// new last node points to first node
			newNode->prev = last;			// new last node's prev points to previous last
			last->next = newNode;			// old last node's next points to new node
			header->next->prev = newNode;	// first node's prev points to new last node
		}

		last = newNode;
		temp = newNode;
	}

	printf("\nSuccessfully stored all of the data values.\n");
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


//deleteMain():
//This function lets user decide which node to delete from the list.

int deleteMain()
{
	int choice;

	printf("\nWhich node do you want to delete: ");
	printf("\n1. Node at Front\n2. Node at any Position\n3. Node at End\n");
	printf("\nChoose one of the option: ");
	scanf("%d", &choice);

	if(choice == 1)
	{
		if(deleteFront()) return 1;
	}
	else if(choice == 2)
	{
		if(deletePos()) return 1;
	}
	else if(choice == 3)
	{
		if(deleteEnd()) return 1;
	}
	else
	{
		printf("\nInvalid option!!\n");
		return 1;
	}

	printf("\nSuccessfully deleted the node.\n");
	if(display(header)) return 1;		//Displaying the new list.

	return 0;
}


//deleteFront():
//This function deletes the node at the front of the list.

int deleteFront()
{
	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!");
		return 1;
	}

	struct node *temp = header -> next;	//temp points to the front node.

	//If the list contains only one node:
	if(temp -> next == temp)
	{
		header -> next = NULL;
		free(temp);
		return 0;
	}

	//Find the last node (the one whose next points back to temp):
	struct node *last = temp -> prev;	//In CDL, prev of first = last node

	header -> next = temp -> next;		//Advance front to the second node
	header -> next -> prev = last;		//New front's prev = old last node
	last -> next = header -> next;		//Old last node's next = new front node

	free(temp);

	return 0;
}


//deletePos():
//This function deletes the node at a specific position.

int deletePos()
{
	int pos, j = 0;

	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	//Taking the position of the node:
	printf("\nEnter the Position of the node: ");
	scanf("%d", &pos);

	//Checking if the position is out of range:
	if(pos < 1 || pos > n)
	{
		printf("\nPosition of the node is out of bounds. Can't Access!!\n");
		return 1;
	}

	struct node *temp = header -> next, *prev = NULL;

	do
	{
		prev = temp;
		temp = temp -> next;
		j += 1;
	}while(temp -> next != header -> next && j < pos);

	//Unlink temp from the list:
	prev -> next = temp -> next;
	temp -> next -> prev = prev;

	free(temp);

	return 0;
}


//deleteEnd():
//This function deletes the node at the end of the list.

int deleteEnd()
{
	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	struct node *temp = header -> next;

	//If the list has only one node:
	if(temp -> next == temp)
	{
		header -> next = NULL;
		free(temp);
		return 0;
	}

	//The last node is temp->prev (CDL circular: first->prev = last):
	struct node *last = temp -> prev;
	struct node *secondLast = last -> prev;

	secondLast -> next = header -> next;	//New last node's next = first node
	header -> next -> prev = secondLast;	//First node's prev = new last node

	free(last);

	return 0;
}
