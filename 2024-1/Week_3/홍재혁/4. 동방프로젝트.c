#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _act {
	int x;
	int y;
}Act;
int room[1000000];
int main(void)
{
	int cnt = 0;
	Act xy[5000];
	
	int N, M;
	scanf("%d\n%d", &N, &M);
	if (M == 0)
	{
		printf("%d", N);
		exit(0);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &xy[i].x, &xy[i].y);
	}
	for (int i = 0; i < N; i++)
	{
		room[i] = i + 1;
	}
	
	for (int i = 0; i < M; i++)
	{
		for (int j = xy[i].x; j < xy[i].y; j++)
		{
			
			room[j - 1] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (room[i] != 0)
		{
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}