/* Binary Heap : Insertion */


/*
 * This program shows the implementation of Binary Heaps using arrays.
 * Then, builds and displays the heap.
 * Then, inserts a new element into the heap and displays.
*/


//Preprocessing Directives:
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free(), ...


//Function Prototypes:
int BuildHeap(int *, int);
int Reheap_up(int *, int);
void swap(int*, int*);


//Main Function:
int main()
{
	int n, i;

	printf("\nEnter the total no. of elements that are to be in the heap: ");
	scanf("%d", &n);

	int HEAP[n];

	printf("\nEnter the %d elements of the heap: ", n);
	for(i = 0;i<n;i++)
	{
		scanf("%d", &HEAP[i]);
	}

	BuildHeap(&HEAP[0], n);

	printf("\nThe HEAP is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ", HEAP[i]);
	}
	printf("\n");

	return 0;

}


//Function Definitions:

int BuildHeap(int *heap, int size)
{
	int i = 1;
	while(i < size)
	{
		Reheap_up(heap, i);
		i += 1;
	}

	return 0;
}


int Reheap_up(int *heap, int i)
{
	if(i != 0)
	{
		int p = (i - 1) / 2;

		if(heap[i] < heap[p])
		{
			swap((heap + i), (heap + p));
			Reheap_up(heap, p);
		}
	}

	return 0;
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
