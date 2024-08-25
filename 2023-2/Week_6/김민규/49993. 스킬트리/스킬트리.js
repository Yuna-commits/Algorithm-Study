function solution(skill, skill_trees) {
    var answer = 0; // 유효한 스킬 트리의 개수를 0으로 초기화
    const skills = skill.split("");

    const filteredSkills = skill_trees.map(skillTree => {
        return skillTree.split('').filter(char => skills.includes(char)).join('');
    });

    function isInOrder(str, order) {
        let lastIndex = -1; 
        for (let i = 0; i < str.length; i++) {
            const index = order.indexOf(str[i]);
            if (index === -1) { 
                continue;
            }
            if (index < lastIndex || index > lastIndex + 1) { // 현재 문자의 인덱스가 이전 문자의 인덱스보다 작거나, 바로 다음 순서가 아니면 순서가 맞지 않음
                return false;
            }
            lastIndex = index; 
        }
        return true;
    }
    console.log('filteredSkills',filteredSkills)
    const result = filteredSkills.filter(skillTree => isInOrder(skillTree, skill));
    answer = result.length; 
    return answer;
}
