/** ==== Binary Search Tree : Implementation of the insertion operation on BSTs implemented using linked lists ==== **/


/*
 * This program creates a binary search tree with a specified no. of nodes and values given by the user.
 * Then, displays the binary search tree.
 * And, inserts a new node into the bst and displays the modified tree.
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(), ...
#include<stdlib.h>		//For DMA functions like malloc(), free(),...


/** ==== Global Declarations ==== **/
/*--- Node Definition ---*/
struct node {
	int data;
	struct node *left;
	struct node *right;
};


/*--- Function Prototypes ---*/
struct node *createNode(int);
struct node *insert(struct node *, int);
struct node *createBST(int);
void inorder(struct node *);
void freeTree(struct node *);


/** ==== Main Function ==== **/
int main()
{
	int n;

	printf("\nEnter the total no. of nodes in the BST: ");
	scanf("%d", &n);

	//Creating the BST:
	printf("\nEnter the values: ");
	struct node *root = createBST(n);

	//Displaying the tree:
	printf("\nBinary Search Tree: ");
	inorder(root);
	printf("\n\n");

	//free the allocated memory:
	freeTree(root);

	return 0;
}


/** ==== Function Definitions ==== **/
//createNode():
//This helper function is used to create node with a given value.

struct node *createNode(int val)
{
	struct node *new = malloc(sizeof(struct node));

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


//insert():
//This helper function inserts a node at appropriate position in the bst.

struct node *insert(struct node *root, int val)
{
	if(root == NULL)
	{
		return createNode(val);
	}

	if(val < (root -> data))
	{
		root -> left = insert(root -> left, val);
	}
	else if(val > (root -> data))
	{
		root -> right = insert(root -> right, val);
	}
	else
	{
		printf("\nNode already exists!!\n\n");
		return NULL;
	}

	return root;
}


//createTree():
//This helper function creates a bst.

struct node *createBST(int n)
{
	struct node *root = NULL;
	int value;

	while(n--)
	{
		scanf("%d", &value);
		root = insert(root, value);
	}

	return root;
}

//inorder():
//This helper function displays the values of the BST by traversing.

void inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root -> left);
	printf("%d ", root -> data);
	inorder(root -> right);
}


//freeTree():
//This helper function frees the allocated memory for the tree.

void freeTree(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	freeTree(root -> left);
	freeTree(root -> right);

	free(root);
}
