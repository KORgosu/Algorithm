#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc
#include <math.h>
#include <time.h> //srand

int H[99];
int n;

void upHeap(int i)
{
	if (i == 1)
	{
		return;
	}

	int parent = i / 2;
	int tmp;

	if (H[parent] > H[i])
	{
		return;
	}

	tmp = H[parent];
	H[parent] = H[i];
	H[i] = tmp;
	upHeap(parent);

}

void downHeap(int i)
{
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left > n)
	{
		return;
	}

	int large = left;

	if (H[right] > H[large])
	{
		large = right;
	}
	if (H[i] < H[large])
	{
		int temp = H[i];
		H[i] = H[large];
		H[large] = temp;
	}

	downHeap(large);
}
int insertItem(int key)
{
	n = n + 1;
	H[n] = key;
	upHeap(n);

	return 0;
}

int removeMax()
{
	int key;
	key = H[1];
	H[1] = H[n];
	n = n - 1;
	downHeap(1);

	return key;
}

void printHeap()
{
	for (int i = 1; i < n + 1; i++)
	{
		printf(" %d\n", H[i]);
	}
}

int main(void)
{
	int data;
	char order;

	while (1)
	{
		scanf("%c", &order);

		if (order == 'i')
		{
			scanf("%d", &data);
			int a = insertItem(data);
			printf("%d\n", a);
		}

		else if (order == 'd')
		{
			int a = removeMax();
			printf("%d\n", a);
		}

		else if (order == 'p')
		{
			printHeap();
		}
		else if (order == 'q')
		{
			break;
		}
	}

	return 0;
}



