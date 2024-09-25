#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b?a:b)
int N, M;
int* money;
int Solve(int max) { //Binary Search
        int left = 0, right = max;
        while (left <= right) {
                int mid = (left + right) / 2, sum = 0;
                for (int i = 0; i < N; i++) sum += min(money[i], mid);
                //가능한 최대의 예산, 예산 합이 예산 총액과 같을 수 있음
                if (sum <= M) {
                        max = mid;
                        left = mid + 1;
                }
                else right = mid - 1;
        }
        return max;
}
int main()
{
        int max = 0, sum = 0;
        scanf("%d", &N);
        money = (int*)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++) {
                scanf("%d", &money[i]);
                sum += money[i];
                if (max < money[i])max = money[i];
        }
        scanf("%d", &M);
        //예산 총 합이 총액보다 작으면 그대로 출력
        printf("%d\n", (sum < M ? max : Solve(max)));
        free(money);
