/* Binary Heap : Deletion Implementation */ 

/*
 * This, program first builds the binary heap using arrays.
 * Then, displays the heap.
 * Then, finally shows the implementation of the deletion operation.
*/ 


//Preprocessing Directives:
#include<stdio.h>   //For Basic I/O operations.
#include<stdlib.h>      //For Basic DMA functions like malloc(), free(),...


//Function Prototypes:
int BuildHeap(int *, int);
int Reheap_Up(int *, int);
void swap(int *, int *);


//Main Function:
int main()
{
    int n, i;

    printf("\nEnter the total no. of elements in the heap: ");
    scanf("%d", &n);

    int HEAP[n];

    printf("\nEnter all of the elements of the heap: ");
    for(i = 0;i < n;i++)
    {   
        scanf("%d", &HEAP[i]);

    }

    BuildHeap(&HEAP[0], n);

    printf("\nThe Binary Heap is: ");
    for(i = 0;i < n;i++)
    {
        printf("%d ", HEAP[i]);
    }

    printf("\n\n");

    return 0;
}


//Function Definitions:

int BuildHeap(int *heap, int size)
{
    int i = 1;
    while(i < size)
    {
        Reheap_Up(heap, i);
        i += 1;
    }

    return 0;
}


int Reheap_Up(int *heap, int i)
{
    if(i != 0)
    {
        int p = (i - 1) / 2;

        if(heap[i] < heap[p])
        {
            swap(heap + i, heap + p);
            Reheap_Up(heap, p);
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
