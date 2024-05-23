// 투포인터 응용 같음
// 문제는 다 포함되었는지 아닌지를 체크할 방법

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

std::vector<int> solution(std::vector<std::string> gems) 
{
	// 보석들의 목록을 만드는 과정
	auto gem_set = std::set<std::string>(gems.begin(), gems.end());
	auto gem_count = gem_set.size();

	std::unordered_map<std::string, int> gem_check;
	auto start = 0;
	auto min_length = static_cast<int>(gems.size()) + 1;
	auto min_start = 0;

	for (auto end = 0; end < gems.size(); end++)
	{
		gem_check[gems[end]]++;

		// 모든 보석을 포함하는 구간을 찾는 과정
		while (gem_check.size() == gem_count)
		{
			if (end - start + 1 < min_length)
			{
				min_length = end - start + 1;
				min_start = start;
			}

			gem_check[gems[start]]--;
			if (gem_check[gems[start]] == 0)
				gem_check.erase(gems[start]);

			start++;
		}
	}

	return { min_start + 1, min_start + min_length };
}