#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int main(void)
{
	long long int K, N;
	scanf("%lld %lld", &K, &N);

	//배열 동적할당하고 입력받기
	long long int* arr = (long long int*)malloc(sizeof(long long int) * K);
	for (int i = 0; i < K; i++)
	{
		scanf("%lld", &arr[i]);
	}

	//배열 오름차순 정렬
	qsort(arr, K, sizeof(long long int), compare);


	//값 찾기
	long long int left = 1;
	long long int right = arr[K - 1];
	long long int answer = 0;

	while (left <= right)
	{
		long long int count = 0;
		long long int mid = (left + right) / 2;
		for (int i = 0; i < K; i++)
		{
			count += arr[i] / mid;  //mid값 랜선 길이로 나눴을 때 총 몇개가 나오는지 저장
		}
		if (count >= N)
		{
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	//값 출력
	printf("%lld", answer);

	//메모리 해제
	free(arr);

	return 0;
}
int compare(const void* a, const void* b)
{
	if (*(long long int*)a > *(long long int*)b)
		return 1;
	else if (*(long long int*)a < *(long long int*)b)
		return -1;
	else
		return 0;
}
