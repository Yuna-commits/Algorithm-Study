#include <iostream>
#include <vector>

#define MAX_MONEY 50000
using PII = std::pair<int, int>;

auto coins = std::vector<PII>(101);
auto dp = std::vector<int>(MAX_MONEY + 1);

int CanDivide(int cnt, int sum)
{
	if (sum % 2)
		return 0;

	for (auto i = 1; i <= cnt; i++)
	{
		auto coin_value = coins[i].first;
		auto coin_count = coins[i].second;

		for (auto j = MAX_MONEY; j >= 0; j--)
			if (dp[j] == 1)
				for (auto k = 1; k <= coin_count && j + coins[i].first * k <= MAX_MONEY; k++)
					dp[j + coin_value * k] = 1;
	}

	return dp[sum / 2] ? 1 : 0;
}

void ClearDP()
{
	dp[0] = 1;
	for (auto i = 1; i < 50001; i++)
		dp[i] = 0;
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	for (auto repeat = 0; repeat < 3; repeat++)
	{
		ClearDP();
		auto coin_type_count = 0;
		std::cin >> coin_type_count;

		auto coin_sum = 0;
		for (auto type = 1; type <= coin_type_count; type++)
		{
			std::cin >> coins[type].first >> coins[type].second;
			coin_sum += coins[type].first * coins[type].second;
		}

		std::cout << CanDivide(coin_type_count, coin_sum) << '\n';
	}

	return 0;
}