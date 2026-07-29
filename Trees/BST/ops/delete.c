/**==== Binary Search Trees: Implementation of the Deletion Operation ====**/

/*
 * This program creates a BST and initializes it with some values.
 * Displays the BST.
 * Deletes the specified node in the BST.
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
struct node *findMin(struct node *);
struct node *deleteNode(struct node *, int );
void postorder(struct node *);
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
    postorder(root);
    printf("\n\n");

    printf("\nEnter the value that is to be deleted from the BST: ");
    scanf("%d", &item);
    root = deleteNode(root, item);

    printf("\nModified BST: ");
    postorder(root);
    printf("\n\n");

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


struct node *findMin(struct node *root)
{
    while(root -> left != NULL)
    {
        root = root -> left;
    }

    return root;
}

struct node *deleteNode(struct node *root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(val < root -> data)
    {
        root -> left = deleteNode(root -> left, val);
    }
    else if(val > root -> data)
    {
        root -> right = deleteNode(root -> right, val);
    }
    else
    {
        if(root -> left == NULL)
        {
            struct node *temp = root -> right;
            free(root);
            return temp;
        }
        if(root -> right == NULL)
        {
            struct node *temp = root -> left;
            free(root);
            return temp;
        }
        
        struct node *temp = findMin(root -> right);

        root -> data = temp -> data;

        root -> right = deleteNode(root -> right, temp -> data);
    }

    return root;
}


void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> data);

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