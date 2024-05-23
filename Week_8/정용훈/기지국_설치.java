import java.util.*;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        solution.solution(16, new int[]{1, 16}, 2);
    }
}

// 전파가 전달되는 곳을 true로 표시하는 n+1칸 짜리 boolean형 배열 생성(혼돈 방지 위해 인덱스 0은 사용 안함. 1부터 n까지를 사용)
// 처음부터 끝까지 순회하면서 true 곳은 패스, false인 곳을 만나면 기지국 설치 필요!
// false인 인덱스가 x라면 x를 true로 만들기 위한 최적의 기지국 설치 인덱스는 x+w임
// x ~ x+2*w를 true로 만들고 (x+2*w)+1 부터 다시 순회 시작
class Solution {
    boolean[] arrReachingWave;
    int w;

    int apartment = 1;
    int answer = 0;
    public int solution(int n, int[] stations, int w) {
        this.w = w;

        arrReachingWave = new boolean[n+1];

        for (int station : stations) {
            reachWaveBy(station);
        }

        while (apartment < n+1) {
            if (arrReachingWave[apartment]) { // 이미 기지국의 전파에 닿는 아파트라면
                apartment++;                  // 다음 아파트로 넘어가기

            } else { // 전파에 안 닿는 아파트일 때
                reachWaveBy(apartment + w); // 기지국 설치
                apartment+= 2*w + 1; // 아파트를 설치된 기지국 다음으로 이동
                answer++; // answer + 1 시키기
            }
        }

        return answer;
    }

    /**
     *
     * 설치된 station의 전파가 닿는 범위
     * 즉, station - w ~ station + w 까지를
     * true 값으로 바꾸는 메소드
     *
     */
    void reachWaveBy(int station) {
        if (station > arrReachingWave.length-1) station = arrReachingWave.length-1;
        Arrays.fill(arrReachingWave, Math.max(station - w, 1), Math.min(station + w + 1, arrReachingWave.length), true);
    }
}