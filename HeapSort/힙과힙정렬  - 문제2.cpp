#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc
#include <math.h>
#include <time.h> //srand

int H[99];
int n;

void downHeap(int i)
{
	int left = i * 2;
	int right = i * 2 + 1;
	int large, tmp;

	if (left > n)
	{
		return;
	}

	large = left;

	if (H[large] < H[right])
	{
		large = right;
	}

	if (H[i] < H[large])
	{
		tmp = H[i];
		H[i] = H[large];
		H[large] = tmp;
	}

	downHeap(large);
}

void rBuildHeap(int i) // Àç±Í
{
	if (i > n)
	{
		return;
	}
	if (i * 2 <= n)
	{
		rBuildHeap(2 * i);
	}
	if (i * 2 + 1 <= n)
	{
		rBuildHeap(2 * i + 1);
	}
	downHeap(i);
}

void buildHeap()
{
	for (int i = n / 2; i >= 1; i--)
	{
		downHeap(i);
	}
}

void printHeap()
{
	for (int i = 1; i < n + 1; i++)
	{
		printf(" %d", H[i]);
	}
	printf("\n");
}

int main(void)
{
	int i;

	scanf("%d", &n);

	for (i = 1; i < n + 1; i++)
	{
		scanf("%d", &H[i]);
	}

	buildHeap();


	printHeap();


	return 0;
}




