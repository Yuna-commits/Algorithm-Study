#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define INF 9999999
#define min(a,b)(a<b?a:b)
int myFriend[50][50];
int N;
void two_friends() {//Floyd-Warshall
                for (int mid = 0; mid < N; mid++) {
                                for (int start = 0; start < N; start++) {
                                                for (int end = 0; end < N; end++) {
                                                                if (mid != start && start != end && mid != end) {
                                                                                myFriend[start][end] = min(myFriend[start][end], (myFriend[start][mid] + myFriend[mid][end]));
                                                                }
                                                }
                                }
                }
}
int main()
{
                scanf("%d", &N);
                for (int i = 0; i < N; i++) {
                                char NY[50]; scanf("%s", NY);
                                for (int j = 0; j < N; j++) {
                                                if (NY[j] == 'Y') myFriend[i][j] = 1;
                                                else myFriend[i][j] = INF;
                                }
                }
                two_friends();
                int max = 0;
                for (int i = 0; i < N; i++) {//Çà¸¶´Ù Ä£±¸ ¼ö °è»ê
                                int cnt = 0;
                                for (int j = 0; j < N; j++) {
                                                if (myFriend[i][j] <= 2) cnt++;
                                }
                                if (max < cnt) max = cnt;
                }
                printf("%d\n", max);
}
