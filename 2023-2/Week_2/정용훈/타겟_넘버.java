import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        solution.solution(new int[]{1, 2, 3, 4}, 6);

    }
}

class Solution {

    public int solution(int[] numbers, int target) {

        return dfs(numbers, target, 0, 0);
    }

    public int dfs(int[] numbers, int target, int sum, int depth) {
        int answer = 0;

        if(depth == numbers.length) {
            if(sum == target) {
                return 1;
            }
            return 0;
        }

        answer += dfs(numbers, target, sum + numbers[depth], depth + 1);
        answer += dfs(numbers, target, sum - numbers[depth], depth + 1);

        return answer;
    }
}
