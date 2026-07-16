/** ==== Binary Trees : Implementation and level order traversal using linked lists ==== **/


/*
 * This program takes no. of nodes that should be in the tree n.
 * Creates a tree using linked lists with user given values.
 * Displays all nodes of the tree by using level order traversal technique.
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>		//For DMA functions like malloc(), free(),...


/** ==== Global Declarations ==== **/
/* --- Tree's Node Definition --- */
struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct nodeQ {
	int data;
	struct nodeQ *next;
};

struct nodeQ *FRONT = NULL, *REAR = NULL;


/* --- Function Prototypes --- */
struct node *createNode(int);
struct node *createTree(int *);
void levelorder(struct node *);
void enqueue(int);
int dequeue();


/** ==== Main Function ==== **/
int main()
{
	int n;

	printf("\nEnter the total no. of values that are to be in the tree: ");
	scanf("%d", &n);

	//Creating the Tree:
	struct node *root = createTree(&n);

	//Displaying the tree:
	printf("\nLevel Order Traversal: ");
	levelorder(root);

	return 0;
}


/** ==== Function Definitions ==== **/
//createNode():
//This helper funtion is used to create a node with the given value.

struct node *createNode(int val)
{
	struct node *new = malloc(sizeof(struct node));

	//Handling error case:
	if(new == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	new -> data = val;
	new -> left = NULL;
	new -> right = NULL;

	return new;
}


//createTree():
//This helper function is used to create the tree with the given values.

struct node *createTree(int *n)
{
	int data;

	if(*n <=0)
	{
		return NULL;
	}

	scanf("%d", &data);
	struct node *root = createNode(data);

	int leftN = (*n-1)/2;
	int rightN = (*n-1) - leftN;

	root -> left = createTree(&leftN);
	root -> right = createTree(&rightN);

	return root;
}


//levelorder():
//This helper function shows the implementation of the level order traversal of the binary tree:

void levelorder(struct node *root)
{
	if(root == NULL)
	{
		printf("\nTree is empty!!\n\n");
		return;
	}

	enqueue(root -> data);
	
	while(FRONT -> next != NULL && REAR -> next != NULL)
	{
		printf("%d ", dequeue());

		if(root -> left != NULL)
		{
			enqueue(root -> left -> data);
		}

		if(root -> right != NULL)
		{
			enqueue(root -> right -> data);
		}
	}
}


//enqueue():
//This helper function inserts an element to the queue.

void enqueue(int val)
{
	struct nodeQ *new = malloc(sizeof(struct nodeQ));

	if(new == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return;
	}
	new -> data = val;
	new -> next = NULL;

	if(FRONT == NULL || REAR == NULL)
	{
		FRONT = malloc(sizeof(struct nodeQ)), REAR = malloc(sizeof(struct nodeQ));

		if(FRONT == NULL || REAR == NULL)
		{
			printf("\nMemory allocation failed!!\n\n");
			return;
		}

		FRONT -> next = new, REAR -> next = new;
		return;
	}	
	
	if(FRONT -> next == NULL && REAR -> next == NULL)
	{
		FRONT -> next = new, REAR -> next = new;
		return;
	}
	
	REAR -> next -> next = new;
	REAR -> next = new;
}


//dequeue():
//This helper function deletes an element from the queue.

int dequeue()
{
	if(FRONT == NULL || REAR == NULL)
	{
		printf("\nQueue is empty!!.\n");
		return -1;
	}

	struct nodeQ *temp = FRONT -> next;
	
	if(FRONT -> next == REAR -> next)
	{
		REAR -> next = NULL;
	}

	FRONT -> next = FRONT -> next -> next;

	int val = temp -> data;

	free(temp);

	return val;
}
