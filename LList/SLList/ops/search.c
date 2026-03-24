/** ===== Single Linked List: Linear Search ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the search operation on a Single Linked List.
 * In this we do the following processes:
 	* Creation of the List.
	* Initialization of the List with certain values.
	* Display the List.
	* Then, searches for an element specified by the user in the list.
 * At last, prints the element position if it is found. 
 * If the element is not found then prints a message that tells that element was not found.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),....
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ===== Function Prototypes ===== **/
int create(void);
int init(void);
int display(void);
int search(void);


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};

struct node header, *N = NULL, new;		//Declaraing here for global access.
int n;


/** ===== Main Function ===== **/
int main()
{
	if(create()) return 1;
	init();
	if(display()) return 1;
	search();

	return 0;
}


/** ===== Function Definitions ===== **/
//create():
//This function allocates the memory for the nodes.

int create()
{
	//Taking the total no. of nodes from the user:
	printf("\nEnter the no. of nodes of the list: ");
	scanf("%d", &n);

	if(n < 1)
	{
		printf("\nInsufficient nodes to create a list!!\n\n");		//Handling edge cases.
		return 1;
	}

	//Allocating the memory for the n nodes.
	N = malloc(n * sizeof(struct node));

	if(N == NULL)
	{
		printf("\nMemory allocation failed!");		//Checking if memory allocation is done or not.
		return 1;				
	}

	return 0;
}


//init():
//This function initializes all of the nodes in the list with a certain values.

int init()
{
	int i = 0;

	//Linking header node to the N nodes.
	header.next = &N[0];

	//Taking the data of all the nodes.
	printf("\nEnter the data of all of the nodes: ");
	while(i < n)
	{
		scanf("%d", &((N+i) -> data));
		if(i == n-1)
		{
			(N+i) -> next = NULL;
			return 0;
		}

		(N+i) -> next = ((N+i)+1);
		i += 1;
	}

	printf("\nSuccessfully initialized all the nodes with data.\n\n");

	return 0;
}


//display():
//This function displays all of the nodes and it's data.

int display()
{
	//Checking the edge case:
	if(header.next == NULL)
	{
		printf("\nThe list is empty!!\n\n");
		return 1;
	}

	struct node *temp = header.next;

	//Traversing through every node and printing their data values.
	while(temp != NULL)
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf(" [ NULL ]");

	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}


//search():
//This function takes an element from the user and searches for the element in the list.

int search()
{
	int key, i = 0;
	
	//Taking the element from the user:
	printf("\nEnter the element that is to be searched: ");
	scanf("%d", &key);

	struct node *temp = NULL;
	temp = &header;

	//Traversing through the entire list:
	while(temp -> next != NULL)
	{
		if(temp -> data == key)		//Comparing the node with key.
		{
			printf("\n%d is found in the list at the position: %d\n", key, i);
			
			return 0;
		}
		i += 1;
		temp = temp -> next;
	}	

	printf("\nElement was not found.\n");
	
	return 1;
}
