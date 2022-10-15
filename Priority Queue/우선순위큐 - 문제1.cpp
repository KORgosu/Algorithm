#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc
#include <math.h>
#include <time.h> //srand

int main(void)
{
	int n, i, j, k;
	int tmp = 0;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int max_arr;
	k = n - 1;

	for (j = n; j > 0; j--)
	{
		max_arr = 0;
		for (i = 0; i < j; i++)
		{
			if (arr[max_arr] < arr[i])
			{
				max_arr = i;
			}
		}

		tmp = arr[k];
		arr[k] = arr[max_arr];
		arr[max_arr] = tmp;
		k--;
	}

	for (i = 0; i < n; i++)
	{
		printf(" %d", arr[i]);
	}
	
	

	return 0;
}



