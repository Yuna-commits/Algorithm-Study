#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> targets)
{
	std::sort(targets.begin(), targets.end());				// 오름차순 정렬

	auto answer = 0;
	auto shoot_count = 1;
	auto end_interval = -1;

	for (const auto& target : targets)
	{
		// 이전 미사일의 x.end가 현재 미사일의 x.start보다 작다면
		if (end_interval <= target[0])
		{
			answer++;						// 동시 요격이 불가능함
			end_interval = target[1];
		}
		else
			// 요격 구간을 점점 좁혀 나가야 함
			end_interval = std::min(end_interval, target[1]);
	}

	return answer;
}
