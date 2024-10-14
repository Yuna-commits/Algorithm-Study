#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int C, R, K;
int main()
{
        scanf("%d%d", &C, &R);
        scanf("%d", &K);
        if (K > C * R) {
                printf("0\n");
                return 0;
        }
        int x = 1, y = 0, p = 1;
        int seats = 0;
        /*골뱅이 배열
        y축 증가->x축 증가->y축 감소->x축 감소 반복
        x축 첫번째 이동은 C=7일 때 6칸으로 시작
        x, y축 모두 이동 범위 1씩 감소 */
        while (1) {
                for (int i = 1; i <= R; i++) {
                        y += p;
                        seats++;
                        if (seats == K) {
                                printf("%d %d\n", x, y);
                                return 0;
                        }
                }
                for (int i = 1; i < C; i++) {
                        x += p;
                        seats++;
                        if (seats == K) {
                                printf("%d %d\n", x, y);
                                return 0;
                        }
                }
                /*p = {1,-1} 증감변수*/
                p *= -1;
                C--; R--;
        }
}