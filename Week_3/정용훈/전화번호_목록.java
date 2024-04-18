import java.util.Arrays;

public class 전화번호_목록 {
    public static void main(String[] args) {
        Solution solution = new Solution();

        solution.solution(new String[]{"119", "84482", "119214"});
    }
}

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book); // 전화번호부 정렬 (문자열이기 때문에 정렬 시 사전식 정렬됨)

        // 사전식 정렬이 되었기 때문에 바로 이전 값이랑만 비교하면 됨
        // because 이전 비교가 false라는 건 사전 순으로 전전 값은 절대 prefix가 될 수 없음
        // ex) 110  111324  [???]  -> [???]의 값의 앞 세 글자는 절대 110이 될 수 없음 최소 111을 이상임
        for(int i=1; i<phone_book.length; i++) {
            if(phone_book[i].startsWith(phone_book[i-1])) {
                return false;
            }
        }

        return true;
    }
}
