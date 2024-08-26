#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto lan_count = 0, target_count = 0;
	std::cin >> lan_count >> target_count;

	auto lan_vec = std::vector<long long>(lan_count);
	for (auto i = 0; i < lan_count; i++)
		std::cin >> lan_vec[i];

	// binary search
	auto start = 1;
	auto end = *max_element(lan_vec.begin(), lan_vec.end());
	auto max_length = 0;
	while (start <= end)
	{
		auto cut_length = (start + end) / 2;
		auto cut_lan_count = 0;

		if (cut_length == 0)
			break;

		for (auto item : lan_vec)
			cut_lan_count += item / cut_length;

		if (cut_lan_count < target_count)
			end = cut_length - 1;
		else if (cut_lan_count >= target_count and max_length < cut_length)
		{
			max_length = cut_length;
			start = cut_length + 1;
		}
		else
			break;
	}
	std::cout << max_length;

	return 0;
}