/* Graphs : Implementation of the Insertion of edge operation */


/* 
 * This program creates a graph.
 * And, takes specified no. of vertices and their values from the user.
 * And, do the implementation of the graph with the taken values using Adjacency List Representation.
 * Inserts a new edge between the specified edges.
*/


/* Preprocessing Directives */
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),..
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/* Global Declarations */
// -- Node Defintion --
struct node {
	int data;
	struct node *next;
};

// -- Graph Node Definition --
struct graph {
	int vertices;
	struct node **adjList;
};


// -- Function Protottypes --
struct node *createNode(int);
struct graph *createGraph(int );
struct graph *insertVertex(int, struct graph*);
struct graph *insertEdge(struct graph*);
int printAdjList(struct graph*);
void destroyGraph(struct graph *);



/* Main Function */
int main()
{
	int n, i;

	//Taking the no. of vertices:
	printf("\nEnter the total no. of vertices of the graph: ");
	scanf("%d", &n);

	//Creating the Graph:
	struct graph *Graph = createGraph(n);

	//Printing the adjacency list of the graph:
	printAdjList(Graph);

	//Establishing the connections between the vertices of the graph:
	for(i=0;i<3;i++)
	{
		Graph = insertEdge(Graph);
	}

	//Print the modified graph:
	printAdjList(Graph);

	//Destory Graph:
	destroyGraph(Graph);

	return 0;
}


/* Function Definitions */

//createNode():
//This helper function creates the node with given value.

struct node* createNode(int value)
{
	struct node* newNode = malloc(sizeof(struct node));

	//Checking errors:
	if(newNode == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	newNode -> data = value;
	newNode -> next = NULL;

	return newNode;
}


//createGraph():
//This helper function creates the graph and returns the created graph.

struct graph *createGraph(int vertices)
{
	int i;
	//Allocating memory for the Graph:
	struct graph *Graph = malloc(sizeof(struct graph));

	//Checking for errors:
	if(Graph == NULL)
	{
		printf("\nMemory allocation failed for the Graph!!\n\n");
		return NULL;
	}

	Graph -> vertices = vertices;

	Graph -> adjList = malloc(vertices * sizeof(struct node *));

	//Again Checking for errors:
	if(Graph -> adjList == NULL)
	{
		printf("\nMemory allocation failed for the adjacency list!!\n\n");
		return NULL;
	}

	//First init adjList of the Graph to NULL and read vertices:
	printf("\nEnter all of the values of the graph: ");
	for(i=0;i<vertices;i++)
	{
		Graph -> adjList[i] = NULL;
		Graph = insertVertex(i, Graph);
	}

	return Graph;
}


//insertVertex():
//This helper function inserts the vertex to the graph(Adjacency List).

struct graph *insertVertex(int vIndex, struct graph* Graph)
{
	int vertex;

	scanf("%d", &vertex);
	 
	struct node *vertexNode = createNode(vertex);
	Graph -> adjList[vIndex] = vertexNode;

	return Graph;
}


//printAdjList():
//This helper function prints the adjaceny list representation of the Graph.

int printAdjList(struct graph *Graph)
{
	int i;

	printf("\n=== Graph : Adjacency List ===\n\n");
	for(i=0;i<(Graph -> vertices);i++)
	{
		struct node *temp = Graph -> adjList[i];

		printf("%d : ", temp -> data);
		while(temp != NULL)
		{
			printf("%d -> ", temp -> data);

			if(temp -> next == NULL)
			{
				printf("\b\b\b  \n");
			}

			temp = temp -> next;
		}
	}
	printf("\n==============================\n\n");

	return 0;
}


//insertEdge():
//This helper function creates an association between two specified indexes.

struct graph *insertEdge(struct graph *Graph)
{
	int V1, V2, i, V1i = -1, V2i = -1;
	
	printf("\nEnter the vertices V1 & V2 between which an association must be established: ");
	scanf("%d%d", &V1, &V2);

	for(i=0;i<(Graph -> vertices);i++)
	{
		V1i = -1;
		if(V1 == Graph -> adjList[i] -> data)
		{
			V1i = i;
			break;
		}
	}

	for(i=0;i<(Graph -> vertices);i++)
	{
		V2i = -1;
		if(V2 == Graph -> adjList[i] -> data)
		{
			V2i = i;
			break;
		}
	}

	if((V1i == -1) || (V2i == -1))
	{
		printf("\nVertex Not found!\n");
		return Graph;
	}

	//Adjacency to V1:
	struct node* newV2 = createNode(V2);
	struct node *temp1 = Graph -> adjList[V1i];
	while(temp1 -> next != NULL)
	{
		temp1 = temp1 -> next;
	}
	temp1 -> next = newV2;

	//Adjacency to V2:
	struct node* newV1 = createNode(V1);
	struct node *temp2 = Graph -> adjList[V2i];
	while(temp2 -> next != NULL)
	{
		temp2 = temp2 -> next;	
	}
	temp2 -> next = newV1;

	return Graph;
	
}


void destroyGraph(struct graph *Graph)
{
    int i;
    if(Graph == NULL)
    {
        printf("\nGraph doesn't exist!!\n\n");
        return;
    }

    for(i = 0; i < (Graph->vertices); i++)
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