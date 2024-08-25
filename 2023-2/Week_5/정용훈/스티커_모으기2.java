import java.util.Arrays;

public class 스티커_모으기2 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(new int[]{1});
    }
}

class Solution {
    int[] includeFirstList;
    int[] includeLastList;


    public int solution(int sticker[]) {
        if(sticker.length == 1) {
            return sticker[0];
        }


        includeFirstList = Arrays.copyOfRange(sticker, 0, sticker.length - 1);
        includeLastList = Arrays.copyOfRange(sticker, 1, sticker.length);

        for (int i = 1; i < includeFirstList.length; i++) {
            if (i > 1) {
                includeFirstList[i] = Math.max(includeFirstList[i - 1], includeFirstList[i - 2] + includeFirstList[i]);
            } else {
                includeFirstList[i] = Math.max(includeFirstList[i - 1], includeFirstList[i]);
            }
        }

        for (int i = 1; i < includeLastList.length; i++) {
            if (i > 1) {
                includeLastList[i] = Math.max(includeLastList[i - 1], includeLastList[i - 2] + includeLastList[i]);
            } else {
                includeLastList[i] = Math.max(includeLastList[i - 1], includeLastList[i]);
            }
        }

        return Math.max(includeFirstList[includeFirstList.length - 1], includeLastList[includeLastList.length - 1]);
    }
}
