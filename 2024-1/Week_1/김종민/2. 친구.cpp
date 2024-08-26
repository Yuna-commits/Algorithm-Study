#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto person_count = 0;
	std::cin >> person_count;

	auto bf_table = std::vector<std::string>(person_count);
	for (auto i = 0; i < person_count; i++)
		std::cin >> bf_table[i];

	auto friend_count_table = std::vector<int>(person_count);
	for (auto a = 0; a < person_count; a++)
	{
		auto friend_check_table = std::vector<bool>(person_count);
		for (auto b = 0; b < person_count; b++)
		{
			if (bf_table[a][b] == 'Y' && a != b)
			{
				friend_check_table[b] = true;

				for (auto c = 0; c < person_count; c++)
					if (bf_table[b][c] == 'Y' && a != c)
						friend_check_table[c] = true;
			}
		}

		for (auto i = 0; i < person_count; i++)
			if (friend_check_table[i])
				friend_count_table[a]++;
	}
	std::cout << *max_element(friend_count_table.begin(), friend_count_table.end());

	return 0;
}