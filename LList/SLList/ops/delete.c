/** ===== Singly Linked List: Deletion Operation Implementation ===== **/


/** ===== Documentation ===== **/
/*
 * This program creates a singly linked list with specified no. of nodes.
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

struct node header, *N = NULL;		//Declaring here for global access.
int n;


/** ===== Function Prototypes ===== **/
int create(void);
int init(void);
int display(void);
int deleteMain(void);
int deleteFront(void);
int deletePos(void);
int deleteEnd(void);


/** ===== Main Function ===== **/
int main()
{
	if(create()) return 1;
	init();
	if(display()) return 1;
	if(deleteMain()) return 1;

	return 0;
}


/** ===== Function Definitions ===== **/
 
//create():
//This function creates the specified no. of nodes and allocates them some memory.

int create()
{
	//Taking the no. of nodes from the user.
	printf("\nEnter the no. of nodes: ");
	scanf("%d", &n);

	if(n < 1)
	{
		printf("\nNot enough nodes to create!!\n");	//Checking Edge case.
		return 1;
	}

	//Allocating memory for all of the nodes:
	N = malloc(n * sizeof(struct node));
	
	if(N == NULL)
	{
		printf("\nMemory allocation failed!!\n");		//Checking if memory allocation is failed.
		return 1;
	}

	return 0;
}


//init():
//This function intialises all of the nodes with data values taken from the user.

int init()
{
	int i = 0;

	//Linking the first node to the header node:
	header.next = &N[0];
	
	//Taking the data values from the user:
	printf("\nEnter all the values of the nodes in the list: ");
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &((N+i) -> data));

		if(i == n-1)
		{
			(N+i) -> next = NULL;
			break;
		}

		(N+i) -> next = ((N+i)+1);
	}

	printf("\nSuccessfully stored all of the data values.\n");

	return 0;
}


//display():
//This function displays all of the nodes of the list.

int display()
{
	//Checking if the list is empty:
	if(header.next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	struct node *temp = NULL;
	temp = header.next;

	//Traversing through the list to print all the nodes:
	printf("\nThe List is: \n");
	while(temp != NULL)
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf(" [ NULL ]");
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
	if(display()) return 1;				//Displaying the new list.

	return 0;
}


//deleteFront():
//This function deletes the node that is at the front most position.

int deleteFront()
{
	//Checking if the list is empty:
	if(header.next == NULL)
	{
		printf("\nThe list is empty!!");
		return 1;
	}

	struct node *temp = NULL;

	temp = header.next;		//Now temp points to the front node.
	
	//If the list contains only one node:
	if(temp -> next == NULL)
	{
		header.next == NULL;	
		return 0;
	}

	header.next = temp -> next;		//Now temp -> next points to the second node.

	return 0;
}


//deletePos():
//This function deletes the node that is at a specific position.

int deletePos()
{
	int pos, j = 0;

	//Checking if the list is empty:
	if(header.next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	//Taking the position of the nodes:
	printf("\nEnter the Position of the node: ");
	scanf("%d", &pos);

	struct node *temp = NULL, *prev = NULL;
	temp = header.next;

	while(temp != NULL && j < pos)
	{
		prev = temp;
		temp = temp -> next;
		j += 1;
	}

	prev -> next = temp -> next;

	return 0;

}


//deleteEnd():
//This function deleted the node that is at the end of the list.

int deleteEnd()
{
	//Checking if the list is empty:
	if(header.next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	struct node *temp = NULL, *prev = NULL;
	temp = header.next;

	//If the list has only one node:
	if(temp -> next == NULL)
	{
		header.next = NULL;
		return 0;	
	}

	//Traversing till the end of the list:
	while(temp -> next != NULL)
	{
		prev = temp;
		temp = temp -> next;
	}

	//Deleting the link betwwen the n and n-1 node:
	prev -> next = NULL;

	return 0;
}
