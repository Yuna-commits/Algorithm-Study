import java.util.Arrays;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();

        int re = s.solution(new String[]{"OOO", "XX.", "..X"});
        System.out.println("re = " + re);
    }
}

// 0 을 리턴해야 할 경우 즉, 규칙이 지켜지지 않은 게임인 케이스
// 1. O의 개수 - X의 개수 < 0 or > 1
// 2. O와 X가 같이 빙고
// 3. O 빙고 -> O의 개수 != X의 개수 + 1
// 4. X 빙고 -> O의 개수 != X의 개수

class Solution {
    String[] board = new String[3];
    boolean OisBingo; // O와 X가 빙고인지 체크
    boolean XisBingo;

    int countO; // O 의 개수
    int countX; // X 의 개수

    public int solution(String[] board) {
        this.board = board;

        count(); // O 와 X의 개수 세기

        if (!isRightTheCountDiff()) return 0; // O의 개수와 X의 개수가 올바른지 확인

        checkBingo('O');
        checkBingo('X');

        if(OisBingo && XisBingo) return 0; // O와 X 둘다 빙고일 때

        if(OisBingo && !XisBingo) {
            if(!isRightOnlyOBingoCase()) return 0;
        }

        if(!OisBingo && XisBingo) {
            if(!isRightOnlyXBingoCase()) return 0;
        }

        return 1;
    }

    public void count() {
        String s = board[0].concat(board[1]).concat(board[2]);

        for(char c : s.toCharArray()) {
            if(c == 'O') countO++;
            else if(c == 'X') countX++;
        }
    }

    public void checkBingo(char v) {
        // 가로 체크
        for(int i=0; i<3; i++) {
            boolean flag = true;
            for(int j=0; j<3; j++) {
                if(board[i].charAt(j) != v) {
                    flag = false;
                }
            }
            if (flag) {
                if(v == 'O') OisBingo = true;
                else XisBingo = true;

                return;
            }
        }

        // 세로 체크
        for(int i=0; i<3; i++) {
            boolean flag = true;
            for(int j=0; j<3; j++) {
                if(board[j].charAt(i) != v) {
                    flag = false;
                }
            }
            if (flag) {
                if(v == 'O') OisBingo = true;
                else XisBingo = true;

                return;
            }
        }

        // 대각선 체크
        if(board[0].charAt(0) == v && board[1].charAt(1) == v && board[2].charAt(2) == v) {
            if(v == 'O') OisBingo = true;
            else XisBingo = true;
        }
        if(board[0].charAt(2) == v && board[1].charAt(1) == v && board[2].charAt(0) == v) {
            if(v == 'O') OisBingo = true;
            else XisBingo = true;
        }


    }

    public boolean isRightTheCountDiff() { // 케이스 1
        int diff = countO - countX;

        return diff == 1 || diff == 0;
    }

    public boolean isRightOnlyOBingoCase() { // 케이스 3
        return countO - countX == 1;
    }

    public boolean isRightOnlyXBingoCase() { // 케이스 4
        return countO - countX == 0;
    }
}
