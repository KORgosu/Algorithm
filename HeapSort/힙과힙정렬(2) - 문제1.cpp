#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc
#include <math.h>
#include <time.h> //srand

int H[99];
int n;
int size;

void printArray()
{
	for (int i = 1; i < size + 1; i++)
	{
		printf(" %d", H[i]);
	}
	printf("\n");
}

void downHeap(int i)
{
	int left, right;
	int large, tmp;
	left = i * 2;
	right = i * 2 + 1;
	if (left > n && right > n)
	{
		return;
	}

	large = left;
	if (right <= n)
	{
		if (H[left] < H[right])
		{
			large = right;
		}
	}

	if (H[large] <= H[i])
	{
		return;
	}
	tmp = H[i];
	H[i] = H[large];
	H[large] = tmp;

	downHeap(large);

}


void rBuildHeap(int i)//재귀상향식 힙 생성에서 사용
{
	if (i > n)
	{
		return;
	}
	rBuildHeap(i * 2);
	rBuildHeap(i * 2 + 1);
	downHeap(i);

	return;
}

void buildHeap()
{
	for (int i = n / 2; i >= 1; i--)
	{
		downHeap(i);
	}
}

void inPlaceHeapSort()
{
	int tmp;

	for (int i = n; i >= 2; i--)
	{
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		n--;
		downHeap(1);
	}
}

int main(void)
{
	int i;

	scanf("%d", &n);
	size = n;

	for (i = 1; i < n + 1; i++)
	{
		scanf("%d", &H[i]);
	}

	rBuildHeap(1);
	inPlaceHeapSort();
	printArray();

	return 0;
}
