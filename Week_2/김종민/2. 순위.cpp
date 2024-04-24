// 누구한테 졌는지, 누구한테 이겼는지 이 승패 결과만 알 수 있다면 문제를 해결할 수 있다.
// 즉, 진 사람 수 + 이긴 사람 수 = 전체 사람 수 - 1이다.

// 그렇다면 진 사람 수와 이긴 사람 수를 구할 알고리즘을 찾아야 한다.
// 만약, bfs를 통하여 현재 경기의 승패를 다른 인접 노드에 전파한다면?
// 구하고자 하는 진 사람 수와 이긴 사람 수를 구할 수 있을 것이다.

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

        // 각 인접 노드들을 방문하면서
        for (auto i = 0; i < graph[node].size(); i++)
        {
            // 어떤 인접 노드에 방문한 적이 없다면
            if (!visited[graph[node][i]])
            {
                visited[graph[node][i]] = true;
                set[graph[node][i]].push_back(start_node);    // 그 노드와의 경기 결과를 기재
                for (auto j : set[start_node])
                    // 이미 경기 결과를 아는 선수가 아닌 경우에만
                    if(std::find(set[graph[node][i]].begin(), set[graph[node][i]].end(), j) == set[graph[node][i]].end())
                        // 인접 노드에게 전파
                        set[graph[node][i]].push_back(j);
                que.push(graph[node][i]);
            }
        }
    }
}

int solution(int n, std::vector<std::vector<int>> results)
{
    // 이긴 사람과 진 사람을 저장할 각각의 집합
    auto win_set = std::vector<std::vector<int>>(n + 1);
    auto lose_set = std::vector<std::vector<int>>(n + 1);

    // 그래프를 인접 노드 배열로 구현(각각 이긴 사람 기준, 진 사람 기준으로)
    auto win_sorted_graph = std::vector<std::vector<int>>(n + 1);
    auto lose_sorted_graph = std::vector<std::vector<int>>(n + 1);

    // 초기화 블럭
    for (auto& result : results)
    {
        auto winner = result[0];
        auto loser = result[1];

        win_sorted_graph[winner].push_back(loser);
        lose_sorted_graph[loser].push_back(winner);
    }

    // 각 선수에 대해 이긴 사람을 구하기 위해 이긴 사람을 기준으로 bfs
    for (auto i = 1; i <= n; i++)
        bfs(n, i, win_set, win_sorted_graph);
    // 각 선수에 대해 진 사람을 구하기 위해 진 사람을 기준으로 bfs
    for (auto i = 1; i <= n; i++)
        bfs(n, i, lose_set, lose_sorted_graph);

    auto answer = 0;
    for (auto i = 1; i <= n; i++)
        // 만약 진 사람 수 + 이긴 사람 수 = 전체 사람 수 - 1이라면
        if (lose_set[i].size() + win_set[i].size() == n - 1)
            answer++;

    return answer;
}
