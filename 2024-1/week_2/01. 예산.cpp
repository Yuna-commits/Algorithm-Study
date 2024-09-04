#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto region_count = 0;
	std::cin >> region_count;

	auto region_request = std::vector<int>(region_count);
	for (auto i = 0; i < region_count; i++)
		std::cin >> region_request[i];

	auto region_money = 0;
	std::cin >> region_money;

	auto region_max = 0;
	auto start = 1;
	auto end = *std::max_element(region_request.begin(), region_request.end());
	while (start <= end)
	{
		auto mid = (start + end) / 2;

		auto temp_region_max = 0;
		for (const auto& request : region_request)
		{
			if (mid > request)
				temp_region_max += request;
			else
				temp_region_max += mid;
		}

		if (temp_region_max > region_money)
			end = mid - 1;
		else if (temp_region_max <= region_money and region_max < temp_region_max)
			start = mid + 1;
	}
	std::cout << end;
	
	return 0;
}