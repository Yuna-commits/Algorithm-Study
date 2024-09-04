#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto input = std::string();
	std::cin >> input;

	auto a_count = 0;
	auto answer = static_cast<int>(input.length());
	for (const auto& item : input)
		if (item == 'a')
			a_count++;

	for (auto i = 0; i < input.length(); i++)
	{
		auto count = a_count;
		auto change_count = 0;

		for (auto j = i; j < i + input.length(); j++)
		{
			if (count == 0)
				break;

			if (input[j % input.length()] == 'b')
				change_count++;

			count--;
		}

		answer = std::min(answer, change_count);
	}
	std::cout << answer;

	return 0;
}