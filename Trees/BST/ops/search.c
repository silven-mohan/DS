/**==== Binary Search Trees: Implementation of the Search Operation ====**/

/*
 * This program creates a BST and initializes it with some values.
 * Displays the BST.
 * Searches for the specified node in the BST.
 * Displays the result.
*/


/** Preprocessing Directives **/
#include<stdio.h>   //For Basic I/O functions.
#include<stdlib.h>      //For DMA functions...


/** Global Declarations **/
/* Tree Node Defintion */
struct node {
    int data;
    struct node *left;
    struct node *right;
};


/* Function Prototypes */
struct node *createNode(int );
struct node *insert(struct node *, int);
struct node *createBST(int );
struct node *searchNode(struct node *, int);
void preorder(struct node *);
void freeTree(struct node *);


/** Main Function **/
int main()
{
    int n, item;

    printf("\nEnter the total no. of nodes of the BST: ");
    scanf("%d", &n);

    printf("\nEnter all of the values of the BST: ");
    struct node *root = createBST(n);

    printf("\nThe BST is: ");
    preorder(root);
    printf("\n\n");

    printf("\nEnter the value that is to be searched in the BST: ");
    scanf("%d", &item);
    struct node *temp = searchNode(root, item);

    if(temp == NULL)
    {
        printf("\nElement was not found in the BST.\n\n");
        return 1;
    }

    printf("\nElement was found in the BST.\n\n");

    freeTree(root);
    return 0;
}


/** Function Definitons **/
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


struct node *insert(struct node *root, int val)
{
    if(root == NULL)
    {
        return createNode(val);
    }

    if(val < root -> data)
    {
        root -> left = insert(root -> left, val);
    }
    else if(val > root -> data)
    {
        root -> right = insert(root -> right, val);
    }
    else
    {
        printf("\nValue already exists.\n\n");
        return NULL;
    }

    return root;
}


struct node *createBST(int n)
{
    int data;
    struct node *root = NULL;

    while(n--)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    return root;
}


struct node *searchNode(struct node *root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(val == root -> data)
    {
        return root;
    }
    else if(val > root -> data)
    {
        return searchNode(root -> right, val);
    }
    else
    {
        return searchNode(root -> left, val);
    }
}


void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}


void freeTree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root -> left);
    freeTree(root -> right);
    free(root);
}