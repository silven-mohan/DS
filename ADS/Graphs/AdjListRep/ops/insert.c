/** Graph Implementation: Adjacency List Representation **/

/*
 * This program shows the implementation of Graphs by using Adjacency List.
 * At first we allocate memory for an array of the graph pointer the no. of the graph pointers will be the no. of vertices of the graph.
 * Then, takes all of the values of the vertices of the graph.
 * Then associates edges between specified pair of vertices.
 * Prints the adjacency list.
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
struct graph *createGraph(int);
struct graph *insertVertex(struct graph *, int);
struct graph *insertEdge(int, int, struct graph *);
int printadjList(struct graph *);
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

	struct graph *G = createGraph(n);

	printf("\nEnter how many new vertices you want to enter : ");
	scanf("%d", &n);

	printf("\nEnter all of the values of the new vertices: ");
	for(i=0;i<n;i++)
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

	destroyGraph(G);

	return 0;
}


/** Function Definitions **/

struct graph *createGraph(int V)
{
	int i, Val;

	struct graph *G = malloc(sizeof(struct graph));

	if(G == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	G -> V = V;

	G -> vertices = malloc(V * sizeof(int));

	if(G -> vertices == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	G -> adjList = malloc(V * sizeof(struct node *));

	if(G -> adjList == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	printf("\nEnter the values for all of the %d vertices of the graph: ", V);
	for(i=0;i<V;i++)
	{
		scanf("%d", &Val);
		G -> vertices[i] = Val;
		G -> adjList[i] = createNode(Val);
	}

	return G;
}

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
