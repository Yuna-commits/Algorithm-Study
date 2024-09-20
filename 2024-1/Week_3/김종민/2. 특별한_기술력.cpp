// 1. 매번 가장 키가 큰 학생의 키를 가장 키가 큰 학생을 제외하고 다 더하면 되지 않을까? 
// > 시간 초과

// 2. 오름차순 정렬을 하고 나면, 매번 가장 키가 큰 학생을 찾을 필요가 없이 (N-1-i)이 가장 큰 학생이니 시간 초과가 없어지지 않을까? 
// > 시간 초과

// 3. 이중 for문이 문제임을 인식함. dp를 이용하는 것은 아닐까? dp를 사용하기 위해 반복되는 공식을 찾기 위한 시도
// 4. dp를 사용할 필요 없이 (N - 1 - i) * 2^(N - i - 1)을 다 더한 것이 정답임을 인식했다. 근데 틀렸다.
// > 오버플로우 및 예외 처리 X

// 5. 진짜 진짜 진짜 진짜 힘들게 나머지 연산자를 적용했지만 제곱 함수를 사용하다보니 또 이중 for문이 만들어졌다.

// 6. 어떻게 하면 제곱 함수의 for문을 없앨 수 있을까?
// > dp를 이용하여 제곱의 결과를 2^(N - 1)번째까지 미리 구해둔다면?
// > 성공

// 이게 어떻게 실버2 문제냐

#include <iostream>
#include <vector>
#include <algorithm>

using LL = long long;

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	const auto CONSTRAINT = 1000000007;

	auto N = 0;
	std::cin >> N;

	auto Ns = std::vector<int>(N);
	for (auto i = 0; i < N; i++)
		std::cin >> Ns[i];

	std::sort(Ns.begin(), Ns.end());

	auto mul = std::vector<LL>(N);
	mul[0] = 1;
	for (auto i = 1; i < N; i++)
		mul[i] = (2 * mul[i - 1]) % CONSTRAINT;

	auto answer = LL(0);
	for (int i = N - 1; i >= 0; i--)
		answer = (answer + (Ns[i] * (mul[i] % CONSTRAINT)) % CONSTRAINT) % CONSTRAINT;

	std::cout << answer;

	return 0;
}