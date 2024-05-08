import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class 숫자_게임 {
    public static void main(String[] args) {
        Sol sol = new Sol();

        sol.sol(new int[]{5,1,3,7}, new int[]{2, 2, 6, 8});
    }
}

class Sol {
    // 아이디어 최소힙 이용

    // 1. A와 B 둘다 최소힙 이용하여 오름차순으로 정렬
    // 2. 맨 앞 요소 꺼내서 비교
    // 3.1 if(A<B) -> answer++; 둘 다 버리기
    // 3.2 A>=B -> B는 모든 A보다 작은 것이기 때문에 카드 버리고 A는 가지고 있기
    // 4. 새롭게 카드 뽑아서 비교 반복
    // until B의 힙이 빌 때까지

    PriorityQueue<Integer> teamAQueue;
    PriorityQueue<Integer> teamBQueue;

    int answer=0;

    public int sol(int[] A, int[] B) {
        teamAQueue = new PriorityQueue<>(Integer::compareTo);
        teamAQueue.addAll(Arrays.stream(A).boxed().collect(Collectors.toList()));

        teamBQueue = new PriorityQueue<>(Integer::compareTo);
        teamBQueue.addAll(Arrays.stream(B).boxed().toList());

        int numberA;
        int numberB;

        while (!teamBQueue.isEmpty()) {
            numberA = teamAQueue.peek();
            numberB = teamBQueue.peek();

            if (numberA < numberB) {
                answer++;
                teamAQueue.poll();
            }

            teamBQueue.poll();
        }
        return answer;
    }
}
