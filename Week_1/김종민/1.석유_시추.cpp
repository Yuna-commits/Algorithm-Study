#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;

auto g_land = std::vector<std::vector<int>>();			// 맵 행렬을 저장할 배열
auto visited = std::array<std::array<int, 501>, 501>();		// 방문 여부를 저장할 배열
auto piece_map = std::map<int, int>();				// 석유 덩어리 크기를 저장할 해시테이블

auto dx = std::vector<int>{ 0, 0, -1, 1 };
auto dy = std::vector<int>{ -1, 1, 0, 0 };
auto pieces = 1;						// 석유 덩어리들을 구별해주기 위한 설정 변수 (1 ~ )
auto row = 0, col = 0;

void bfs(int x, int y);

int solution(std::vector<std::vector<int>> land) {
	int answer = 0;

	row = land.size();
	col = land[0].size();
	g_land = land;

	// 이동 가능한 좌표를 순회하면서 석유가 있는 좌표인지 확인하고 bfs
	for (auto i = 0; i < row; i++)
		for (auto j = 0; j < col; j++)
			if (!visited[i][j] and g_land[i][j] > 0)
				bfs(i, j);

	// 열벡터를 관찰하면서 총 연결된 석유 덩어리들의 값을
	// key를 사용하여 해시테이블을 통해서 더해줌
	for (auto i = 0; i < col; i++)
	{
		int temp_oil_amount = 0;
		auto oil_set = std::set<int>();

		for (auto j = 0; j < row; j++)
			oil_set.insert(g_land[j][i]);
		for (auto element : oil_set)
			temp_oil_amount += piece_map[element];

		// 전 열벡터와 현 열벡터의 값을 비교해가며 갱신
		answer = std::max(answer, temp_oil_amount);
	}

	return answer;
}

void bfs(int x, int y)
{
	auto oil_amount = 0;					// 석유 덩어리의 크기를 체크하는 변수
	std::queue<std::pair<int, int>> que;
	que.push(std::make_pair(x, y));
	g_land[x][y] = pieces;	
	visited[x][y] = 1;

	while (!que.empty())
	{
		auto x = que.front().first;
		auto y = que.front().second;
		que.pop();
		oil_amount++;					// 루프를 돌 경우에는 석유가 연결되어 있는 경우이므로 증가

		// 현재 좌표에서 상하좌우로 이동을 해보면서
		for (auto i = 0; i < 4; i++)
		{
			auto nx = x + dx[i];
			auto ny = y + dy[i];

			// 맵 밖을 뚫고 나간다면
			if (nx < 0 or ny < 0 or nx >= row or ny >= col)
				continue;

			// 현재 좌표에 석유가 존재하고 그 곳을 방문한 적이 없다면
			if (g_land[nx][ny] == 1 and !visited[nx][ny])
			{
				g_land[nx][ny] = pieces;
				visited[nx][ny] = 1;
				que.push(std::make_pair(nx, ny));
			}
		}
	}

	// 현재 석유 덩어리 값을 key로, 그리고 석유 덩어리의 크기를 value로
	// 해시테이블을 사용하여 O(1)로 접근하도록 설정
	piece_map[pieces++] = oil_amount;
}
