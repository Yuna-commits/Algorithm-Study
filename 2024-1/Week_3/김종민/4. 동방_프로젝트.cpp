#include <iostream>
#include <vector>

const int MAX = 1000001;

auto parent = std::vector<int>(MAX);
auto rank = std::vector<int>(MAX);

void Init(int n)
{
	for (auto i = 1; i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

int Find(int room)
{
	if (parent[room] != room)
		parent[room] = Find(parent[room]);

	return parent[room];
}

void Union(int start, int end)
{
	auto root_start = Find(start);
	auto root_end = Find(end);

	if (root_start != root_end)
	{
		if (rank[root_start] < rank[root_end])
			parent[root_start] = root_end;
		else if (rank[root_start] > rank[root_end])
			parent[root_end] = root_start;
		else
		{
			parent[root_end] = parent[root_start];
			rank[root_start]++;
		}
	}
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto N = 0, M = 0;
	std::cin >> N >> M;

	Init(N);

	for (auto i = 0; i < M; i++)
	{
		auto start = 0, end = 0;
		std::cin >> start >> end;

		for (auto j = start; j < end; j++)
			Union(j, j + 1);
	}

	auto answer = 0;
	for (auto i = 1; i <= N; i++)
		if (Find(i) == i)
			answer++;
	std::cout << answer;

	return 0;
}