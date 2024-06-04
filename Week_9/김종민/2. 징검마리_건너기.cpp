// 생각 1: 브루트포스: 200_000 * 200_000_000 = 약 40억 딱봐도 시간 초과
// 생각 2: 
// - 이거 일일히 for문으로 숫자 줄여가면서 할 필요가 있나?
// - 결국에 k 개수만큼 0이 나오면 그때까지가 사람의 수 아닌가?
// - 예전에 백준에서 풀었던 최대로 통나무 자르기 문제랑 똑같네 > 이진 탐색
// https://www.acmicpc.net/problem/2805

#include <string>
#include <vector>
#include <algorithm>

using LL = long long;

// 건널 수 있는지 없는지를 판단하는 함수
bool CanCross(const std::vector<int>& stones, int k, int people)
{
    int skips = 0;
    for (const auto& stone : stones)
    {
        if (stone < people)
        {
            skips++;
            if (skips >= k)
                return false;
        }
        else
            skips = 0;
    }

    return true;
}

int solution(std::vector<int> stones, int k) 
{
    auto answer = LL(0);

    auto start = *std::min_element(stones.begin(), stones.end());   // 최소 숫자가 적힌 징검다리
    auto end = *std::max_element(stones.begin(), stones.end());     // 최대 숫자가 적힌 징검다리
    
    // 이진 탐색을 통해 k만큼의 높이를 가진 구간을 찾는다.
    while (start <= end)
    {
        auto mid = (start + end) / 2;
        if (CanCross(stones, k, mid))
            start = mid + 1;
        else
            end = mid - 1;
    }

    return end;
}