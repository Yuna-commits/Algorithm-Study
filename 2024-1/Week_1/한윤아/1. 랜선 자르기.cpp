#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
long long* LAN; //랜선 최대 길이(2^31)-1
int K, N;
int check(int mid) {
                int cnt = 0;
                for (int i = 0; i < K; i++) {
                                int cut = LAN[i] / mid;
                                cnt += cut;
                }
                if (cnt < N) return 0;
                else return 1;
}
int main()
{
                long long max = 0, ans = 0;
                scanf("%d%d", &K, &N);
                LAN = (long long*)malloc(sizeof(long long) * K);
                for (int i = 0; i < K; i++) {
                                scanf("%lld", &LAN[i]);
                                if (LAN[i] > max)max = LAN[i];
                }
                //Binary Search
                long long left = 1, right = max;
                while (left <= right) {
                                long long mid = (left + right) / 2;
                                if (!check(mid))right = mid - 1;
                                else {
                                                ans = mid;
                                                left = mid + 1;
                                }
                }
                printf("%lld\n", ans);
                free(LAN);
}
