/* Insertion(Inplace) Sort Implementation*/

/*
 * This program takes an unsorted array of integers of size n.
 * Evaluates all of the cases and then sorts the array in ascending order by using Insertion Sorting Techinque.
 * While, sorting this program prints every pass of the loop.
 * At last, prints the sorted array.
*/


//Preprocessing Directives:
#include<stdio.h>	//For Basic I/O functions.

//Main function:
int main()
{
	int i, j, k, n, key;
	printf("Enter the no. of elements of the array: ");	//Taking the size of the array from the user.
	scanf("%d", &n);
	if(n < 1)
	{
		printf("\nNo elements for sorting!\n");
		return 1;
	}
	int a[n];

	printf("\nEnter the elements of the array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);	//Taking the n array elements from the user.
	}
	
	//Printing the Unsorted Array:
	printf("\nThe Unsorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n==============\n\n");

	//Main Logic:
	for(i=1;i<n;i++)
	{
		key = a[i];
		j = i-1;
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j-1;
		}	
		a[j+1] = key;

		//Printing every pass:
		printf("Pass %d: ", i);
		for(k=0;k<n;k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
	}
	printf("\n==============\n\n");

	//Printing the Sorted Array:
	printf("The Sorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}

