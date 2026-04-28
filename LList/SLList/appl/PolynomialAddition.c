/** ==== Applications of the Single Linked List: Polynomial Addition ==== **/


/** ==== Documentation ==== **/
/*
 * This program creates two linked lists p and q for the two polynomials.
 * Takes the values of the polynomial equations like coefficients and exponents from the user.
 * Adds the polynomial equations in two another polynomial equation r.
 * And, finally prints all of the polynomial equations p, q, r.
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>		//For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>	//For DMA functions like malloc(), free(),...


/** ==== Global Declarations ==== **/
/* ---- Node definition ---- **/
struct node {
	int coeff;
	int exp;
	struct node *next;
};


/** ==== Function Prototypes ==== **/
//Node Creation:
struct node *createNode(int, int);
int createList(struct node *, int);
int display(struct node *);
int PolyAdd(struct node *, struct node *, struct node *);

//Miscellaneous Functions:
char *OrdinalIndication(int);


/** ==== Main Function ==== **/
int main()
{
	int Pn, Qn;
	struct node *Phead = NULL, *Qhead = NULL, *Rhead = NULL;

	//Allocating Memory:
	Phead = malloc(sizeof(struct node));
	Qhead = malloc(sizeof(struct node));
	Rhead = malloc(sizeof(struct node));

	Phead -> next = NULL;
	Qhead -> next = NULL;
	Rhead -> next = NULL;

	//Checking if allocation failed:
	if(Phead == NULL || Qhead == NULL || Rhead == NULL)
	{
		printf("Memory allocation failed!!\n");

		return 1;
	}
	
	printf("\n ======= Polynomial addition ======== \n\n");
	printf("At first enter the values of the first polynomial equation: \n");
	printf("Enter the total no. of terms in the first polynomial: ");
	scanf("%d", &Pn);

	//Creating and initializing the first polynomial's list:
	if(createList(Phead, Pn))  return 1;

	printf("\nNow enter the values of the second polynomial equation: \n");
	printf("Enter the total no. of terms in the second polynomial: ");
	scanf("%d", &Qn);

	//Creating and initializing the second polynomial's list:
	if(createList(Qhead, Qn))  return 1;

	//Performing the Addition:
	if(PolyAdd(Phead, Qhead, Rhead)) return 1;

	//Displaying the polynomial equations:
	printf("\n==================\n\n");
	printf("The First Polynomial is: ");

	if(display(Phead)) return 1;

	printf("\n\n==================\n");
	printf("The Second Polynomial is: ");

	if(display(Qhead)) return 1;

	printf("\n\n=================\n");
	printf("The Resultant Polynomial is: ");

	if(display(Rhead)) return 1;

	return 0;
	
}


/** ==== Function Definitions: ==== **/
//createNode():
//This function is used to create and allocate memory for a node:

struct node *createNode(int coeff, int exp)
{
	struct node *newNode = malloc(sizeof(struct node));

	if(newNode == NULL)
	{
		printf("\nMemory allocation failed!!.");
		return NULL;
	}

	//Assiging the data values to the new node:
	newNode -> coeff = coeff;
	newNode -> exp = exp;
	newNode -> next = NULL;

	return newNode;
}


//display():
//This function traverses through the lists and displays all of the data.

int display(struct node *head)
{
	if(head -> next == NULL)
	{
		printf("Memory allocation failed!!\n\n");
		return 1;
	}

	struct node *temp = head -> next;
	while(temp != NULL)
	{
		printf("%dx^%d", temp -> coeff, temp -> exp);
		if(temp -> next != NULL)
		{
			printf(" + ");
		}

		temp = temp -> next;	
	}

	printf(" = 0\n\n");

	printf("Successfully printed the lists!!\n\n");

	return 0;
}


//createList():
//This function is used to create the single linked list with the user given values:

int createList(struct node *head, int n)
{
	int c, e, i;
	struct node *lastNode = NULL, *temp = NULL;

	//Checking edge cases:
	if(n < 1)
	{
		printf("Not enough nodes in the list!!.");
		return 1;
	}

	for(i=1;i<=n;i++)
	{
		printf("\nEnter %d%s term's coefficient: ", i, OrdinalIndication(i));
		scanf("%d", &c);
		printf("\nEnter %d%s term's exponent: ", i, OrdinalIndication(i));
		scanf("%d", &e);
		
		//Create newNode:
		struct node *new = createNode(c, e);

		//Linking the nodes together:
		if(head -> next == NULL)
		{
			head -> next = new;
		}
		else
		{
			lastNode -> next = new;
		}

		lastNode = new;
		temp = new;
	}

	if(temp -> next != NULL)
	{
		temp -> next = NULL;
	}

	return 0;
}


//PolyAdd():
//This function performs polynomial addition on two polynomial equations which were stored in the two linked lists and store the result equation in another polynomial.

int PolyAdd(struct node *P, struct node *Q, struct node *R)
{
	//Declaring required variables:
	struct node *Pptr = NULL, *Qptr = NULL, *Rptr = NULL;
	Pptr = P -> next;
	Qptr = Q -> next;
	Rptr = R;

	//Traversing through the lists and adding up the coefficients of the terms:
	while((Pptr != NULL) && (Qptr != NULL))
	{
		if((Pptr -> exp) == (Qptr -> exp))
		{
			struct node *new = createNode((Pptr -> coeff + Qptr -> coeff), Pptr -> exp);
			Pptr = Pptr -> next;
			Qptr = Qptr -> next;
			Rptr -> next = new;
			Rptr = new;
		}
		else if((Pptr -> exp) > (Qptr -> exp))
		{
			struct node *new = createNode(Pptr -> coeff, Pptr -> exp);
			Pptr = Pptr -> next;
			Rptr -> next = new;
			Rptr = new;
		}
		else
		{
			struct node *new = createNode(Qptr -> coeff, Qptr -> exp);
			Qptr = Qptr -> next;
			Rptr -> next = new;
			Rptr = new;
		}
	}

	if(Pptr != NULL)
	{
		while(Pptr != NULL)
		{
			struct node *new = createNode(Pptr -> coeff, Pptr -> exp);
			Rptr -> next = new;
			Rptr = new;
			Pptr = Pptr -> next;
		}
	}
	
	if(Qptr != NULL)
	{
		while(Qptr != NULL)
		{
			struct node *new = createNode(Qptr -> coeff, Qptr -> exp);
			Rptr -> next = new;
			Rptr = new;
			Qptr = Qptr -> next;
		}
	}

	return 0;
}


/* ---- Miscellaneous Functions ---- */
//OrdinalIndication():
//This function gives the ordinal indication of the number passed.

char *OrdinalIndication(int num)
{
	switch(num)
	{
		case 1:
			{
				return "st";
			}
		case 2:
			{
				return "nd";
			}
		case 3:
			{
				return "rd";
			}
		default:
			{
				return "th";
			}

	}
}
