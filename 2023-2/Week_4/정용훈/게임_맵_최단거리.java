import java.util.LinkedList;
import java.util.Queue;

public class 게임_맵_최단거리 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(new int[][]{{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}});
    }
}

class Solution {
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1};
    static Queue<int[]> routeQueue;
    static boolean visited[][]; // 방문 체크 표
    static int n; // 지도의 가로 크기
    static int m; // 지도의 세로 크기

    public int solution(int[][] maps) {
        // 최단 경로를 위해서 bfs로 풀이
        // dfs 로 할 시 답을 찾아도 최단 경로인지 알 수 없음

        routeQueue = new LinkedList<>();

        n = maps.length;
        m = maps[0].length;

        // 방문했는지 확인하기 위해 maps 크기만큼 좌표 생성
        visited = new boolean[n][m];

        // 캐릭터의 시작 지점 (0, 0)을 큐에 넣고 방문 체크
        routeQueue.add(new int[]{0,0});
        visited[0][0] = true;

        while(!routeQueue.isEmpty()) { // 큐가 빌 때까지
            // 상하좌우를 탐색하기 위해 현재 위치를 가져오면서 큐에서 삭제
            int[] curPos = routeQueue.poll();
            int curX = curPos[0];
            int curY = curPos[1];

            for(int i=0; i<4; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];

                if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {    // maps을 벗어나지 않은 좌표에서
                    if(!visited[nextX][nextY] && maps[nextX][nextY] == 1) { // 방문하지 않았으면서 벽이 아니라면
                        maps[nextX][nextY] = maps[curX][curY] + 1;          // 다음 칸의 횟수를 현재 칸의 + 1 하기
                        routeQueue.add(new int[]{nextX, nextY});            // 다음 칸을 큐에 넣기
                        visited[nextX][nextY] = true;                       // 방문 처리 하기
                    }
                }
            }
        }

        // 도착지가 1이라면 도달하지 못했단 의미이므로 -1 리턴, 아니라면 값 그대로 리턴
        return maps[n-1][m-1] == 1 ? -1 : maps[n-1][m-1];
    }
}
