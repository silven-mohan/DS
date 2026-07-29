/** ==== Binary Trees : Implementation and Level Order Traversal using Linked Lists ==== **/

#include<stdio.h>
#include<stdlib.h>

/** ==== Global Declarations ==== **/

/* Tree Node */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Queue Node */
struct nodeQ
{
    struct node *ptr;
    struct nodeQ *next;
};

struct nodeQ *FRONT = NULL;
struct nodeQ *REAR = NULL;

/* Function Prototypes */
struct node *createNode(int);
struct node *createTree(int *);
void levelorder(struct node *);

void enqueue(struct node *);
struct node *dequeue();

/* Main Function */

int main()
{
    int n;

    printf("Enter the total no. of values that are to be in the tree: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    struct node *root = createTree(&n);

    printf("\nLevel Order Traversal: ");
    levelorder(root);

    printf("\n");

    return 0;
}

/** ==== Function Definitions ==== **/

struct node *createNode(int val)
{
    struct node *new = malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }

    new->data = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct node *createTree(int *n)
{
    if(*n <= 0)
        return NULL;

    int data;
    scanf("%d", &data);

    struct node *root = createNode(data);

    if(root == NULL)
        return NULL;

    int leftN = (*n - 1) / 2;
    int rightN = (*n - 1) - leftN;

    root->left = createTree(&leftN);
    root->right = createTree(&rightN);

    return root;
}

void levelorder(struct node *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty!\n");
        return;
    }

    enqueue(root);

    while(FRONT != NULL)
    {
        struct node *current = dequeue();

        printf("%d ", current->data);

        if(current->left != NULL)
            enqueue(current->left);

        if(current->right != NULL)
            enqueue(current->right);
    }
}

void enqueue(struct node *temp)
{
    struct nodeQ *new = malloc(sizeof(struct nodeQ));

    if(new == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }

    new->ptr = temp;
    new->next = NULL;

    if(FRONT == NULL)
    {
        FRONT = REAR = new;
        return;
    }

    REAR->next = new;
    REAR = new;
}

struct node *dequeue()
{
    if(FRONT == NULL)
	{
        return NULL;
	}

    struct nodeQ *temp = FRONT;
    struct node *value = temp->ptr;

    FRONT = FRONT->next;

    if(FRONT == NULL)
        REAR = NULL;

    free(temp);

    return value;
}