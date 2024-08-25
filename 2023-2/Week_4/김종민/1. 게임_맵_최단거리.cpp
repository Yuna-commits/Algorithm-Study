#include <vector>
#include <queue>

using pii = std::pair<int, int>;

// 맵과 방문 여부를 작성할 2차원 벡터를 생성한다.
auto map = std::vector<std::vector<int>>();
auto visited = std::vector<std::vector<int>>();

// 상하좌우 움직임을 설정한다.
auto dx = std::vector<int>{ 1, -1, 0, 0 };
auto dy = std::vector<int>{ 0, 0, 1, -1 };

// 좌표를 전역에서 사용하기 위한 변수이다.
auto x_pos = 0;
auto y_pos = 0;

// 최단거리라는 단어가 들어가면 생각해야 할 알고리즘의 경우의 수는 총 4가지이다.
// 1. bfs
// 2. 다익스트라 알고리즘
// 3. 벨만-포드 알고리즘
// 4. 플로이드 워셜 알고리즘

// 이 중 방향이 있거나 가중치가 있는 경우에는 2, 3, 4를 사용하지만
// 2차원 격자가 존재하거나, 방향과 가중치가 없는 경우에는 1을 사용한다.

// 이 문제에서는 방향과 가중치가 없지만 최단거리를 구해야 하며, 격자가 존재하므로
// bfs와 방문 여부를 저장할 2차원 벡터를 이용하여 해결할 수 있다.
void bfs(int x, int y)
{
    auto que = std::queue<pii>();
    que.push(std::make_pair(x, y));
    visited[x][y] = true;

    map[y_pos - 1][x_pos- 1] = -1;

    while (!que.empty())
    {
        auto current = que.front(); que.pop();
        x = current.first;
        y = current.second;

        for (auto i = 0; i < 4; i++)
        {
            auto nx = x + dx[i];
            auto ny = y + dy[i];

            if (nx < 0 or ny < 0 or nx >= y_pos or ny >= x_pos)
                continue;

            if (!visited[nx][ny] and map[nx][ny] != 0)
            {
                que.push(std::make_pair(nx, ny));
                visited[nx][ny] = true;
                map[nx][ny] = map[x][y] + 1;
            }
        }
    }
}

int solution(std::vector<std::vector<int>> maps)
{
    x_pos = maps[0].size();
    y_pos = maps.size();
    map = maps;

    visited = std::vector<std::vector<int>>(y_pos, std::vector<int>(x_pos, 0));
    bfs(0, 0);

    // 최단거리를 리턴한다.
    return map[y_pos - 1][x_pos- 1];
}
