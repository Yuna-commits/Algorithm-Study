public class 등굣길 {
    public static void main(String[] args) {
        So so = new So();
        System.out.println(so.solution(7, 4, new int[][]{{2, 1}, {2, 2}, {2, 3}, {4, 2}, {4, 3}, {4, 4}, {6, 2}, {6, 3}}));

    }
}

class Solution {

    final int INF = 99999999;
    int[][] routeCountBoard;
    int mod = 1_000_000_007;

    public int solution(int m, int n, int[][] puddles) {
        routeCountBoard = new int[m+1][n+1];

        // 출발점만 1 놓고 시작
        routeCountBoard[1][1] = 1;

        // 웅덩이는 지나갈 수 없도록 INF로 표시
        if (puddles[0].length > 0) { // 웅덩이의 입력이 0일 수도 있기 때문에 미리 체크
            for (int[] puddle : puddles) {
                routeCountBoard[puddle[0]][puddle[1]] = INF;
            }
        }

        // (x, y)를 가는 방법은 (x-1, y) + (x, y-1) 의 방법의 개수
        // 물 웅덩이가 있다면 없는 곳의 값으로 저장 Min((x-1, y), (x, y-1))
        // 좌측, 상 둘 다 물 웅덩이라면 역시 INF로 저장
        for(int i=1; i<m+1; i++) {
            for(int j=1; j<n+1; j++) {
                if(i==1 && j==1) {
                    continue; // [1][1]은 출발점이기 때문에 처리 불필요
                }

                if(routeCountBoard[i][j] == INF) { // 물 웅덩이라면
                    continue;
                }

                // 효율성 문제 때문에 이렇게 수정
                 if (routeCountBoard[i - 1][j] != INF) {
                     routeCountBoard[i][j] += routeCountBoard[i-1][j];
                 }

                 if (routeCountBoard[i][j - 1] != INF) {
                     routeCountBoard[i][j] += routeCountBoard[i][j-1];
                 }


//                // 상, 좌 중 하나가 물 웅덩이라면 최소값으로 저장, 둘 다 웅덩이라면 그냥 INF로 저장
//                if (routeCountBoard[i - 1][j] == INF || routeCountBoard[i][j - 1] == INF) {
//                    routeCountBoard[i][j] = Math.min(routeCountBoard[i - 1][j], routeCountBoard[i][j - 1]);
//                } else {
//                    routeCountBoard[i][j] = (routeCountBoard[i - 1][j] + routeCountBoard[i][j - 1]);
//                }

                if (routeCountBoard[i][j] > mod) {
                    routeCountBoard[i][j] %= mod;
                }
            }
        }

        return routeCountBoard[m][n];
    }
}
