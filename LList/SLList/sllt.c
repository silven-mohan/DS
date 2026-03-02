/** ===== Traversal on Single Linked List ===== **/


/*
 * This program shows the implementation of the traversal operation on a single linked list.
 * This contains a function called traverse() which takes the header node, upto which position of the list to traverse.
 * And, prints the node's data value at that position after traversing.
 * This program handles edge cases like empty list, position out of bounds,......
*/


/** ---- Preprocessing Directives ---- **/
#include<stdio.h>		//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free(),...
			

/** ---- Global Declaration ---- **/
/* -- Node Definition -- */
struct node {
	int data;
	struct node *next;
};

struct node header, *N = NULL;		//Declaring here for the global access.
int n;


/** ---- Function Prototypes ---- **/
int create(void);
int init(void);
int display(void);
int traverse(void);


/** ---- Main Function ---- **/
int main()
{
	if(create()) return 1; 			//Creation.
	init();		//Initialization.
	display();		//Display the node.
	if(traverse()) return 1;	//Find a node by traversing through the list.
	
	//Free the allocated memory:
	free(N);
	N = NULL;

	return 0;
}


/* -- Function Definitions -- */

//create():
//This function creates and allocates memory for all the required number(specified by the user) of nodes.

int create(void)
{
	printf("\nEnter the no. of nodes required: ");		//Taking the total no. of nodes from the user.
	scanf("%d", &n);

	//Allocating the memory for the nodes:
	N = malloc(n * sizeof(struct node *));

	if(n < 1)
	{
		printf("\nNot enough nodes to create!!\n");		//Checking edge case that there are no nodes.
		return 1;
	}

	if(N == NULL)
	{
		printf("\nMemory allocation failed!!\n");		//Checking if memory allocation failed.
		return 1;
	}

	printf("\nSuccessfully created all of the nodes.\n");

	return 0;
}


//init():
//This function initializes the node's data variables with the user given values.

int init(void)
{
	int i;

	header.next = N;		//Now header points to the first node.

	//Now taking all of the values from the user:
	printf("\nEnter the node's data values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &((N+i) -> data));
		if(i == n-1)
		{
			(N+i) -> next = NULL;
			return 0;
		}
		(N+i) -> next = N+(i+1);
	}
	printf("\nSuccessfully initialized the list with values.\n");
	
	return 0;
}


//display():
//This function displays all of the values of the list.

int display(void)
{
	int i = 0;

	struct node *temp;

	//Printing all the nodes:
	temp = header.next;
	
	printf("\nThe list is: ");
	while(temp != NULL)
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf("[ NULL ]\n");

	printf("\nSuccessfully printed the list.\n");

	return 0;
}


//traverse():
//This function prints out the value in node that is in a specific position.

int traverse(void)
{
	int pos, i=0;
	struct node * temp;

	printf("\nEnter the position of the required node: ");
	scanf("%d", &pos);			//Taking the position of the node from the user.
	
	if(pos < 0 || pos > n-1)
	{
		printf("\nNo nodes to print!!.");		//Checking if the position is out of bounds.
		return 1;
	}

	temp = header.next;

	while(temp -> next != NULL && i < pos)
	{
		temp = temp -> next;
		i += 1;
	}

	printf("\nThe value in the node at position %d is: %d\n\n", pos, temp -> data);

	return 0;
}
