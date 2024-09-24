#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b);
int main(void)
{
	int N, M, ans;
	int sum1 = 0;

	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d ", &arr[i]);
	scanf("%d", &M);

	//오름차순 정렬
	qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; i++)
	{
		sum1 += arr[i];
	}

	//1번조건 - 모든 요청 배정될 수 있는 경우
	if(sum1<=M)
	{
		printf("%d", arr[N - 1]);
		exit(0);
	}


	//2번조건 - 모든 요청 배정될 수 없는 경우
	//초기 상한액(평균)
	int avg = arr[N-1];
	int sum2 = 0;
	
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i] <= avg)
				sum2 += arr[i];
			else if (arr[i] >= avg)
				sum2 += avg;
		}
		//상한액으로 계산해서 총예산보다 작거나 같으면 상한액 출력
		if (sum2 <= M)
		{
			printf("%d", avg);
			break;
		}
		//총예산보다 크다면 상한액-1
		else
		{
			avg--;
			sum2 = 0;
		}
	}




	return 0;
}
int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}