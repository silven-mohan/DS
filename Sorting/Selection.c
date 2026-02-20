/*Selection Sort Implementation*/

/*
 * This program takes an unsorted array of elements of size n from the user.
 * And, sorts the array in ascending order using Selection Sorting Technique.
 * While sorting, prints all of the passes of the sorting.
 * And, finally prints the sorted array of elements.
 * This program handles all of the error cases.
*/

//Preprocessing Directives:
#include<stdio.h>	//For Basic I/O functions.

//Function Prototypes:
void swap(int *, int *);


//Main function:
int main()
{
	int i, j, k, min_index, n;

	printf("Enter the size of the array: ");
	scanf("%d", &n);	//Taking the size of the array from the user.
	
	if(n < 1)
	{
		printf("No elements for sorting!\n");
		return 1;	//Handling the error case.
	}

	int a[n];
				
	//Taking the array of elements:
	printf("\nEnter the elements of the array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//Printing the Unsorted Array:
	printf("\nThe Unsorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n==============\n\n");

	//Main Logic:
	for(i=0;i<n;i++)
	{
		min_index = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		swap(&a[i], &a[min_index]);	//Swapping the large number with the small one.
		
		//Printing the each pass:
		printf("Pass %d: ", i+1);
		for(k=0;k<n;k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
	}
	printf("\n==============\n\n");

	//Printing the Sorted Array:
	printf("\nThe Sorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

//Function Definitions:

//swap():
//This function swaps the values in any two integer variables by dereferencing.

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
