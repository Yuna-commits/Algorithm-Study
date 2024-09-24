const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
let index = 0;

rl.on('line', function (line) {
    input.push(line);
}).on('close', function () {
    const T = 3;  // 세 개의 입력이 주어진다고 명시되어 있음
    const results = [];

    for (let t = 0; t < T; t++) {
        const N = parseInt(input[index]);  // 동전 종류 N
        index++;

        const coins = [];
        for (let i = 0; i < N; i++) {
            const [value, count] = input[index].split(' ').map(Number);
            coins.push({ value, count });
            index++;
        }

        // 문제 해결 함수 호출
        const result = solve(N, coins);
        results.push(result);
    }

    // 출력
    results.forEach(result => console.log(result));
});

function solve(N, coins) {
    let total = 0;
    for(const coin of coins){
        total+=coin.value* coin.count;
    }

    if(total %2 !==0) return 0;

    const target = total / 2;

    const dp = new Array(target+1).fill(false);
    dp[0] = true;

    for (const coin of coins) {
        const { value: coinValue, count: coinCount } = coin;

        // 이전 상태를 복사하여 현재 동전의 영향만 고려
        const dpPrev = dp.slice();

        for (let amount = 0; amount <= target; amount++) {
            if (dpPrev[amount]) {
                for (let k = 1; k <= coinCount; k++) {
                    const nextAmount = amount + coinValue * k;
                    if (nextAmount > target) break;
                    dp[nextAmount] = true;
                }
            }
        }
    }

    

    return dp[target] ? 1: 0 ;
}