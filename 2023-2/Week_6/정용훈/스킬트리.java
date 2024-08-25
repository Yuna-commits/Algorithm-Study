public class 스킬트리 {
    public static void main(String[] args) {
        Sol sol = new Sol();

        sol.solution("CBD", new String[]{"BACDE", "CBADF", "AECB", "BDA"});
    }
}


// skill에 있는 스킬들의 순서만이 포인트
// 그 외 나머지 알파벳 스킬들은 상관이 없기 때문에 지워도 됨

// skill_trees의 모든 요소들은 skill의 각 스킬이 아니면 replace("")

// 앞의 스킬부터 있는지 확인

class Sol {
    char[] preSkillArray;
    boolean[] alphabetCheckingArray; // 선행 스킬에 포함된 스킬인지 확인하기 위한 배열
    int answer = 0;

    public int solution(String preSkills, String[] skill_trees) {
        preSkillArray = preSkills.toCharArray();
        alphabetCheckingArray = new boolean[26];

        // preSkills들만 true 값 처리
        for(char preSkill : preSkillArray) {
            alphabetCheckingArray[preSkill - 'A'] = true;
        }

        // skill_trees의 요소들을 순회하면서
        for(String skillTree : skill_trees) {
            // skill의 한 문자씩 처리
            int index = 0;

            // 모든 스킬트리가 선행 스킬이 아닐 수 있기 때문에 true 값으로 초기화해놓기
            boolean isRightTree = true;
            for(char skill : skillTree.toCharArray()) {
                // 선행 스킬에 포함되지 않은, 순서에 상관 없는 스킬이라면 다음 스킬로 넘어감
                if(!alphabetCheckingArray[skill - 'A']) {
                    continue;
                }

                // 선행 스킬 트리의 순서에 맞는지 비교, 다르면 continue
                if(!(skill == preSkillArray[index])) {
                    isRightTree = false;
                    break;
                }

                isRightTree= true;
                index++;
            }

            if(isRightTree) answer++;
        }

        System.out.println("answer = " + answer);
        return answer;
    }
}
