// 아이디어 1: 원으로 돌려가면서 합을 계산해보자.
// - 매우 비효율적이고 하다가 지쳐버림.

// 아이디어 2: 아이디어 1에서 합을 계산하는 도중 점화식 발견 + 원으로 돌릴 필요가 없다는 것을 발견
// - dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);

// 아이디어 3: 시작 스티커를 뜯느냐 안 뜯느냐가 경우의 수를 나누는 것을 알아냄.
// - 즉, 시작 스티커를 뜯고 시작한 합과 시작 스티커를 안 뜯고 시작한 합의 최대 값을 비교하면 된다.

#include <vector>
#include <algorithm>

int solution(std::vector<int> sticker) 
{
    auto size = sticker.size();

    // 스티커가 한 개인 경우
    if (size == 1)
        return sticker[0];

    auto dp = std::vector<int>(size);

    // 1. 시작 스티커를 뜯어내는 경우
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for (int i = 2; i < size - 1; i++)
        dp[i] = std::max(dp[i - 1], dp[i - 2] + sticker[i]);

    // 마지막 스티커를 뜯지 않은 경우가 최대값
    auto max_sum = dp[size - 2];

    // 2. 시작 스티커를 뜯어내지 않는 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i < size; i++)
        dp[i] = std::max(dp[i - 1], dp[i - 2] + sticker[i]);

    // 마지막 스티커를 뜯은 경우가 최대값
    max_sum = std::max(max_sum, dp[size - 1]);

    return max_sum;
}
