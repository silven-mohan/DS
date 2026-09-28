/* Graph : Adjacency Matrix Representation */


/*
 * This program creates a graph.
 * Inserts, the vertices into the graph.
 * Associates, the edges between the specified vertices.
 * Prints the adjacency matrix of the graph.
 * Deletes, an edge between the specified the vertices.
 * Deletes a vertex of the graph.
*/


/* Preprocessing Directives */
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), realloc(), calloc(), free(),....


/* Global Declarations */
/*- Graph Structure -*/
typedef struct {
	int V;
	int *vertices;
	int **adjMatrix;
} Graph;


/*- Function Prototypes -*/
Graph *createGraph(int);
Graph *insertVertex(Graph *, int);
Graph *insertEdge(Graph *, int, int);
void printGraph(Graph *);
void destroyGraph(Graph *);
Graph *deleteEdge(Graph *, int, int);
Graph *deleteVertex(Graph *, int);



/* Main Function */
int main()
{
	int i, n, V1, V2;

	printf("\nEnter the total no. of vertices: ");
	scanf("%d", &n);

	Graph *g = createGraph(n);

	printGraph(g);
	
	printf("\nEnter how many new vertices you want to insert in the graph: ");
	scanf("%d", &n);

	printf("\nEnter the values of the vertices: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &V1);
		g = insertVertex(g, V1);
	}

	printGraph(g);	

	printf("\nEnter for how many pairs of the vertices you want to associate an edge: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter the vertices V1, V2: ");
		scanf("%d%d", &V1, &V2);
		g = insertEdge(g, V1, V2);
	}

	printGraph(g);
	

	printf("\nEnter for how many pairs of the vertices you want to delete an edge: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter the vertices V1, V2: ");
		scanf("%d%d", &V1, &V2);
		g = deleteEdge(g, V1, V2);
	}

	printGraph(g);

	destroyGraph(g);

	return 0;
}


/* Function Definitions */

Graph *createGraph(int V)
{
	int i;
	Graph *g = malloc(sizeof(Graph));

	if(g == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	g -> V = V;
	g -> vertices = NULL;
	g -> adjMatrix = NULL;

	g -> vertices = malloc(V * sizeof(int));

	if(g -> vertices == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	g -> adjMatrix = calloc(V, sizeof(int *));

	if(g -> adjMatrix == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	for(i=0;i<(g -> V);i++)
	{
		g -> adjMatrix[i] = calloc(V, sizeof(int));

		if(g -> adjMatrix[i] == NULL)
		{
			printf("\nMemory allocation failed!!\n\n");
			return NULL;
		}
	}

	printf("\nEnter all of the vertices of the graph: ");
	for(i=0;i<(g -> V);i++)
	{
		scanf("%d", &(g ->vertices[i]));
	}

	return g;
}


Graph *insertVertex(Graph *g, int V)
{
	int i;

	//Reallocate memory for the vertices array:
	int *tempvertices = realloc(g -> vertices, (g -> V + 1) * sizeof(int));

	if(tempvertices == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return g;
	}

	g -> vertices = tempvertices;
	g -> vertices[g->V] = V;


	//Allocate memory for a new row pointer in the adjMatrix:
	int **tempMatrix = realloc(g -> adjMatrix, (g -> V + 1)*sizeof(int *));

	if(tempMatrix == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return g;
	}

	g -> adjMatrix = tempMatrix;

	//Reallocate a new column for all of the existing rows:
	for(i=0;i<(g->V);i++)
	{
		int *tempRow = realloc(g->adjMatrix[i], (g -> V + 1) * sizeof(int));

		if(tempRow == NULL)
		{
			printf("\nMemory allocation failed!!\n\n");
			return g;
		}

		g -> adjMatrix[i] = tempRow;
		g -> adjMatrix[i][g -> V] = 0;
	}

	//For new pointer allocate memory:
	g -> adjMatrix[g -> V] = calloc((g -> V + 1), sizeof(int));

	if(g -> adjMatrix[g -> V] == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return g;
	}
	(g -> V)++;

	return g;
}


Graph *insertEdge(Graph *g, int V1, int V2)
{
	int i, V1i = -1, V2i = -1;

	if(V1 == V2)
	{
		printf("\nSelf Looping isnt allowed!!\n\n");
		return g;
	}

	for(i=0;i<(g->V);i++)
	{
		if(g->vertices[i] == V1)
		{
			V1i = i;
			break;
		}
	}

	for(i=0;i<(g->V);i++)
	{
		if(g->vertices[i] == V2)
		{
			V2i = i;
			break;
		}
	}

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex not found.\n\n");
		return g;
	}

	g -> adjMatrix[V1i][V2i] = 1;
	g -> adjMatrix[V2i][V1i] = 1;

	return g;
}



void printGraph(Graph *g)
{
    int i, j;
    if(g -> V <= 0)
    {
        printf("\nGraph is empty!!\n\n");
        return;
    }
    printf("\n\nGraph - Adjacency Representation");
    printf("\n======================================\n\n  ");

    for(i=0;i<g -> V;i++)
    {
        printf("%d  ", g -> vertices[i]);
    }
    printf("\n");
    for(i=0;i<g->V;i++)
    {
        printf("%d ", g -> vertices[i]);
        for(j=0;j<g->V;j++)
        {
            printf("%d  ", g -> adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n======================================\n\n");
}


Graph *deleteEdge(Graph *g, int V1, int V2)
{
	int i, V1i = -1, V2i = -1;

	for(i=0;i<(g -> V);i++)
	{
		if(g -> vertices[i] == V1)
		{
			V1i =i;
		}
	}

	for(i=0;i<(g -> V);i++)
	{
		if(g -> vertices[i] == V2)
		{
			V2i = i;
		}
	}

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex found.\n\n");
		return g;
	}

	g -> adjMatrix[V1i][V2i] = 0;
	g -> adjMatrix[V2i][V1i] = 0;

	return g;
}


Graph *deleteVertex(Graph *G, int V)
{
	int i, j, Vi = -1;

	if(G == NULL)
	{
		printf("\nGraph doesn't exist!!\n\n");
		return NULL;
	}

	// Find the index of the vertex to be deleted:
	for(i = 0; i < G->V; i++)
	{
		if(G->vertices[i] == V)
		{
			Vi = i;
			break;
		}
	}

	if(Vi == -1)
	{
		printf("\nVertex not found.\n\n");
		return G;
	}

	
	//Shift the vertices after Vi one position to the left.
	for(i = Vi; i < G->V - 1; i++)
	{
		G->vertices[i] = G->vertices[i + 1];
	}

	
	//Remove the column Vi from every row.
	for(i = 0; i < G->V; i++)
	{
		for(j = Vi; j < G->V - 1; j++)
		{
			G->adjMatrix[i][j] = G->adjMatrix[i][j + 1];
		}
	}

	
	//Free the row corresponding to the deleted vertex.
	free(G->adjMatrix[Vi]);

	
	//Shift the remaining row pointers one position up.
	for(i = Vi; i < G->V - 1; i++)
	{
		G->adjMatrix[i] = G->adjMatrix[i + 1];
	}

	
	G->V--;

	
	//Resize the vertices array.
	int *tempVertices = realloc(G->vertices, G->V * sizeof(int));

	if(G->V > 0 && tempVertices == NULL)
	{
		printf("\nMemory reallocation failed!!\n\n");
		return G;
	}

	G->vertices = tempVertices;

	
	//Resize the array of row pointers.
	int **tempMatrix = realloc(G->adjMatrix, G->V * sizeof(int *));

	if(G->V > 0 && tempMatrix == NULL)
	{
		printf("\nMemory reallocation failed!!\n\n");
		return G;
	}

	G->adjMatrix = tempMatrix;

	
	//Resize every remaining row.
	for(i = 0; i < G->V; i++)
	{
		int *tempRow = realloc(G->adjMatrix[i],
							   G->V * sizeof(int));

		if(G->V > 0 && tempRow == NULL)
		{
			printf("\nMemory reallocation failed!!\n\n");
			return G;
		}

		G->adjMatrix[i] = tempRow;
	}

	return G;
}


void destroyGraph(Graph *G)
{
	int i;

	if(G == NULL)
	{
		printf("\nGraph doesn't exist!!\n\n");
		return;
	}

	//Free vertices array:
	free(G -> vertices);

	//Free the adjacency matrix:
	for(i = 0;i<G -> V;i++)
	{
		if(G -> adjMatrix[i] != NULL)
		{
			free(G -> adjMatrix[i]);
		}
	}

	free(G -> adjMatrix);
	free(G);
}	
