#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	int* arrS = (int*)malloc(sizeof(int) * N);
	int* arrD = (int*)malloc(sizeof(int) * N);
	int* arrP = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d ", &arrS[i]);
	for (int i = 0; i < N; i++)
		scanf("%d ", &arrD[i]);

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arrP[arrD[j]-1] = arrS[j];
		}
		memcpy(arrS, arrP, sizeof(int) * N);
	}

	for (int i = 0; i < N; i++)
		printf("%d ", arrP[i]);

	free(arrD);
	free(arrP);
	free(arrS);

	return 0;
}