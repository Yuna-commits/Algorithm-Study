import java.util.Arrays;
import java.util.stream.*;

public class 섬_연결하기 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(4, new int[][]{{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}});
    }
}

class Solution {
    int[] parent;

    public int find(int child) {
        if(parent[child] == child) return child;
        else return find(parent[child]);
    }

    public boolean union(int node_1, int node_2) {
        node_1 = find(node_1);
        node_2 = find(node_2);

        if(node_1 == node_2) return false;

        if(node_1 < node_2) {
            parent[node_2] = node_1;
        } else {
            parent[node_1] = node_2;
        }
        return true;
    }

    public int solution(int n, int[][] costs) {
        parent = new int[n];                  // find - union을 위한 부모 노드 배열
        int answer = 0;

        IntStream.range(0, parent.length)
                .forEach(i -> parent[i] = i);

        Arrays.sort(costs, (o1, o2) -> o1[2] < o2[2] ? -1 : 1);  // 연결 비용을 기준으로 오름차순 정렬

//        Arrays.stream(costs)
//                .flatMapToInt(Arrays::stream)
//                .forEach(System.out::println);

        boolean canConnect;             // 섬을 연결했을 때 사이클이 생기는지 확인하는 변수
        for(int[] cost : costs) {
            canConnect = union(cost[0], cost[1]); // 두 개의 섬을 연결했을 때
            if(canConnect) {                      // canConnect가 true라면 연결할 수 있으니 
                answer += cost[2];                // 비용 더해주기
            }
        }

        return answer;
    }


}