/*
다익스트라 
=> 가중치가 각각 다른 그래프에서 사용,
     우선순위 큐에 해당 정점까지의 최단거리와 정점의 좌표를 한쌍으로 push
     push(-1*해당 정점까지의 최단거리, 정점의 좌표)
     우선순위 큐는 큰 값에 우선순위를 높게 주지만 최단거리를 찾아야 하기 때문에 음수로 만들어서 우선순위를 낮춤
     BFS처럼 검사
     => (지금까지 알고 있던 해당 정점의 최단경로, 현재 검사중인 정점(다음 위치)까지의 최단거리+간선의 가중치) 비교
           더 작은 값을 dist[next]에 갱신                       
*/
#include<iostream>
#include<queue>
#define INF 999999
#define min(a,b) (a<b?a:b)
using namespace std;
int N;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int dist[125][125];
int cave[125][125];
void dijkstra() {
        priority_queue<pair<int, pair<int, int>>> que;
        que.push({ -1 * cave[0][0], {0,0} });
        dist[0][0] = cave[0][0];
        while (!que.empty()) {
                int now_x = que.top().second.first;
                int now_y = que.top().second.second;
                que.pop();
                for (int i = 0; i < 4; i++) {
                        int next_x = now_x + dx[i];
                        int next_y = now_y + dy[i];
                        int next_cost = cave[next_x][next_y];
                        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
                                int before = dist[next_x][next_y];
                                int after = next_cost + dist[now_x][now_y];
                                if (before > after) {
                                        dist[next_x][next_y] = after;
                                        que.push({ -1 * after, {next_x, next_y} });
                                }
                        }
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        int cnt = 1;
        while (1) {
                cin >> N;
                if (N == 0) break;
                for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                                cin >> cave[i][j];
                                dist[i][j] = INF; /*dist 배열 매번 초기화*/
                        }
                }
                dijkstra();
                printf("Problem %d: %d\n", cnt++, dist[N - 1][N - 1]);
        }
}

/*
void bfs() {
        queue<pair<int, int>> que;
        que.push({ 0,0 });
        dist[0][0] = cave[0][0];
        while (!que.empty()) {
                int now_x = que.front().first;
                int now_y = que.front().second;
                que.pop();
                for (int i = 0; i < 4; i++) {
                        int next_x = now_x + dx[i];
                        int next_y = now_y + dy[i];
                        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
                                if (dist[next_x][next_y] > dist[now_x][now_y] + cave[next_x][next_y]) {
                                        dist[next_x][next_y]= dist[now_x][now_y] + cave[next_x][next_y];
                                        que.push({ next_x, next_y });
                                }
                        }
                }
        }
}*/
