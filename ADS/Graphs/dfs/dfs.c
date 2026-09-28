/** Graph Implementation: Adjacency List Representation Breadth First Search(BFS) **/

/*
 * This program shows the implementation of Graphs by using Adjacency List.
 * At first we allocate memory for an array of the graph pointer the no. of the graph pointers will be the no. of vertices of the graph.
 * Then, takes all of the values of the vertices of the graph.
 * Then associates edges between specified pair of vertices.
 * Prints the adjacency list.
 * Performs Depth First Search on the graph and prints the output.
*/


/** Preprocessing Directives **/
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free(),...


/** Global Declarations **/
/*- Node definiton -*/
struct node {
	int data;
	struct node *next;
};

/*- Graph pointer definiton -*/
struct graph {
	int V;
	int *vertices;
	struct node **adjList;
};


/** Function Prototypes **/
struct graph *insertVertex(struct graph *, int);
struct graph *insertEdge(int, int, struct graph *);
int printadjList(struct graph *);
void DFS(struct graph *);
void push(struct node **, int);
int pop(struct node **);
void destroyGraph(struct graph *);


/*- Miscellaneous Functions -*/
struct node *createNode(int);
int search(int *, int, int);
struct node *insert_SL_end(int, struct node *);


/** Main Function **/
int main()
{
	int i, n, v, v1;

	printf("\nEnter the total no. of the vertices of the graph: ");
	scanf("%d", &n);

	struct graph *G = malloc(sizeof(struct graph));
	G -> V = 0;
	G -> vertices = NULL;
	G -> adjList = NULL;

	printf("\nEnter all of the vertices: ");
	for(i = 0;i < n;i++)
	{
		scanf("%d", &v);
		G = insertVertex(G, v);
	}

	if(printadjList(G))	return 1;
	printf("\nFor how many pairs of the vertices you want to associate an edge: ");
	scanf("%d", &n);
	
	printf("\nEnter the pairs of vertices: ");
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &v, &v1);
		G = insertEdge(v, v1, G);
	}

	if(printadjList(G))	return 1;

	DFS(G);

	destroyGraph(G);

	return 0;
}


/** Function Definitions **/

struct graph *insertVertex(struct graph *G, int V)
{
	int *temp = realloc(G -> vertices, (G -> V + 1) * sizeof(int));
	if(temp == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return G;
	}

	temp[G -> V] = V;
	G -> vertices = temp;

	struct node **tempList = realloc(G -> adjList, (G -> V + 1) * sizeof(struct node));
	if(tempList == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return G;
	}

	tempList[G -> V] = createNode(V);
	G -> adjList = tempList;
	G -> V++;

	return G;
}


struct graph *insertEdge(int V1, int V2, struct graph *G)
{
	int V1i, V2i;

	V1i = search(G -> vertices, V1, G -> V);
	V2i = search(G -> vertices, V2, G -> V);

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex not found!!\n\n");
		return G;
	}
	
	G -> adjList[V1i] = insert_SL_end(V2, G -> adjList[V1i]);
	G -> adjList[V2i] = insert_SL_end(V1, G -> adjList[V2i]);

	return G;
}


void destroyGraph(struct graph *Graph)
{
    int i;
    if(Graph == NULL)
    {
        printf("\nGraph doesn't exist!!\n\n");
        return;
    }

    for(i = 0; i < (Graph->V); i++)
    {
        struct node *temp = Graph->adjList[i];

        while(temp != NULL)
        {
            struct node *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(Graph->adjList);
    free(Graph);
}


int printadjList(struct graph *G)
{
	int i;

	if(G == NULL)
	{
		printf("\nGraph is empty!!\n\n");
		return 1;
	}
	
	printf("\n\n ===== Adjacency List of the Graph =====");
	for(i = 0;i<(G -> V);i++)
	{
		struct node *temp = G -> adjList[i];
		printf("\n  [%d] : ", temp -> data);
		while(temp != NULL)
		{
			printf("[%d] -> ", temp -> data);

			if(temp -> next == NULL)
			{
				printf("[NULL]");
			}

			temp = temp -> next;
		}
	}
	printf("\n----------------------------------------\n\n");

	return 0;
}



void DFS(struct graph *G)
{
    if(G == NULL)
    {
        printf("\nGraph is empty: Depth first search is not possible\n\n");
        return;
    }

    struct node *STACK = NULL;
    int visited[G->V];
    int i, V, index;

    for(i = 0; i < G->V; i++)
    {
        visited[i] = 0;
    }

    push(&STACK, G->vertices[0]);
    printf("\n===== Depth First Search =====\n");

    printf("DFS : ");

    while(STACK != NULL)
    {
        V = pop(&STACK);
        index = search(G->vertices, V, G->V);

        if(index == -1)
            continue;

        if(visited[index] == 1)
            continue;

        visited[index] = 1;
        printf("[%d] ", V);
        struct node *ptr = G->adjList[index]->next;

        while(ptr != NULL)
        {
            int adjIndex;
            adjIndex = search(G->vertices, ptr->data, G->V);

            if(adjIndex != -1 && visited[adjIndex] == 0)
            {
                push(&STACK, ptr->data);
            }
            ptr = ptr->next;
        }
    }
    printf("\n================================\n\n");
}



struct node *createNode(int val)
{
	struct node *newNode = malloc(sizeof(struct node));

	if(newNode == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	newNode -> data = val;
	newNode -> next = NULL;

	return newNode;
}


int search(int *X, int V, int n)
{
	int i;
	for(i =0;i<n;i++)
	{
		if(X[i] == V)
		{
			return i;
		}
	}

	return -1;
}

struct node *insert_SL_end(int V, struct node *adjList)
{
	struct node *temp = adjList;

	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}

	temp -> next = createNode(V);

	return adjList;
}


void push(struct node **top, int V)
{
    struct node *newNode = createNode(V);

    if(newNode == NULL)
        return;

    newNode->next = *top;
    *top = newNode;
}


int pop(struct node **top)
{
    if(*top == NULL)
    {
        printf("\nStack is empty!!\n");

        return -1;
    }

    struct node *temp = *top;
    int V = temp->data;

    *top = (*top)->next;
    free(temp);

    return V;
}
