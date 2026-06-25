/** ===== Circular Singly Linked List: Deletion Operation Implementation ===== **/


/** ===== Documentation ===== **/
/*
 * This program creates a circular singly linked list with specified no. of nodes.
 * And, allocates the memory for all of the nodes in the list.
 * Then, initializes all of the nodes with the data values specified by the user.
 * Displays the entire list after initialization.
 * Then, the main feature deletes a node at front/end or any position in the list.
 * And, then prints the final list.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>		//For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>			//For DMA functions like malloc(), free(),...


/** ===== Global Declarations ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
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
			newNode->next = newNode; // circular
		}
		else
		{
			newNode->next = header->next;
			last->next = newNode;
		}

		last = newNode;
		temp = newNode;
	}

	if(temp != NULL)
	{
		temp->next = header->next;
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
//This function displays all of the nodes of the list.

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
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}while(temp != header -> next);

	printf(" [ FIRST NODE ]");
	printf("\nSuccessfully printed the list!!.\n");

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
		return 1;		//Checking Edge case.
	}

	printf("\nSuccessfully deleted the node.\n");
	if(display(header)) return 1;				//Displaying the new list.

	return 0;
}


//deleteFront():
//This function deletes the node that is at the front most position.

int deleteFront()
{
	//Checking if the list is empty:
	if(header ->  next == NULL)
	{
		printf("\nThe list is empty!!");
		return 1;
	}

	struct node *temp = NULL, *curr = NULL;

	temp = header -> next;		//Now temp points to the front node.
	
	//If the list contains only one node:
	if(temp -> next == temp)
	{
		header -> next = NULL;	
		free(temp);
		return 0;
	}

	while(temp -> next != header -> next)
	{
		temp = temp -> next;
	}

	curr = header -> next;
	header -> next = curr -> next;		//Here temp -> next points to the second node.

	//Fix the circular link:
	temp -> next = header -> next;
	free(curr);

	return 0;
}


//deletePos():
//This function deletes the node that is at a specific position.

int deletePos()
{
	int pos, j = 0;

	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	//Taking the position of the nodes:
	printf("\nEnter the Position of the node: ");
	scanf("%d", &pos);

	struct node *temp = NULL, *prev = NULL;
	temp = header -> next;

	//Checking if the  position is out of range:
	if(pos < 1 || pos > n)
	{
		printf("\nPosition of the node is out of bounds. Can't Access!!\n");
		return 1;
	}

	do
	{
		prev = temp;
		temp = temp -> next;
		j += 1;
	}while(temp -> next != header -> next && j < pos);

	prev -> next = temp -> next;
	free(temp);

	return 0;

}


//deleteEnd():
//This function deleted the node that is at the end of the list.

int deleteEnd()
{
	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	struct node *temp = NULL, *prev = NULL;
	temp = header -> next;

	//If the list has only one node:
	if(temp -> next == temp)
	{
		header -> next = NULL;
		free(temp);
		return 0;	
	}

	//Traversing till the end of the list:
	while(temp -> next != header -> next)
	{
		prev = temp;
		temp = temp -> next;
	}

	//Deleting the link betwwen the n and n-1 node:
	prev -> next = header -> next;
	free(temp);

	return 0;
}
