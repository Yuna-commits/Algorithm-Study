#include <string>
#include <vector>
#include <queue>
#include <iostream>

int solution(int m, int n, std::vector<std::vector<int>> puddles)
{
	const int MOD = 1000000007;

	// 맵의 모든 좌표를 0으로 초기화한다.
	auto map = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));

	// 물 웅덩이의 좌표를 -1로 설정한다.
	for (auto& dim2 : puddles)
	{
		auto x = dim2[0] - 1;
		auto y = dim2[1] - 1;

		map[y][x] = -1;
	}

	// 메모이제이션을 모두 0으로 초기화한다.
	auto dp = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));

	// dp를 이용하여 경로를 계산한다.
	dp[0][0] = 1;
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < m; j++)
		{
			// 물 웅덩이 위치는 0으로 유지한다.
			if (map[i][j] == -1)
				dp[i][j] = 0;
			else
			{
				// 위쪽 누적 경로를 더한다.
				if (i > 0)
				{
					dp[i][j] += dp[i - 1][j];
					dp[i][j] %= MOD;
				}
				// 왼쪽 누적 경로를 더한다.
				if (j > 0)
				{
					dp[i][j] += dp[i][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}

	return dp[n - 1][m - 1];
}