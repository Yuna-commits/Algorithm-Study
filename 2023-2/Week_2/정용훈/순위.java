public class 순위 {
    public static void main(String[] args) {
        Solution solution = new Solution();

        solution.solution(5, new int[][]{{4,3}, {4,2}, {3,2}, {1,2}, {2,5}});
    }
}

class Solution {
    boolean[][] winnerBoard;
    boolean[][] loserBoard;

    public int solution(int n, int[][] ratingBoard) {
        winnerBoard = new boolean[n+1][n+1];
        loserBoard = new boolean[n+1][n+1];

        int answer = 0;

        for(int[] rating : ratingBoard) {
            winnerBoard[rating[0]][rating[1]] = true;
            loserBoard[rating[1]][rating[0]] = true;
        }

        for(int k=1; k<n+1; k++) {         // 경로가 될 중간 노드
            for(int i=1; i<n+1; i++) {     // 시작 노드
                for(int j=1; j<n+1; j++) { // 끝 노드
                    if(winnerBoard[i][k] && winnerBoard[k][j]) {
                        winnerBoard[i][j] = true;   // 승자와 패자가 연결될 중간 선수가 있다면 승패여부를 알 수 있음
                    }

                    if(loserBoard[i][k] && loserBoard[k][j]) {
                        loserBoard[i][j] = true;
                    }
                }
            }
        }

        for(int i=1; i<n+1; i++) {
            int cntKnowRate = 0;
            for(int j=1; j<n+1; j++) {
                if(winnerBoard[i][j]) {
                    cntKnowRate++;
                }
                if(loserBoard[i][j]) {
                    cntKnowRate++;
                }
            }
            if(cntKnowRate == n-1) {
                answer++;
            }
        }

        return answer;
    }
}
