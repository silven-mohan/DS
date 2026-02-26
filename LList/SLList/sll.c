/**** ====== Single Linked List Implementation ====== ****/

/*
 * This program shows the implementation of the Single Linked List.
 * In this program, total three nodes were used for the list and a header node which indicates the start of the list.
 * Each node in the list has two members one is data which stores the values and the other one is the pointer that points to the next node or NULL.
 * At last, this shows how the members of each node can be accessed node by node and hence prints the values in the data members.
*/


/** ---- Preprocessing Directives ---- **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>	//For DMA functions; malloc(), free(),.....
		

/** ---- Global Declaration ---- **/

/* -- Linked List Node Definition --*/
struct node {
	int data;	//Member that stores the data.
	struct node *next;	//Member that points to the next node.
};


struct node *header = NULL;		//Declaring the header pointer globally.


/** ---- Main Function ---- **/
int main()
{
	//Declaring the nodes:
	struct node *first = NULL, *second = NULL, *third = NULL;


	//Allocating the memory for all the nodes:
	header = (struct node *) malloc(sizeof(struct node *));
	first = (struct node *) malloc(sizeof(struct node *));
	second = (struct node *) malloc(sizeof(struct node *));
	third = (struct node *) malloc(sizeof(struct node *));


	//Checking for any errors in the memory allocation process:
	if(header == NULL || first == NULL || second == NULL || third == NULL)
	{
		printf("\nMemory allocation failed!\n");
		return 1;
	}

	//Initializing nodes with some data:
	header -> next = first;

	first -> data = 1;
	first -> next = second;

	second -> data = 2;
	second -> next = third;

	third -> data = 3;
	third -> next = NULL;


	//Accessesing:
	printf("\n\n[ %d ] -> [ %d ] -> [ %d ]\n\n", first -> data, second -> data, third -> data);



	//Free the allocated memory:
	free(first);
	free(second);
	free(third);
	free(header);

	return 0;
}
