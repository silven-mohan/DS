/** ===== Single Linked List: Node Insertion Implementation ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the Node Insertion operation on a Single Linked List.
 * In this we do the following processes:
 	* Creation of the List.
	* Initialization of the List with certain values.
	* Display the List.
	* Insertion of a new node at the front or middle(any position) or at the end of the list.
	* Again, display the new list.
 * Thus, we finally insert a new node at the required position of the list.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),....
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ===== Function Prototypes ===== **/
int create(void);
int init(void);
int display(void);
int insertMain(void);
int insertFront(void);
int insertPos(void);
int insertEnd(void);


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
	printf("\nThe List is : ");
	if(display()) return 1;
	if(insertMain()) return 1;

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


//insertMain():
//This function created the new node that is to be inserted and determines where it should be inserted(front, end, or any other position)

int insertMain()
{
	int choice;

	//Creating the new node that is to be inserted:	
	printf("\nEnter the data value of the new node that is to be inserted: ");
	scanf("%d", &new.data);
	new.next = NULL;
	printf("\nSuccessfully created the new node.\n");

	//Taking the user's choice at which position should the node be inserted.
	printf("\nAt which position should the node be inserted: ");
	printf("\n1. Front\n2. At any position 'n'\n3. End\n");
	printf("\nChoose one of the option: ");
	scanf(" %d", &choice);

	//Execution based on the choice:
	if(choice == 1)
	{
		if(insertFront()) return 1;
	}
	else if(choice == 2)
	{
		if(insertPos()) return 1;
	}
	else if(choice == 3)
	{
		if(insertEnd()) return 1;
	}
	else
	{
		printf("\nInvalid Option!!");
		return 1;
	}
	printf("\nSuccessfully inserted the node.\nThe list after the node insertion is: ");
	display();

	return 0;
}


//insertFront():
//This function inserts a node the front of the list.

int insertFront()
{
	struct node *temp;

	temp = header.next;

	//Linking the new node to the header node.
	header.next = &new;

	//Linking the list to the new node that is inserted at the front position.
	new.next = temp;

	return 0;
}


//insertPos():
//This function inserts a node at the specified position.

int insertPos()
{
	int pos, j=0;
	printf("\nAt which position do you want to insert the node: ");
	scanf(" %d", &pos);

	if(pos < 0 || pos > n+1)
	{
		printf("\nCannot insert at that position.\n");
		return 1;
	}	

	if(pos == 0)
	{
		insertFront();
		return 0;
	}
	if(pos == n+1)
	{
		insertEnd();
		return 0;
	}
	
	struct node *temp = NULL, *prev = NULL;

	temp = header.next;

	while(temp != NULL && j < pos)
	{
		prev = temp;
		temp = temp -> next;
		j += 1;
	}
	
	//Linking the new node to the node befor position 'pos':
	prev -> next = &new;

	//Linking the nodes from the position 'pos' to the the new node:
	new.next = temp;

	//Display the modified list:
	display();

	return 0;
}


//insertEnd():
//This function inserts a node at the end of the list.

int insertEnd()
{
	struct node *temp;

	temp = header.next;


	//Traversing till the last node:
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}

	//Inserting the node at the end:
	temp -> next = &new;
	new.next = NULL;

	return 0;
		
}
