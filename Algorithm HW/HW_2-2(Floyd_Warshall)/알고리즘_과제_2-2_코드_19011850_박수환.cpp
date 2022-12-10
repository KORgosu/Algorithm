#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <math.h>

int number = 5;
int INF = 10000;

// 전체그래프 초기화
int weight[5][5] = {
	{ 0, 10, 5, INF, INF },
	{ INF, 0, 2, 1, INF },
	{ INF, 3, 0, 9, 2 },
	{ INF, INF, INF, 0, 4 },
	{ 7, INF, INF, 6, 0 },
};
int d[5][5];

void print()
{
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (d[i][j] == INF)
				printf("%4c", '*');
			else printf("%4d", d[i][j]);
		}
		printf("\n\n");
	}
}


void floydWarshall()
{

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			d[i][j] = weight[i][j];
		}
	}

	// k = 거쳐가는 노드(중심)
	for (int k = 0; k < number; k++)
	{
		for (int i = 0; i < number; i++)
		{// i 는 출발노드
			for (int j = 0; j < number; j++)
			{ // j 는 도착노드
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		printf("F%d : \n", k);
		print();
	}
}

int main()
{
	int i, j;

	printf("********** weight adjacency matrix **********\n\n");
	for (i = 0; i < number; i++) {
		for (j = 0; j < number; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}

	printf("********* Floyd shortest Path **********\n\n");
	floydWarshall();


	return 0;
}
