import java.util.*;

public class 보석_쇼핑 {
    public static void main(String[] args) {
        Solution solution = new Solution();

        solution.solution(new String[]{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
    }
}

// 투포인터 이용 풀이
// 보석 종류의 개수를 파악
// 투포인터의 윈도우 안에 보석의 모든 종류가 있을 때의 경우로 조건 만족 확인
// 우측 포인터를 하나씩 증가시키면서 윈도우 움직이다가
// 좌측 포인터를 움직이면서 좌측 포인터의 위치의 보석이 2개 이상일 때는
// 그 보석은 중복이어서 없어도 되므로 좌측 포인터 하나 다시 이동시키기

class Solution {
    Map<String, Integer> gemMap; // <보석의 이름, 윈도우 내 Key 보석의 개수>
    public int[] solution(String[] gems) {
        // 보석의 종류 개수 파악
        int kind = new HashSet<>(Arrays.asList(gems)).size();

        gemMap = new HashMap<>();

        int[] answer = new int[2]; // 최종 리턴 값 [시작 진열대 번호, 끝 진열대 번호]
        int length = Integer.MAX_VALUE; // 구간의 길이의 최소값을 파악하기 위해 최대값으로 초기화
        int L = 0; // 좌측 포인터는 0부터 시작

        for (int R = 0; R < gems.length; R++) { // 우측 포인터 0부터 시작해서 끝까지 이동
            // gemMap에다가 우측 포인터의 위치에 있는 보석의 개수 1 증가시키기
            gemMap.put(gems[R], gemMap.getOrDefault(gems[R], 0)+1);

            while(gemMap.get(gems[L]) > 1) { // 좌측 포인터의 보석이 Map에 2개 이상일 때는
                gemMap.put(gems[L], gemMap.get(gems[L])-1); // 중복 보석이므로 굳이 가지고 있을 필요 없기 때문에
                L++;                                        // 좌측 포인터 하나 증가시키기
            }

            if (gemMap.size() == kind && length > (R-L)) { // 윈도우 안에 모든 보석의 종류가 있으면서 구간 길이를 줄일 수 있는 경우일 때
                length = R-L;
                answer[0] = L+1; // 문제에서 진열장은 1부터 시작하므로 인덱스에서 1 더해주어야 함
                answer[1] = R+1;
            }
        }

        return answer;
    }
}