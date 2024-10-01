/*
상어가 없는 빈공간~상어가 있는 공간까지의 안전거리=빈공간~상어와의 최단거리
BFS이용, 최단거리중 가장 큰 값 구하기
상어가 없는 지점에서 상어가 있는 곳으로 BFS
visited[next]==0이면 한번도 방문하지 않은 곳, visited[now]+1로 갱신
마지막에 가장 큰 안전거리값 찾기
*/
#include<iostream>
#include<queue>
#include<cstring>
#define MAX_SIZE 50
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
using namespace std;
int N, M, ans;
int space[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];/*방문확인, 안전거리*/
/*시계방향 8방향 이동*/
int dx[] = { -1,-1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int is_valid(int x, int y) { return (x >= 0 && x < N && y >= 0 && y < M); }
int BFS(int x, int y) {
        memset(visited, 0, sizeof(visited));/*visited 배열 0 초기화*/
        visited[x][y] = 1;
        queue<pair<int, int>> que;
        que.push({ x,y });
        while (!que.empty()) {
                int now_x = que.front().first;
                int now_y = que.front().second;
                que.pop();
                /*현재 위치에서부터 시계방향으로 8방향 빈공간 탐색*/
                for (int i = 0; i < 8; i++) {
                        int next_x = now_x + dx[i];
                        int next_y = now_y + dy[i];
                        /*visited[nx][ny]!=0이면 이미 방문한적 있는 곳
                        다음 위치에 현재 경로까지의 지나온 길의 수 저장*/
                        if (visited[next_x][next_y] != 0 || !is_valid(next_x, next_y)) continue;
                        if (space[next_x][next_y] == 1) return visited[now_x][now_y];
                        visited[next_x][next_y] = visited[now_x][now_y] + 1;
                        que.push({ next_x, next_y });
                }
        }
        return 0;
}
int solve() {
        /*빈공간에서 상어가 있는 곳까지의 안전거리(최단거리)*/
        int ans = 0;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        if (space[i][j] == 0) ans = max(ans, BFS(i, j));
                }
        }
        return ans;
}
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) cin >> space[i][j];
        }
        cout << solve() << endl;
}