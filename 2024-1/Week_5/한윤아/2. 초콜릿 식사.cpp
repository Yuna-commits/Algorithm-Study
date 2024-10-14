/*
choco가 2의 제곱 형태일 때,
K에서 (choco/2)한 값들을 빼면서 K를 만들 수 있는지 확인
choco를 반으로 쪼갰을 떄 K보다 작거나 같으면 K에서 뺌, K-=choco
K보다 크면 횟수만 증가시키고 다시 쪼갬
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
        int K, choco = 1;
        scanf("%d", &K);
        /*가장 처음 나오는 K보다 큰 choco가 최적의 값
        choco가 최적의 값이 아닐 경우는 생각 X, 시간초과 뜸*/
        while (choco < K) choco *= 2;
        if (choco == K) printf("%d %d\n", choco, 0);
        else {
                int tmp = choco;
                int cnt = 0;
                while (K > 0) {
                        if (K >= tmp) K -= tmp;
                        else {
                                tmp /= 2;
                                cnt++;
                        }
                }
                printf("%d %d\n", choco, cnt);
        }
}