// 1. 브루트 포스?  > 될 것 같긴 했는데 별로였음
// 2. bfs?         > 현재 연산의 값과 인덱스를 따로 관리하는 게 별로였음
// 3. 백트래킹?     > 제일 직관적인 방법이었음 아니면 되돌아오면 그만이니깐

#include <string>
#include <vector>

auto g_numbers = std::vector<int>();
auto g_target = 0;

int back_tracking(int idx, int sum)
{
    if (idx == g_numbers.size())
        if (sum == g_target)
            return 1;
        else
            return 0;

    // 내부적으로 발생하는 연산들에 대하여 신경 쓸 필요가 없음
    // 백트래킹은 항상 모든 경우의 수를 보장하며 아니면 되돌아옴
    return back_tracking(idx + 1, sum + g_numbers[idx]) 
                + back_tracking(idx + 1, sum - g_numbers[idx]);
}

int solution(std::vector<int> numbers, int target)
{
    g_numbers = numbers;
    g_target = target;

    return back_tracking(0, 0);
}
