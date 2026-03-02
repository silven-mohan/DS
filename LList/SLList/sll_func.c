/** ===== Single Linked List Implementation: v2.0 ===== **/


/*
 * This program shows the implementation of the single linked list.
 * This program uses helper functions like create(), display(),... to create and access the single linked list.
 * The helper functions were declared and defined by the user.
 * The list in this program contains a node which has a data member which stores the values and a pointer member which points to the next node in the list.
*/


/* ---- Preprocessing Directives: ---- */
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(), ....
#include<stdlib.h>	//For DMA functions like malloc(), free(),...
		

/* ---- Global Declaration: ---- */

/* -- Linked List Node Definition -- */
struct node {
	int data;
	struct node * next;
};


/* -- Global Variables Declaration: -- */
struct node header, *N = NULL; 		//Declaring here for global access.
int n;


/* -- Function Prototypes: -- */
int create(void);
int init(void);
int display(void);



/* ---- Main Function ---- */
int main()
{
	if(create()) return 1;
	init();
	if(display()) return 1;
	
	//Free the allocated memory:
	free(N);
	N = NULL;

	return 0;
}



/* -- Function Definition: -- */

//create():
//This function allocates the memory for required number of the nodes in the list.
int create(void)
{
	printf("\nEnter how many nodes you want in the list: ");
	scanf("%d", &n);

	if(n < 1)
	{
		printf("\nNot enough nodes in the list!!\n\n");		//Handling edge case.
		return 1;
	}

	//Allocating the memory for all nodes:
	N = malloc(n * sizeof(struct node *));


	if(N == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return 1;					//Checking for memory allocation fails.
	}

	printf("\nSuccessfully created the Single Linked List.\n");

	return 0;
}



//init():
//This function initializes the data of the n nodes in the list with the user given data.
int init(void)
{
	int i;
	header.next = N;		//Now the header points to the first node.
	
	printf("\nEnter the values for the %d nodes: ", n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &((N+i) -> data));
		
		if(i == n-1)
		{
			(N+i) -> next = NULL;		//Take the values from the user.
			break;
		}

		(N+i) -> next = N+(i+1);
	}
	
	printf("\nSuccessfully initialized the data of the %d nodes.\n", n);

	return 0;
}



//display():
//This function displays all of the data of the n nodes in the list.
int display(void)
{
	int i;
	
	if(header.next == NULL)
	{
		printf("\nThe list is empty can't access any data.\n");		//Handling edge case.
		return 1;
	}

	struct node *temp;
	temp = header.next;

	//Printing all the node's data values by traversing through the list.
	printf("\nThe data in all of the nodes is: \n");
	while(temp != NULL)
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf("[ NULL ]\n\n");

	return 0;
}
