/*
피연산자 0번째 값에 재귀적으로 계산하는 방식
백트래킹 사용
optr[i]>0일 때, 특정 연산자와의 계산 값을 변수로 보냄
=>다음 연산에서 중복을 피하기 위해 연산자 개수를 하나 줄임
종료조건에 의해 함수가 끝나면 다음 연산자를 위해 줄였던 연산자 개수를 다시 늘림
===>>>N개의 피연산자의 (N-2)개 사이에 연산자가 모든 위치에 한번씩은 들어가게 됨
*/
/*(음수 / 양수의 경우)는 만들 필요 X*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define OPRD_SIZE 12
#define OPTR_SIZE 4
int oprd[OPRD_SIZE], optr[OPTR_SIZE];//피연산자, 연산자(0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈)
int N, mx = INT_MIN, mn = INT_MAX;
void solve(int result, int oprd_idx) {
        if (oprd_idx == N) {
                mx = max(mx, result);
                mn = min(mn, result);
                return;
        }
        for (int i = 0; i < OPTR_SIZE; i++) {
                if (optr[i] > 0) {
                        optr[i]--;
                        if (i == 0)solve(result + oprd[oprd_idx], oprd_idx + 1);
                        else if (i == 1)solve(result - oprd[oprd_idx], oprd_idx + 1);
                        else if (i == 2)solve(result * oprd[oprd_idx], oprd_idx + 1);
                        else solve(result / oprd[oprd_idx], oprd_idx + 1);
                        optr[i]++;
                }
        }
}
int main()
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &oprd[i]);
        for (int i = 0; i < OPTR_SIZE; i++)scanf("%d", &optr[i]);
        solve(oprd[0], 1);
        printf("%d\n%d\n", mx, mn);
}