#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int compare(const void* a, const void* b);
int main(void)
{
	char sen[1001];
	scanf("%s", sen);
	int senlen = strlen(sen);
	int a_cnt = 0;

	//a의 개수 세기
	for (int i = 0; i < senlen; i++)
	{
		if (sen[i] == 'a')
			a_cnt++;
	}


	int min = senlen;
	//윈도우 크기많큼 움직이면서 b개수세기
	for (int i = 0; i < senlen; i++)
	{
		int b_cnt=0;
		for (int j = 0; j < a_cnt; j++)
		{
			if (sen[(i + j)%senlen] == 'b')
				b_cnt++;
		}
		if (compare(&min, &b_cnt)==1)
			min = b_cnt;
	}

	printf("%d", min);


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