/** ===== Single Linked List: Operations Implementation ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the operations on a Single Linked List.
 * In this we do the following processes:
 	* Creation of the List.
	* Initialization of the List with certain values.
	* Display the List by traversing.
	* Insertion of a new node at the front or middle(any position) or at the end of the list.
	* Deletion of a node that is at front or middle(any position) or at the end of the list.
	* Search for specific node in the list.
	* Merge two lists into a single list and print the merged list.
	* Reverse the single linked list.
	* Modify a specific node's value.
 * Thus, we finally perform all of the operations on the list.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),....
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};

struct node *header = NULL, *N = NULL, new;		//Declaraing here for global access.


/** ===== Function Prototypes ===== **/
int create(struct node **, int);
int init(struct node *, struct node *, int);
int display(struct node *);
int insertMain(int);
int insertFront(void);
int insertPos(int);
int insertEnd(void);
int deleteMain(void);
int deleteFront(void);
int deletePos(void);
int deleteEnd(void);
int search(void);
int mergeMain(void);
int merge(struct node *, struct node *);
int reverse(void);
int modify(int);


/** ===== Main Function ===== **/
int main()
{
	//Variable declarations:
	int choice, n;
	char ch2;


	printf("\n\n ====== Singly Linked List : Operations Implementations ====== \n\n");
	printf("\n   -------------------------------------------------------------   \n");
	printf("\n\nLet us start by creating a list and assigning each node some values...\n");
	printf("Enter the no. of nodes in the list: ");
	scanf("%d", &n);

	printf("\nCreating the list......\n");
	if(create(&header, 1))  return 1;
	if(create(&N, n)) return 1;	
	printf("\nSuccessfully created the list.");
	 	
	printf("\nInitializing the list.....\n");
	init(header, N, n);

	do
	{
		printf("\n===============================\n\n");
		printf("\nChoose the operations that are to be performed on the list: \n");
		printf("\n1. Traversal\n2. Insertion of Nodes\n3. Deletion of Nodes\n4. Searching of a node\n5. Merging of two lists\n6. Reversing of a list\n7. Modify a node's value\n8. Exit\n");
		scanf("%d", &choice);
		printf("\n===============================\n\n");

		//Deciding the user's choice:
		switch(choice)
		{
			case 1:
				{
					printf("Traversing...\n");
					if(display(header))  return 1;
					break;
				}
			case 2:
				{
					printf("Insertion...\n");
					if(insertMain(n))  return 1;
					break;
				}
			case 3:
				{
					printf("Deletion...\n");
					if(deleteMain())  return 1;
					break;
				}
			case 4:
				{
					printf("Searching...\n");
					printf("The list is: \n");
					if(display(header))  return 1;
					
					if(search())  return 1;
					break;
				}
			case 5:
				{
					printf("Merging two lists....\n");
					if(mergeMain())  return 1;
					break;
				}
			case 6:
				{
					printf("Reversing the list....\n");
					printf("The list is: \n");
					if(display(header))  return 1;
					
					if(reverse())  return 1;
					break;
				}
			case 7:
				{
					printf("Modifying a node's value...\n");
					printf("The list is: \n");
					if(display(header))  return 1;
					
					if(modify(n))  return 1;
					break;
				}
			case 8:
				{
					printf("Exit...\n");
					goto l;
					break;
				}
			default:
				{
					printf("Invalid option. Try Again!!\n");
				}
		}

		printf("\nDo you want to continue?(Y/n)\n");
		scanf(" %c", &ch2);
		
	}while(ch2 == 'Y');
	l:
	
	//free the allocated memory:
	free(header);  header = NULL;
	free(N);  N = NULL;
	
	return 0;
}


/** ===== Function Definitions ===== **/
//create():
//This function allocates the memory for the nodes.

int create(struct node **N, int size)
{
	if(size < 1)
	{
		printf("\nInsufficient nodes to create a list!!\n\n");		//Handling edge cases.
		return 1;
	}

	//Allocating the memory for the n nodes.
	*N = malloc(size * sizeof(struct node));

	if(*N == NULL)
	{
		printf("\nMemory allocation failed!");		//Checking if memory allocation is done or not.
		return 1;				
	}

	return 0;
}


//init():
//This function initializes all of the nodes in the list with a certain values.

int init(struct node* header, struct node* N, int size)
{
	int i = 0;

	//Linking header node to the N nodes.
	header->next = &N[0];

	//Taking the data of all the nodes.
	printf("\nEnter the data of all of the nodes: ");
	while(i < size)
	{
		scanf("%d", &((N+i) -> data));
		if(i == size-1)
		{
			(N+i) -> next = NULL;
			return 0;
		}

		(N+i) -> next = ((N+i)+1);
		i += 1;
	}

	printf("\nSuccessfully initialized all the nodes with data.\n\n");

	return 0;
}


//display():
//This function displays all of the nodes and it's data.

int display(struct node *header)
{
	//Checking the edge case:
	if(header->next == NULL)
	{
		printf("\nThe list is empty!!\n\n");
		return 1;
	}

	struct node *temp = header->next;

	//Traversing through every node and printing their data values.
	while(temp != NULL)
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf(" [ NULL ]");

	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}


//insertMain():
//This function created the new node that is to be inserted and determines where it should be inserted(front, end, or any other position)

int insertMain(int size)
{
	int choice1;

	//Creating the new node that is to be inserted:	
	printf("\nEnter the data value of the new node that is to be inserted: ");
	scanf("%d", &new.data);
	new.next = NULL;
	printf("\nSuccessfully created the new node.\n");

	//Taking the user's choice at which position should the node be inserted.
	printf("\nAt which position should the node be inserted: ");
	printf("\n1. Front\n2. At any position 'n'\n3. End\n");
	printf("\nChoose one of the option: ");
	scanf(" %d", &choice1);
	
	//Printing the list before insertion:
	printf("\nThe list before insertion: ");
	if(display(header)) return 1;

	//Execution based on the choice:
	if(choice1 == 1)
	{
		if(insertFront()) return 1;
	}
	else if(choice1 == 2)
	{
		if(insertPos(size)) return 1;
	}
	else if(choice1 == 3)
	{
		if(insertEnd()) return 1;
	}
	else
	{
		printf("\nInvalid Option!!");
		return 1;
	}
	printf("\nSuccessfully inserted the node.\nThe list after the node insertion is: ");
	if(display(header))  return 1;

	return 0;
}


//insertFront():
//This function inserts a node the front of the list.

int insertFront()
{
	struct node *temp;

	temp = header -> next;

	//Linking the new node to the header node.
	header -> next = &new;

	//Linking the list to the new node that is inserted at the front position.
	new.next = temp;

	return 0;
}


//insertPos():
//This function inserts a node at the specified position.

int insertPos(int size)
{
	int pos, j = 0;
	printf("\nAt which position do you want to insert the node: ");
	scanf(" %d", &pos);

	if(pos < 0 || pos > size+1)
	{
		printf("\nCannot insert at that position.\n");
		return 1;
	}	

	if(pos == 0)
	{
		insertFront();
		return 0;
	}
	if(pos == size+1)
	{
		insertEnd();
		return 0;
	}
	
	struct node *temp = NULL, *prev = NULL;

	temp = header -> next;

	while(temp != NULL && j < pos)
	{
		prev = temp;
		temp = temp -> next;
		j += 1;
	}
	
	//Linking the new node to the node befor position 'pos':
	prev -> next = &new;

	//Linking the nodes from the position 'pos' to the the new node:
	new.next = temp;

	return 0;
}


//insertEnd():
//This function inserts a node at the end of the list.

int insertEnd()
{
	struct node *temp;

	temp = header -> next;


	//Traversing till the last node:
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}

	//Inserting the node at the end:
	temp -> next = &new;
	new.next = NULL;

	return 0;
		
}


//deleteMain():
//This function lets user decide which node to delete from the list.

int deleteMain()
{
	int choice1;

	printf("\nWhich node do you want to delete: ");
	printf("\n1. Node at Front\n2. Node at any Position\n3. Node at End\n");
	printf("\nChoose one of the option: ");
	scanf("%d", &choice1);
	
	//Printing the original list:
	printf("\nThe list before deletion: \n");
	if(display(header))  return 1;

	if(choice1 == 1)
	{
		if(deleteFront()) return 1;
	}
	else if(choice1 == 2)
	{
		if(deletePos()) return 1;
	}
	else if(choice1 == 3)
	{
		if(deleteEnd()) return 1;
	}
	else
	{
		printf("\nInvalid option!!\n");
		return 1;		//Checking Edge case.
	}

	printf("\nSuccessfully deleted the node.\n");
	if(display(header)) return 1;				//Displaying the new list.

	return 0;
}


//deleteFront():
//This function deletes the node that is at the front most position.

int deleteFront()
{
	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!");
		return 1;
	}

	struct node *temp = NULL;

	temp = header -> next;		//Now temp points to the front node.
	
	//If the list contains only one node:
	if(temp -> next == NULL)
	{
		header -> next == NULL;	
		return 0;
	}

	header -> next = temp -> next;		//Now temp -> next points to the second node.

	return 0;
}


//deletePos():
//This function deletes the node that is at a specific position.

int deletePos()
{
	int pos, j = 0;

	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	//Taking the position of the nodes:
	printf("\nEnter the Position of the node: ");
	scanf("%d", &pos);

	struct node *temp = NULL, *prev = NULL;
	temp = header -> next;

	while(temp != NULL && j < pos)
	{
		prev = temp;
		temp = temp -> next;
		j += 1;
	}

	prev -> next = temp -> next;

	return 0;

}


//deleteEnd():
//This function deleted the node that is at the end of the list.

int deleteEnd()
{
	//Checking if the list is empty:
	if(header -> next == NULL)
	{
		printf("\nThe list is empty!!\n");
		return 1;
	}

	struct node *temp = NULL, *prev = NULL;
	temp = header -> next;

	//If the list has only one node:
	if(temp -> next == NULL)
	{
		header -> next = NULL;
		return 0;	
	}

	//Traversing till the end of the list:
	while(temp -> next != NULL)
	{
		prev = temp;
		temp = temp -> next;
	}

	//Deleting the link betwwen the n and n-1 node:
	prev -> next = NULL;

	return 0;
}


//search():
//This function takes an element from the user and searches for the element in the list.

int search()
{
	int key, i = 0;
	
	//Taking the element from the user:
	printf("\nEnter the element that is to be searched: ");
	scanf("%d", &key);

	struct node *temp = NULL;
	temp = header;

	//Traversing through the entire list:
	while(temp -> next != NULL)
	{
		if(temp -> data == key)		//Comparing the node with key.
		{
			printf("\n%d is found in the list at the position: %d\n", key, i);
			
			return 0;
		}
		i += 1;
		temp = temp -> next;
	}	

	printf("\nElement was not found.\n");
	
	return 1;
}

//mergeMain():
//This function acts as the main function for merge operation.

int mergeMain(void)
{
	struct node *N2 = NULL, *header2 = NULL;
	int n2;
	
	//Allocating the memory:
	if(create(&header2, 1))  return 1;
	
	//Getting the second list:
	printf("\nEnter the no. of nodes in the second list: ");
	scanf("%d", &n2);
	
	//Allocating memory for all of the nodes in second list:
	if(create(&N2, n2)) return 1;
	init(header2, N2, n2);
	
	//Printing the first list:
	printf("\nThe first list is: \n");
	if(display(header))  return 1;
	
	//Printing the second list:
	printf("\nThe second list is: \n");
	if(display(header2))  return 1;
	
	//Now merging the two lists into a single one:
	merge(header, header2);
	
	//free the allocated memory:
	free(header2);  header2 = NULL;
	free(N2);  N2 = NULL;
	
	return 0;
}
//merge():
//This function merges two linked lists as a single list.

int merge(struct node *h1, struct node *h2)
{
	struct node *header3 = NULL;

	//Allocating memory:
	if(create(&header3, 1))  return 1;

	//Linking the first list to the header:
	header3 -> next = h1 -> next;

	struct node *temp = NULL;
	temp = header3 -> next;

	//Traversing till the last node of the first list:
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}

	//Linking last node of list1 to first node of list2:
	temp -> next = h2 -> next;
	
	//Printing the merged list:
	printf("\nThe merged list is: \n");
	if(display(header3))  return 1;

	//free the allocated memory:
	free(header3);  header3 = NULL;

	return 0;
}


//reverse():
//This function reverses the list.

int reverse()
{
	struct node *prev = NULL, *curr = NULL, *next = NULL;

	//Store the first node in curr:
	curr = header -> next;

	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	//Linking the last node to the header node:
	header -> next = prev;

	printf("\nThe reversed list is: ");
	if(display(header)) return 1;

	return 0;
}


//modify():
//This function takes the position of a node in list and modifies its value.

int modify(int size)
{
	int key, i = 0, newValue;
	
	//Taking the element from the user:
	printf("\nEnter the position of the node whose value is to be modified: ");
	scanf("%d", &key);

	//Taking the new value from the user:
	printf("\nEnter the new value: ");
	scanf("%d", &newValue);

	//Checking if position is out of bounds:
	if(key < 1 || key >= size)
	{	
		printf("\nPosition of the node is out of bounds. Can't Access!!\n");
		return 1;
	}

	struct node *temp = NULL;
	temp = header -> next;

	//Traversing through the entire list:
	while(temp != NULL)
	{
		if(i == key)		//Comparing the node with key.
		{
			temp -> data = newValue;	//Modify the value.
			
			break;
		}
		i += 1;
		temp = temp -> next;
	}	

	printf("\nThe modified list is: \n");
	if(display(header)) return 1;		//Display the modified list.
	
	return 0;
}
