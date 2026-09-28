/* Graphs : Implementation by using Adjacency Matrix */

/*
 * This program takes the total no. of vertices from the user V.
 * And, creates a V x V matrix with all zeroes.
 * Creates another array to store the V no. of vertices of the graph.
 * Inserts all of the vertices to the graph and associates connections between them.
 * Finally, prints the graph.
 */


/* Preprocessing Directives */
#include<stdio.h>       //For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>  //For DMA functions like malloc(), free(),...


/* Global Declarations */
/*- Graph Structure -*/
typedef struct {
    int V;
    int *vertices;
    int **adjMatrix;
} Graph;


/*- Function Prototypes -*/

//Graph *createGraph(int );
void GraphMain();
Graph *insertVertex(Graph *, int );
Graph *insertEdge(Graph *, int, int);
Graph *deleteEdge(Graph *, int, int);
Graph *deleteVertex(Graph *, int);
void destroyGraph(Graph *);
void printGraph(Graph *);


/* Main Function */

int main()
{
	GraphMain();

	return 0;
}


void GraphMain()
{
	char ch;
	int i, n, v, v1, choice;

	Graph *G = malloc(sizeof(Graph));
	G -> V = 0;
    	G -> vertices = NULL;
    	G -> adjMatrix = NULL;

	//Menu:
	do
	{
		printf("\n ===== Graph Implementation: Using Adjacency Matrix\n\n");
		printf("\n1. Insert a vertex,\n2. Insert an edge,\n3. Delete an Edge,\n4. Delete a Vertex,\n5. Show Adjacency List,\n6. Exit.\n\n");
		printf("Choose: ");
		
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter the value of the vertex: ");
				scanf("%d", &v);

				G = insertVertex(G, v);
				printGraph(G);
				break;

			case 2:
				printf("\nEnter the pair between which the edge should be associated: ");
				scanf("%d%d", &v, &v1);

				G = insertEdge(G, v, v1);
				printGraph(G);
				break;
			
			case 3:
				printf("\nEnter the pair between which the edge should be deleted: ");
				scanf("%d%d", &v, &v1);

				G = deleteEdge(G, v, v1);
				printGraph(G);
				break;

			case 4:
				printf("\nEnter the vertex that is to be deleted: ");
				scanf("%d", &v);

				G = deleteVertex(G, v);
				printGraph(G);
				break;
			case 5:
				printGraph(G);
				break;
			case 6:
				printf("\n ....... Exit .......\n\n");
				return;
			default:
				printf("\nInvalid option!!\n\n");
		}

		printf("\nDo you want to continue(Y/n)?");
		scanf(" %c", &ch);
	}while(ch == 'Y' || ch == 'y');

	destroyGraph(G);

}


/* Function Definitions */

Graph *insertVertex(Graph *g, int val)
{
    int i;

    //Increase memory of vertices array by another element:
    int *tempVertices = realloc(g -> vertices, (g -> V + 1) * sizeof(int));

    if(tempVertices == NULL)
    {
        printf("\nMemoery allocation failed!!\n\n");
        return g;
    }

    g -> vertices = tempVertices;
    g -> vertices[g->V] = val;

    //Allocate memory for another row pointer
    int **tempMatrix = realloc(g -> adjMatrix, (g -> V + 1) * sizeof(int *));

    if(tempMatrix == NULL)
    {
        printf("\nMemory allocation failed!!\n\n");
        return g;
    }

    g -> adjMatrix = tempMatrix;

    //Allocate new column for each row:
    for(i=0;i<(g -> V);i++)
    {
        int *tempRow = g -> adjMatrix[i];

        tempRow = realloc(g -> adjMatrix[i], (g -> V + 1) * sizeof(int));

        if(tempRow == NULL)
        {
            printf("\nMemory allocation failed!!\n\n");
            return g;
        }

        g -> adjMatrix[i] = tempRow;
        g -> adjMatrix[i][g->V] = 0;
    }

    //Allocate memory for all the entries of new row:
    g -> adjMatrix[g->V] = calloc(g->V+1, sizeof(int));

    if(g -> adjMatrix[g->V] == NULL)
    {
        printf("\nMemory allocation failed!!\n\n");
        return g;
    }

    g -> V++;
    return g;
}


Graph *insertEdge(Graph *g, int V1, int V2)
{
    int V1i = -1, V2i = -1, i;

    if(V1 == V2)
    {
        printf("\nSelf Loopinf isn't allowed!!\n\n");
        return g;
    }

    for(i=0;i<(g->V);i++)
    {
        if(g -> vertices[i] == V1)
        {
            V1i = i;
            break;
        }
    }

    for(i=0;i<(g->V);i++)
    {
        if(g -> vertices[i] == V2)
        {
            V2i = i;
            break;
        }
    }

    if((V1i == -1 || V2i == -1) || (V1i > g -> V || V2i > g -> V))
    {
        printf("\nVertex not found!!\n\n");
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
