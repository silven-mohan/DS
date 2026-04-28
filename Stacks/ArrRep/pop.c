/** ==== Stacks : Pop Operation Implementation ==== **/


/** ==== Documentation ==== **/
/*
 * This program shows the implementation of the pop operation on the stacks which are implemented using arrays.
 * In this a stack with some values is created and initialized.
 * Then, an item is popped from the stack
 * Finally, displays all of the members in the stack.
*/


/** ==== Preprocessing Directives: ==== **/
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free(),...


/** ==== Function Prototypes: ==== **/
int createStk(int *, int, int *);
int display(int *, int);
int POP(int *, int *);


/** ==== Main Function ==== **/
int main()
{
	//Declaring the required variables:
	int size, top = 0;

	printf("\n\nEnter the size of the stack: ");
	scanf("%d", &size);

	int STK[size];

	//Creating the stack:
	if(createStk(&STK[0], size, &top))  return 1;

	//Displaying the stack:
	if(display(&STK[0], top))  return 1;

	//Poping the items:
	if(POP(&STK[0], &top))  return 1;

	if(display(&STK[0], top))  return 1;

	return 0;
}


/** ==== Function Definitions ==== **/
//createStk():
//This function is used to create and initialize a stack with given values.

int createStk(int *arr, int n, int *top)
{
	int n1, i;
	
	//Checking edge cases:
	if(n < 1)
	{
		printf("The stack is empty!!\n\n");
		return 1;
	}
	
	printf("\nEnter how many values you want to enter: ");
	scanf("%d", &n1);

	printf("\nEnter the values: ");

	for(i=0;i<n1;i++)
	{
		scanf("%d", arr + i);
		*top = *top + 1;
	}
	
	printf("Successfully created the stack!!\n\n");

	return 0;
}


//display():
//This function displays the elements in the stack.
int display(int *arr, int n)
{
	int i;

	//Checking edge case:
	if(n < 1)
	{
		printf("No elements in the stack!!\n\n");
		return 1;
	}

	//Printing the elements from the stack:
	printf("\nThe elements in the stack are: \n\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t[ %d ]", *(arr + i));
		if(i != n-1)
		{
			printf("\n");
		}
	}
	printf("  ->  TOP\n");

	printf("\nSuccessfully printed the stack.\n\n");

	return 0;
}


//POP():
//This function pops out an element from the stack.

int POP(int *arr, int *top)
{
	//Checking if stack is empty:
	if(*top < 1)
	{
		printf("No elements in the stack can't pop!!\n\n");
		return 1;
	}

	//Popping an element from the stack:
	*top = *top - 1;

	printf("Successfully popped an element from the stack.\n\n");

	return 0;
}
