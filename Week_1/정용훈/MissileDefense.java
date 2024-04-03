import java.util.Arrays;
import java.util.Comparator;

public class MissileDefense {
    public static void main(String[] args) {
        Solution s = new Solution();

        int result = s.solution(new int[][]{{4, 5}, {4, 8}, {10,14}, {11,13}, {5,12}, {3,7},{1,4}});

        System.out.println(result);
    }
}

class Solution {
    public int solution(int[][] targets) {

        // 1차 시도에서는 start를 기준으로 정렬해서 실패.
        // 테스트 케이스 : {{1,2}, {3, 100}, {4,5}, {6,7}} 같은 경우 때문에 시작점을 기준으로 정렬하면 XX

        // end를 기준으로 정렬해야 끝선을 기준으로 다음 폭격기의 시작점과 비교가 됨.

        Arrays.sort(targets, Comparator.comparingInt(o -> o[1]));

        int s = 0; // 폭격 미사일의 시작 구간
        int e = 0; // 폭격 미사일의 끝 구간
        int end = 0; // 요격 시스템의 경계 끝 값

        int answer = 0; // 요격 미사일의 개수

        for(int i=0; i<targets.length; i++) {
            s = targets[i][0];
            e = targets[i][1];

            if(s >= end) { // 그 전 요격 시스템의 값이 현재 폭격 미사일의 시작 구간보다 작다면
                end = e; // 현재 폭격미사일의 끝 값을 경계 값으로 할당
                answer++;
            }
        }

        return answer;
    }
}