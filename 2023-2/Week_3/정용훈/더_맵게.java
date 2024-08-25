import java.util.*;

public class 더_맵게 {
    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.solution(new int[]{1, 2, 3, 9, 10, 12}, 7));

    }
}

class Solution {
    Queue<Integer> scovilleMinHeap;  // 스코빌 음식 최소 힙
    int count = 0;        // 음식을 섞은 횟수

    public int solution(int[] scoville, int K) {
        scovilleMinHeap = new PriorityQueue<>(Integer::compareTo); // 최소 힙 생성

        boolean answer = false; // 정답 조건을 만족했을 때 true를 가지는 변수

        for(int s : scoville) {        // 스코빌 음식, 최소 힙에 추가
            scovilleMinHeap.add(s);
        }

        while(scovilleMinHeap.size() >= 2) { // 스코빌 음식이 2개 이상이면 반복
            // 처음부터 모든 음식이 스코빌 조건을 만족할 수 있기 때문에 우선 확인 필요
            if(scovilleMinHeap.peek() >= K) {
                answer = true;
                break;
            }

            // 스코빌 조건 만족을 안하니까(위의 조건식) 음식 섞어서 다시 넣기
            scovilleMinHeap.add(scovilleOperation(scovilleMinHeap.poll(), scovilleMinHeap.poll()));
        }

        // 음식이 한 개가 남았을 때 스코빌 조건을 만족할 수도 있기 때문에 확인 필요
        if(scovilleMinHeap.size() == 1 && scovilleMinHeap.peek() >= K) {
            answer= true;
        }

        return answer ? count : -1;
    }

    public int scovilleOperation(int food_1, int food_2) {
        count++;
        return food_1 + (food_2 * 2);

    }
}


