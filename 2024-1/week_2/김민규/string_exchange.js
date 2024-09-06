const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = '';

rl.on('line', function (line) {
    input = line;
}).on('close', function () {
    // 문제 해결 시작
    const result = solve(input);
    console.log(result);
});

function solve(str) {
    const n = str.length;

    const totalA = str.split('').filter(char => char === 'a').length;

    const doubledStr = str + str;

    let currentBCount = 0;
    for (let i = 0; i < totalA; i++) {
        if (doubledStr[i] === 'b') currentBCount++;
    }

    let minBCount = currentBCount;
    for (let i = 1; i < n; i++) {
        if (doubledStr[i - 1] === 'b') currentBCount--; // 앞의 문자를 제외
        if (doubledStr[i + totalA - 1] === 'b') currentBCount++; // 새로운 문자를 추가

        minBCount = Math.min(minBCount, currentBCount);
    }

    return minBCount;
}