import java.util.Arrays;

public class 구명보트 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(new int[]{70, 50, 80, 50}, 100);
    }

}

class Solution {
    // 오름차순 정렬 후 투포인터 이용하여 필요한 보트의 개수 계산

    int frontPointer;
    int rearPointer;
    int count; // 구멍 보트 개수

    public int solution(int[] people, int limit) {
        Arrays.sort(people);

        frontPointer = 0;
        rearPointer = people.length - 1;

        count = 0;

        while(frontPointer < rearPointer) { // 두 개의 포인터가 만나거나 크로스될 때까지 실행
            int sum = people[frontPointer] + people[rearPointer];

            if(sum <= limit) { // 두 명의 합이 무게 제한에 안 걸린다면
                count++;    // 구명 보트 개수
                frontPointer++; // 앞쪽 포인터 밀고
                rearPointer--; // 뒤쪽 포인터 땡기고
            } else { // 무게 제한보다 몸무가 합이 무겁다면
                count++; // 무거운 사람 한 명만 혼자 보트 태우고
                rearPointer--; // 한 단계 가벼운 사람으로 포인터 가리키기
            }

        }

        if(frontPointer == rearPointer) {
            count++;
        }

        return count;
    }
}