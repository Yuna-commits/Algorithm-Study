#include <string>
#include <vector>
#include <queue>

int solution(std::vector<int> scoville, int K) 
{
	// 최소 힙을 구성한다.
	auto heap = std::priority_queue<int, std::vector<int>, std::greater<int>>();
	for (auto& food_scoville : scoville)
		heap.push(food_scoville);

	auto count = 0;
	while (!heap.empty())
	{
		// 1. 힙의 탑이 K보다 크다면 최소 힙의 특성 상 모든 원소가 K보다 크다.
		if (heap.top() >= K)
			return count;

		// 2. 1의 조건에 걸리지 않았는데, 원소가 2개 미만이라면 K만큼 만들 수 없다.
		if (heap.size() < 2)
			break;

		count++;

		auto first_mild = heap.top(); heap.pop();
		auto second_mild = heap.top(); heap.pop();

		auto new_food_scoville = first_mild + second_mild * 2;
		heap.push(new_food_scoville);
	}

	return -1;
}
