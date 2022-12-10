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

bool visit[5]; // 방문한 노드
int distance[5]; // 최단 거리
int step[5] = { 0, };
int k = 0;


//가장 최소거리를 가지는 정점 반환, (선형탐색)
int shortStep() {
	int min = INF; // min 값에 무한대 넣어주고
	int index = 0;
	for (int i = 0; i < number; i++)
	{
		if (distance[i] < min && !visit[i])//방문하지 않은 노드중, 최솟값보다 더 낮은 값을 가지면
		{
			min = distance[i];
			index = i;
		}
	}

	return index;
}

void st()
{
	printf("S={");

	for (int i = 0; i < number; i++)
	{
		for (int j = i + 1; j < number; j++)
		{
			if (step[i] > step[j])
			{
				int tmp = step[i];
				step[i] = step[j];
				step[j] = tmp;
			}
		}
	}
	for (int i = 0; i < number; i++)
	{
		if (step[i] == 1)
		{
			printf("  A ");
		}
		else if (step[i] == 2)
		{
			printf("  B ");
		}
		else if (step[i] == 3)
		{
			printf("  C ");
		}
		else if (step[i] == 4)
		{
			printf("  D ");
		}
		else if (step[i] == 5)
		{
			printf("  E ");
		}
	}
	printf("}     \n");
}

// DIjkstra
void Dijkstra_Path(int start)
{
	for (int i = 0; i < number; i++)
	{
		step[i] = 9;
	}
	step[0] = 1;
	for (int i = 0; i < number; i++)
	{
		distance[i] = weight[start][i];
	}
	visit[start] = true;
	for (int i = 0; i < number - 1; i++)
	{
		int current = shortStep();
		printf("%d step : ", i);
		st();
		printf("distance :[");
		step[i + 1] = current + 1;
		for (int j = 0; j < number; j++)
		{
			if (distance[j] == INF)
				printf("%4c", '*');
			else printf("%4d", distance[j]);
		}
		printf("    ]\n\n");
		
		visit[current] = true;
		for (int j = 0; j < number; j++)
		{
			if (!visit[j])
			{
				//현재까지 알고있던 비용이랑 목적지까지 갈 비용이 직통으로 갈때보다 비용이 더 적게들었을때
				if (distance[current] + weight[current][j] < distance[j])
				{
					distance[j] = distance[current] + weight[current][j]; // 갱신해준다.
				}
			}
		}
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

	printf("********* Dijkstra shortest Path **********\n\n");
	Dijkstra_Path(0);

	printf("4 step : ");
	st();
	printf("distance :[");
	for (int i = 0; i < number; i++)
	{
		printf("%4d", distance[i]);
	}
	printf("    ]\n");

	return 0;
}
