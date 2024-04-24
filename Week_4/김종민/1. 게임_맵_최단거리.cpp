#include <vector>
#include <queue>

using pii = std::pair<int, int>;

auto map = std::vector<std::vector<int>>();
auto visited = std::vector<std::vector<int>>();

auto dx = std::vector<int>{ 1, -1, 0, 0 };
auto dy = std::vector<int>{ 0, 0, 1, -1 };

auto x_pos = 0;
auto y_pos = 0;

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

    return map[y_pos - 1][x_pos- 1];
}