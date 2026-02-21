/*Bubble Sort Implementation*/

/*
 * This program takes an unsorted array from the user of size n.
 * And, sorts the array using Bubble sorting technique in ascending order.
 * During the sorting process this prints all of the passes of the sorting.
 * And also handles all of the error cases.
 * At last, prints the sorted array.
*/

//Preprocessing Directives:
#include<stdio.h>	//For Basic I/O functions.

//Function Prototypes:
void swap(int *, int *);

//Main Function:
int main()
{
	int i, j, k, n;

	printf("\nEnter the no. of elements of the array: ");	//Taking the size of the array from the user.
	scanf("%d", &n);

	if(n < 1)
	{
		printf("\nNo elements for sorting!!"); 		//Handling error case.
		return 1;
	}

	int a[n];

	//Taking the array elements from the user.
	printf("\nEnter the elements of the array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//Printing the unsorted array:
	printf("\n\nThe Unsorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n==============\n\n");

	//Main Logic:
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j] > a[j+1])
			{
				swap(&a[j], &a[j+1]);
			}
		}

		//Printing all of the passes:
		printf("Pass %d: ", i+1);
		for(k=0;k<n;k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
	}
	printf("\n==============\n\n");

	//Printing the sorted array:
	printf("\n\nThe Sorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;

}

//Function Definitions:

//swap():
//This function swaps the integer values in any two variables by dereferencing.

void swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;		//XOR Swapping.
	*x = *x ^ *y;
}
