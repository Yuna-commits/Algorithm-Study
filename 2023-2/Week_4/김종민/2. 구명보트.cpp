#include <string>
#include <vector>
#include <deque>
#include <algorithm>

int solution(std::vector<int> people, int limit) 
{
	// 덱을 사용하여 양쪽에서 사람을 빼며 정리한다.
	auto deque = std::deque<int>();
	for (const auto& element : people)
		deque.push_back(element);

	// 내림차순으로 덱을 정렬한다.
	std::sort(deque.begin(), deque.end(), std::greater<>());

	auto answer = 0;
	while (deque.size() >= 2)
	{
		// 무거운 친구는 일단 태워보내야 한다.
		auto heaviest = deque.front();
		deque.pop_front();

		// 가벼운 친구는 끼워보낼수 있다면 태워보내야 한다.
		auto lightest = deque.back();
		if (heaviest + lightest <= limit)
			deque.pop_back();

		answer++;
	}

	// 가벼운 친구가 혼자 남는 경우가 존재할 수도 있다.
	if (!deque.empty())
		answer++;

	return answer;
}