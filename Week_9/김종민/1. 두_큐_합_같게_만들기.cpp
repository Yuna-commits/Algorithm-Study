#include <string>
#include <vector>
#include <queue>

using LL = long long;

int solution(std::vector<int> queue1, std::vector<int> queue2)
{
    auto que1 = std::queue<int>();
    auto que2 = std::queue<int>();
    auto que1_sum = LL(0);      // 큐1 원소의 합
    auto que2_sum = LL(0);      // 큐2 원소의 합

    // 벡터의 요소들을 큐에 옮기는 과정이다.
    for (auto i = 0; i < queue1.size(); i++)
    {
        que1.push(queue1[i]);
        que1_sum += queue1[i];
        
        que2.push(queue2[i]);
        que2_sum += queue2[i];
    }

    // 양쪽의 큐가 원상태로 복귀될 때까지 합이 일치하는 순간이 없다면 답은 없다.
    for (auto answer = 0; answer < 4 * queue1.size() + 1; answer++)
    {
        if (que1_sum == que2_sum)
            return answer;

        // 큐1의 합이 큐2의 합보다 크다면
        if (que1_sum > que2_sum)
        {
            // 큐1의 원소를 큐2로 옮긴다.
            que1_sum -= que1.front();
            que2_sum += que1.front();
            que2.push(que1.front());
            que1.pop();
        }

        // 큐2의 합이 큐1의 합보다 크다면
        else if (que1_sum < que2_sum)
        {
            // 큐2의 원소를 큐1으로 옮긴다.
            que1_sum += que2.front();
            que2_sum -= que2.front();
            que1.push(que2.front());
            que2.pop();
        }
    }

    return -1;
}