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
Graph *insertVertex(Graph *, int );
Graph *insertEdge(Graph *, int, int);
void destroyGraph(Graph *);
void printGraph(Graph *);


/* Main Function */
int main()
{
    int i, n, value, value2;

    printf("\nEnter the total no. of vertices of the graph: ");
    scanf("%d", &n);

    Graph *g = malloc(sizeof(Graph));
    g -> V = 0;
    g -> vertices = NULL;
    g -> adjMatrix = NULL;

    printf("\nEnter the values of the vertices: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &value);
        g = insertVertex(g, value);
    }

    printGraph(g);

    printf("\nFor how many pairs of vertices of the graph you want to associate an edge: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the vertices V1 & V2: ");
        scanf("%d%d", &value, &value2);

        g = insertEdge(g, value, value2);
    }

    printGraph(g);

    //free the graph:
    destroyGraph(g);

    return 0;
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
