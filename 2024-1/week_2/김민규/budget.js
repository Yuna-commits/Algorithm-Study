// 입력 처리
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
rl.on('line', function (line) {
    input.push(line);
}).on('close', function () {
    // 입력 처리
    const N = parseInt(input[0]); // 지방의 수
    const budgets = input[1].split(' ').map(Number); // 각 지방의 예산 요청
    const M = parseInt(input[2]); // 총 예산

    // 여기서부터 문제 해결 로직을 작성하면 됩니다.

    // 출력 (최댓값을 구한 후 출력)
    const answer = solve(N, budgets, M);
    console.log(answer);
});

function solve(N, budgets, M) {
    budgets.sort((a, b) => a - b);
    const total = budgets.reduce((prev,cur)=> prev+cur)
    if(total <= M) return Math.max(...budgets)

    let current = 0
    let dum = M;
    let result = 0;

    for(let i = 0; i< N; i++){
        let currentBudget = budgets[i];
        let dumCity = N -i;

        if(dum >= currentBudget * dumCity){
            dum -= currentBudget
            result = currentBudget
        }else{
            result = Math.floor(dum / dumCity);
            break
        }
    }
    return result

}