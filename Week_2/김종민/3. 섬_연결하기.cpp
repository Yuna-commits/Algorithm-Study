// 1. 모든 정점이 연결되어야 함
// 2. 시작점이 정해지지 않음
// 3. 최소 비용
// => 크루스칼 알고리즘

#include <string>
#include <vector>
#include <algorithm>

auto g_costs = std::vector<std::vector<int>>();
auto g_size = 0;

// 유니온 파인드
// =============================================================
int Find(int node, const std::vector<int>& parents)
{
    if (parents[node] == node)
        return node;

    return Find(parents[node], parents);
}

void Union(int start, int end, std::vector<int>& parents)
{
    auto root_start = Find(start, parents);
    auto root_end = Find(end, parents);

    parents[root_end] = root_start;
}
// =============================================================

bool Compare(const std::vector<int>& v1, const std::vector<int>& v2)
{
    return v1[2] < v2[2];
}

int Kruskal()
{
    // 비용 순으로 오름차순 정렬
    std::sort(g_costs.begin(), g_costs.end(), Compare);

    // 유니온 파인드를 위하여 부모 노드 집합 번호를 설정
    auto parents = std::vector<int>(g_size);
    for (auto i = 0; i < g_size; i++)
        parents[i] = i;

    auto sum = 0;
    for (const auto& edge : g_costs)
    {
        auto start = edge[0], end = edge[1], cost = edge[2];

        // 사이클을 생성하지 않는 경우에만
        if (Find(start, parents) != Find(end, parents))
        {
            // 섬을 연결
            sum += cost;
            Union(start, end, parents);
        }
    }

    return sum;
}

int solution(int n, std::vector<std::vector<int>> costs)
{
    g_size = n;
    g_costs = costs;

    return Kruskal();
}