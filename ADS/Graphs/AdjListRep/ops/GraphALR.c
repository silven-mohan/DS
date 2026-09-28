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
//struct graph *createGraph(int);
struct graph *insertVertex(struct graph *, int);
struct graph *insertEdge(int, int, struct graph *);
struct graph *deleteEdge(int, int, struct graph *);
struct graph *deleteVertex(struct graph *, int);
int printadjList(struct graph *);
void destroyGraph(struct graph *);


/*- Miscellaneous Functions -*/
void GraphMain();
struct node *createNode(int);
int search(int *, int, int);
struct node *insert_SL_end(int, struct node *);
int delete_SL_any(int, struct node *);


/** Main Function **/

int main()
{
	GraphMain();

	return 0;
}


void GraphMain()
{
	char ch;
	int i, n, v, v1, choice;

	struct graph *G = malloc(sizeof(struct graph));
	G -> V = 0;
    	G -> vertices = NULL;
    	G -> adjList = NULL;

	//Menu:
	do
	{
		printf("\n ===== Graph Implementation: Using Adjacency Lists\n\n");
		printf("\n1. Insert a vertex,\n2. Insert an edge,\n3. Delete an Edge,\n4. Delete a Vertex,\n5. Show Adjacency List,\n6. Exit.\n\n");
		printf("Choose: ");
		
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter the value of the vertex: ");
				scanf("%d", &v);

				G = insertVertex(G, v);
				printadjList(G);
				break;

			case 2:
				printf("\nEnter the pair between which the edge should be associated: ");
				scanf("%d%d", &v, &v1);

				G = insertEdge(v, v1, G);
				printadjList(G);
				break;
			
			case 3:
				printf("\nEnter the pair between which the edge should be deleted: ");
				scanf("%d%d", &v, &v1);

				G = deleteEdge(v, v1, G);
				printadjList(G);
				break;

			case 4:
				printf("\nEnter the vertex that is to be deleted: ");
				scanf("%d", &v);

				G = deleteVertex(G, v);
				printadjList(G);
				break;
			case 5:
				printadjList(G);
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



struct graph *deleteEdge(int V1, int V2, struct graph *G)
{
	int V1i, V2i;

	if(G == NULL)
	{
		printf("\nGraph is empty!!\n\n");
		return G;
	}

	V1i = search(G -> vertices, V1, G -> V);
	V2i = search(G -> vertices, V2, G -> V);

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex not found!!\n\n");
		return G;
	}

	if(delete_SL_any(V1, G -> adjList[V2i]))	return G;
	if(delete_SL_any(V2, G -> adjList[V1i]))	return G;

	return G;
}


struct graph *deleteVertex(struct graph * Graph, int V)
{
	int i, j, found = 1;

	// Remove V from all other lists:
	for(i = 0; i < Graph->V; i++)
	{
    		if(Graph->adjList[i] != NULL && Graph->adjList[i]->data != V)
	    	{
	        	delete_SL_any(V, Graph->adjList[i]);
	    	}
	}

	// Now free V's adjacency list:
	for(i = 0; i < Graph->V; i++)
	{
	    	if(Graph->adjList[i] != NULL && Graph->adjList[i]->data == V)
	    	{
	        	struct node *temp = Graph -> adjList[i];
	
			found = 0;
			while(temp != NULL)
			{
				struct node *next = temp -> next;
				free(temp);
				temp = next;
			}
			break;
	    	}
	}

	if(found == 1)
	{
		printf("\nVertex not found in the graph!!\n\n");
		return Graph;
	}

	Graph->adjList[i] = NULL;
	
	//Shift the lists that are after the deleted list:
	for(j = i; j < Graph->V - 1; j++)
	{
		Graph->vertices[j] = Graph->vertices[j + 1];
		Graph->adjList[j] = Graph->adjList[j + 1];
	}

	Graph->adjList[Graph->V - 1] = NULL;
	Graph->V--;

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


int delete_SL_any(int V, struct node *adjList)
{
	struct node *deltemp = NULL;
	struct node *temp = adjList;
	int found = 1;

	struct node *prev = NULL;
	while(temp != NULL)
	{
		if(temp -> data == V)
		{
			found = 0;	
			deltemp = temp;
			break;
		}
		prev = temp;
		temp = temp -> next;
	}

	if(found == 0)
	{
		if(prev != NULL)
		{
			prev -> next = temp -> next;
		}
		else
		{
			adjList = adjList -> next;
		}
	}
	else
	{
		return found;
	}
	free(deltemp);

	return found;
}
