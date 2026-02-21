/*Binary Search Implementation*/

/*
 * This program takes a sorted array from the user of size n.
 * And, also takes a key that is to be searched in that array.
 * The sorting is done by using Binary Search Sorting technique.
 * Handles error cases.
*/

//Preprocessing Directives:
#include<stdio.h>	//For Basic I/O functions.

//Main Function:
int main()
{
	int i, n, key, l, mid, u;

	printf("Enter the size of the array: ");	//Taking the size of the array from the user.
	scanf("%d", &n);

	if(n < 1)
	{
		printf("\nNo elements to search!!\n");		//Handling error case.
		return 1;
	}

	int a[n];

	//Taking the sorted array elements from the user.
	printf("\nEnter the array elements in sorted order(ascending): ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//Taking the key element from the user.
	printf("\nEnter the element that is to be searched: ");
	scanf("%d", &key);

	//Main Logic:
	l=0;		//Lower Bound
	u=n-1;
	while(l<=u)
	{
		mid = (l+u)/2;
		if(key == a[mid])
		{
			printf("\n\n%d is found at position: %d\n", key, mid);		//Element Found.
			return 0;
		}
		else if(key < a[mid])
		{
			u = mid-1;
		}
		else
		{
			l = mid+1;
		}
	}

	printf("\n\n%d is not found in the array.\n", key);	//Element not Found.

	return 1;
}
