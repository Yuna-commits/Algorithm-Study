#include <string>
#include <vector>
#include <queue>
#include <algorithm>


void bfs(int n, int start_node, std::vector<std::vector<int>>& set, std::vector<std::vector<int>>& graph)
{

    auto visited = std::vector<bool>(n + 1, false);
    auto que = std::queue<int>();

    que.push(start_node);
    visited[start_node] = true;

    while (!que.empty())
    {
        auto node = que.front();
        que.pop();

        for (auto i = 0; i < graph[node].size(); i++)
        {
            if (!visited[graph[node][i]])
            {
                visited[graph[node][i]] = true;
                set[graph[node][i]].push_back(start_node);
                for (auto j : set[start_node])
                    if(std::find(set[graph[node][i]].begin(), set[graph[node][i]].end(), j) == set[graph[node][i]].end())
                        set[graph[node][i]].push_back(j);
                que.push(graph[node][i]);
            }
        }
    }
}

int solution(int n, std::vector<std::vector<int>> results)
{
    auto win_set = std::vector<std::vector<int>>(n + 1);
    auto lose_set = std::vector<std::vector<int>>(n + 1);

    auto win_sorted_graph = std::vector<std::vector<int>>(n + 1);
    auto lose_sorted_graph = std::vector<std::vector<int>>(n + 1);

    for (auto& result : results)
    {
        auto winner = result[0];
        auto loser = result[1];

        win_sorted_graph[winner].push_back(loser);
        lose_sorted_graph[loser].push_back(winner);
    }

    for (auto i = 1; i <= n; i++)
        bfs(n, i, win_set, win_sorted_graph);
    for (auto i = 1; i <= n; i++)
        bfs(n, i, lose_set, lose_sorted_graph);

    auto answer = 0;
    for (auto i = 1; i <= n; i++)
        if (lose_set[i].size() + win_set[i].size() == n - 1)
            answer++;

    return answer;
}