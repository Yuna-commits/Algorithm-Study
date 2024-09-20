#include <iostream>
#include <string>
#include <array>

#define MAX 50
using LL = long long;

auto arr = std::array<std::array<int, MAX + 1>, MAX + 1>();
auto answer = LL(0);

auto sum(int sy, int sx, int ey, int ex) -> LL
{
	auto temp_sum = LL(0);

	for (auto i = sy; i <= ey; i++)
		for (auto j = sx; j <= ex; j++)
			temp_sum += arr[i][j];

	return temp_sum;
}

auto Case1(int N, int M)
{
	if (M < 3)
		return;

	for (auto i = 0; i < M - 2; i++)
		for (auto j = 0; j < M - 1 - i; j++)
			answer = std::max(answer, sum(0, 0, N - 1, i) * sum(0, i + 1, N - 1, j) * sum(0, j + 1, N - 1, M - 1));
}

auto Case2(int N, int M)
{
	if (N < 3)
		return;

	for (auto i = 0; i < N - 2; i++)
		for (auto j = 0; j < N - 1 - i; j++)
			answer = std::max(answer, sum(0, 0, i, M - 1) * sum(i + 1, 0, j, M - 1) * sum(j + 1, 0, N - 1, M - 1));
}

auto Case3(int N, int M)
{
	if (N < 2 or M < 2)
		return;

	for (auto i = 0; i < N - 1; i++)
		for (auto j = 0; j < M - 1; j++)
			answer = std::max(answer, sum(0, 0, i, j) * sum(0, j + 1, i, M - 1) * sum(i + 1, 0, N - 1, M - 1));
}

auto Case4(int N, int M)
{
	if (N < 2 or M < 2)
		return;

	for (auto i = 0; i < N - 1; i++)
		for (auto j = 0; j < M - 1; j++)
			answer = std::max(answer, sum(0, 0, i, M - 1) * sum(i + 1, 0, N - 1, j) * sum(i + 1, j + 1, N - 1, M - 1));
}

auto Case5(int N, int M)
{
	if (N < 2 or M < 2)
		return;

	for (auto i = 0; i < N - 1; i++)
		for (auto j = 0; j < M - 1; j++)
			answer = std::max(answer, sum(0, 0, i, j) * sum(i + 1, 0, N - 1, j) * sum(0, j + 1, N - 1, M - 1));
}

auto Case6(int N, int M)
{
	if (N < 2 or M < 2)
		return;

	for (auto i = 0; i < N - 1; i++)
		for (auto j = 0; j < M - 1; j++)
			answer = std::max(answer, sum(0, 0, N - 1, j) * sum(0, j + 1, i, M - 1) * sum(i + 1, j + 1, N - 1, M - 1));
}

void Solution(int N, int M)
{
	Case1(N, M);
	Case2(N, M);
	Case3(N, M);
	Case4(N, M);
	Case5(N, M);
	Case6(N, M);
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto N = 0, M = 0;
	std::cin >> N >> M;

	for (auto i = 0; i < N; i++)
	{
		std::string input_col;
		std::cin >> input_col;
		for (auto j = 0; j < M; j++)
			arr[i][j] = input_col[j] - '0';
	}

	Solution(N, M);
	std::cout << answer;

	return 0;
}