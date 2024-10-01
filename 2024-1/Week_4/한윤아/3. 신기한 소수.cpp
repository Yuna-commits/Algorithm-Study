/*
N만큼 할당된 temp에서 idx==0번째부터 idx==N-1번째 위치에 1~9사이 숫자 x를 순서대로 넣음
temp 0번째, 0~1번째, 0~2번째...0~(N-1)번째 위치까지 저장된 숫자가 소수인지 확인
소수이면 idx+1로 temp의 다음 자리로 넘어감, 소수가 아니면 다음번 숫자 x로 넘어감
0번째 위치엔 소수 2,3,5,7이 반드시 들어감
1~9사이 숫자 x가 순서대로 들어가서 소수판별을 하기 때문에 오름차순으로 출력됨
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int N;
int* temp;
int is_Prime(int* temp, int size) {/*size로 몇 자리 정수인지 확인*/
        int num = 0, exp = size;
        for (int i = 0; i < size; i++) num += temp[i] * pow(10, --exp);
        for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0)return 0;
        }
        return 1;
}
void solve(int idx) {
        if (idx == N) {
                for (int i = 0; i < N; i++) printf("%d", temp[i]);
                printf("\n");
                return;
        }
        for (int x = 1; x < 10; x++) {
                if (idx == 0 && x == 1)continue;
                temp[idx] = x;
                if (is_Prime(temp, idx + 1)) solve(idx + 1);
        }
}
int main()
{
        scanf("%d", &N);
        temp = (int*)calloc(N, sizeof(int));/*할당된 공간을 0으로 초기화하기 위해 calloc 사용*/
        solve(0);
        free(temp);
}