/** ===== Binary Tree : Inorder Traversal ===== **/


/** ===== Documentation ===== **/
/*
* This program shows the implementation of the Binary Tree.
* In this we do the following processes:
	* Creation of the Tree.
	* Initialization of the Tree with certain values.
	* Display the Tree by Inorder Traversal.
* Thus, we finally complete the implementation of the Tree.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),....
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *left;
	struct node *right;
};


/** ===== Function Prototypes ===== **/
struct node* createNode(int );
struct node* createTree(int *);
void freeTree(struct node *);
void Inorder(struct node *);


/** ===== Main Function ===== **/
int main()
{
	int n;

	printf("\nEnter the total no. of nodes in the Tree: ");
	scanf("%d", &n);

	//Creation of the Tree:
	printf("\nEnter values for the tree: ");
	struct node *root = createTree(&n);

	//Display the Tree:
	printf("\nThe Tree: \n");
	Inorder(root);

	//Free the allocated memory of the Tree:
	freeTree(root);  root = NULL;

	return 0;
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
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}


//createTree():
//This function initializes the Tree with user-provided values.

struct node* createTree(int *n)
{
	int data;

	if(*n <= 0)
	{
		return NULL;
	}

	scanf("%d", &data);

	struct node* root = createNode(data);
	
	int leftN = (*n-1)/2;
	int rightN = *n-1-leftN;

	root -> left = createTree(&leftN);
	root -> right = createTree(&rightN);

	return root;
}


//freeTree():
//This function frees the allocated memory.
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


//Inorder():
//This function displays all of the nodes and it's data of the Tree in Inorder fashion.

void Inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}	

	Inorder(root -> left);
	printf("%d ", root -> data);
	Inorder(root -> right);
}
