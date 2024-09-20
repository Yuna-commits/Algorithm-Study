#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto N = 0, K = 0;
	std::cin >> N >> K;

	auto Si = std::vector<int>(N);
	for (auto i = 0; i < N; i++)
		std::cin >> Si[i];

	auto Di = std::vector<int>(N);
	for (auto i = 0; i < N; i++)
		std::cin >> Di[i];

	auto Ti = std::vector<int>(N);
	for (auto i = 0; i < K; i++)
	{
		for (auto j = 0; j < N; j++)
			Ti[Di[j] - 1] = Si[j];
		Si = Ti;
	}

	for (auto i = 0; i < N; i++)
		std::cout << Ti[i] << " ";

	return 0;
}