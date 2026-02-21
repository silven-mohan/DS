/*Linear Searching Implementation*/

/*
 * This program takes an array of integers of size n from the user.
 * And, a key element to search in that array.
 * Using Linear Searching technique if the element is in the array this program prints its position.
 * Handles all error cases.
*/

//Preprocessing Directives:
#include<stdio.h>	//For Basic I/O Functions.
			

//Main Function:
int main()
{
	int i, key, n;

	printf("Enter the size of the array: ");	//Taking the size of the array from the user.
	scanf("%d", &n);

	if(n < 1)
	{
		printf("No elements for sorting!!\n");		//Handling the error case.
		return 1;
	}

	int a[n];

	//Taking the elements of the array from the user:
	printf("\nEnter the array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	printf("\nEnter the element that is to be searched: ");		//Taking the key element from the user.
	scanf("%d", &key);

	//Main logic:
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("\n%d is found at position %d\n\n", key, i);		//Element found.
			return 0;
		}
	}

	printf("\n%d is not found in the array.\n\n");		//Element not found.

	return 1;
}
