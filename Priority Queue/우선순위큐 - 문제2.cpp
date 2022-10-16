#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc
#include <math.h>
#include <time.h> //srand

void inPlaceInsertionSort(int* arr, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	inPlaceInsertionSort(arr, n);

	for (i = 0; i < n; i++)
	{
		printf(" %d", arr[i]);
	}
	

	return 0;
}



