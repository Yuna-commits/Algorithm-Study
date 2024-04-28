// 1번째 아이디어: 단방향 링크드 리스트 활용
// - 시간 복잡도: O(n^2) > 효율성 검사에서 탈락

// 2번째 아이디어: 이거 굳이 A 형태에 맞춰서 검사할 필요가 있나? 그리디.
// - 어차피 A에 이기게 하려면 둘 다 정렬해서 비교하면 그만임 : A[i] < B[i]

// 3번째 아이디어: A[i] < B[i]만 비교해서는 안된다.
// - A[i]는 해결이 안된 상태이기 때문에 인덱스를 따로 관리해주어야 함. 

#include <vector>
#include <algorithm>

int solution(std::vector<int> A, std::vector<int> B)
{
    // A와 B를 오름차순으로 정렬한다.
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    auto answer = 0;
    auto a_idx = 0;    // A의 인덱스를 관리해줄 변수
    for (auto i = std::size_t(0); i < A.size(); i++)
        if (A[a_idx] < B[i])
        {
            answer++;
            a_idx++;    // B가 이긴 경우에만 다음 A 선수를 데려옴.
        }

    return answer;
}
