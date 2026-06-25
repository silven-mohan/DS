/** ===== Circular Single Linked List: Node Insertion Implementation ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the Node Insertion operation on a Circular Single Linked List.
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


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};

struct node *header = NULL, *N = NULL, *new = NULL;		//Declaraing here for global access.
int n;


/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void createList(int n);
void freeList(void);
int display(struct node *);
int insertMain(void);
int insertFront(void);
int insertPos(void);
int insertEnd(void);



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

	printf("\nEnter the no. of nodes of the list: ");
	scanf("%d", &n);
	if(n < 1)
	{
		printf("\nInsufficient nodes to create a list!!\n\n");
		status = 1;
		goto cleanup;
	}

	printf("\nEnter the data of all of the nodes: ");
	createList(n);
	if(header->next == NULL)
	{
		status = 1;
		goto cleanup;
	}
	printf("\nThe List is : ");
	if(display(header))
	{
		status = 1;
		goto cleanup;
	}
	if(insertMain())
	{
		status = 1;
	}

	cleanup:
	//Free the memory:
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

	printf("\nSuccessfully initialized all the nodes with data.\n\n");
}

void freeList(void)
{
	if(header->next == NULL)
	{
		new = NULL;
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
	new = NULL;
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


//insertMain():
//This function created the new node that is to be inserted and determines where it should be inserted(front, end, or any other position)

int insertMain()
{
	int choice;

	//Creating the new node that is to be inserted:	
	printf("\nEnter the data value of the new node that is to be inserted: ");
	int newValue;
	scanf("%d", &newValue);
	new = createNode(newValue);
	if(new == NULL) return 1;
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
	if(display(header))  return 1;

	return 0;
}


//insertFront():
//This function inserts a node the front of the list.

int insertFront()
{
	struct node *temp = NULL;

	if(header -> next == NULL)
	{
		header -> next = new;
		new -> next = new;
		return 0;
	}

	temp = header -> next;

	//Linking the new node to the header node.
	header -> next = new;

	//Linking the list to the new node that is inserted at the front position.
	new->next = temp;

	//Traversing upto the last node to link the last node to the first one.
	temp = header -> next;

	do
	{
		temp = temp -> next;
	}while(temp -> next != header -> next);
	

	temp -> next = header -> next;

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

	temp = header -> next;

	while(temp -> next != header -> next && j < pos)
	{
		prev = temp;
		temp = temp -> next;
		j += 1;
	}
	
	//Linking the new node to the node befor position 'pos':
	prev -> next = new;

	//Linking the nodes from the position 'pos' to the the new node:
	new->next = temp;

	//Display the modified list:
	if(display(header))  return 1;

	return 0;
}


//insertEnd():
//This function inserts a node at the end of the list.

int insertEnd()
{
	struct node *temp = NULL;

	temp = header -> next;


	//Traversing till the last node:
	do 
	{
		temp = temp -> next;
	}while(temp -> next != header -> next);

	//Inserting the node at the end:
	temp -> next = new;
	new->next = header -> next;

	return 0;
		
}
