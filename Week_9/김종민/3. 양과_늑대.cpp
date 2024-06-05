#include <string>
#include <vector>
#include <iostream>

auto max_sheep = 0;			// 최대로 구할 수 있는 양의 수
auto start_flag = true;		// 시작할 때 양의 수와 늑대의 수가 같기 때문에 이를 배제하기 위한 변수

void dfs(const std::vector<int>& info, const std::vector<std::vector<int>>& tree, 
						int cur_sheep, int cur_wolf, std::vector<int> next_nodes)
{
	// 모두 잡아먹혔다면 돌아간다.
	if (!start_flag and cur_sheep <= cur_wolf)
		return;

	if (start_flag)
		start_flag = false;

	max_sheep = std::max(max_sheep, cur_sheep);

	for (auto i = size_t(0); i < next_nodes.size(); i++)
	{
		auto next = next_nodes[i];

		// 방문한 노드와 방문할 노드를 벡터에 정리한다.
		auto new_next_nodes = next_nodes;
		new_next_nodes.erase(new_next_nodes.begin() + i);
		for (const auto& child : tree[next])
			new_next_nodes.push_back(child);

		if (info[next] == 0)
			dfs(info, tree, cur_sheep + 1, cur_wolf, new_next_nodes);
		else
			dfs(info, tree, cur_sheep, cur_wolf + 1, new_next_nodes);
	}
}

int solution(std::vector<int> info, std::vector<std::vector<int>> edges)
{
	// 이진 트리 tree를 생성한다.
	auto tree = std::vector<std::vector<int>>(info.size());
	for (const auto& edge : edges)
		tree[edge[0]].push_back(edge[1]);

	// 다음에 방문할 노드를 결정할 목록을 만든다.
	auto next_nodes = std::vector<int>{0};

	dfs(info, tree, 0, 0, next_nodes);

	return max_sheep;
}