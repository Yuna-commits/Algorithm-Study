import java.util.HashSet;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(new String[]{"frodo", "fradi", "crodo", "abc123", "frodoc"}, new String[]{"fr*d*", "abc1**"});
    }
}

class Solution {
    String[] user_id;
    String[] regex_banned_id;
    HashSet<HashSet<String>> restrictedIdSet;

    public int solution(String[] user_id, String[] banned_id) {
        this.user_id = user_id;
        regex_banned_id = new String[banned_id.length];
        restrictedIdSet = new HashSet<>();

        // 정규표현식으로 변경
        for(int i=0; i< banned_id.length; i++) {
            regex_banned_id[i] = banned_id[i].replace("*", ".");
        }

        //
    }

    public void matches() {

    }
}