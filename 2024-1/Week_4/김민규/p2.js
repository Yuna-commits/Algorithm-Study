const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input.push(line.trim());
}).on('close', function () {
    // 입력 처리
    const N = parseInt(input[0]);  // N개의 숫자
    const numbers = input[1].split(' ').map(Number);  // N개의 숫자 배열
    const operators = input[2].split(' ').map(Number);  // 덧셈, 뺄셈, 곱셈, 나눗셈의 개수

    let maxResult = -Infinity;
    let minResult = Infinity;
    function backtrack(idx, currentResult, add, sub, mul, div) {
        if(idx === N){
            maxResult = Math.max(maxResult,currentResult);
            minResult = Math.min(minResult,currentResult);
            return;
        }
        if(add > 0){
            backtrack(idx+1,currentResult+numbers[idx],add -1,sub,mul,div)
        }
        if(sub >0){
            backtrack(idx+1,currentResult-numbers[idx],add,sub-1,mul,div)
        }
        if(mul>0){
            backtrack(idx+1,currentResult*numbers[idx],add,sub,mul-1,div)
        }
        if(div>0){
            const nextResult = currentResult < 0 ? -Math.floor(Math.abs(currentResult) / numbers[idx]) :
                Math.floor(currentResult / numbers[idx]);
            backtrack(idx+1,nextResult,add,sub,mul,div-1)
        }
    }

    backtrack(1, numbers[0], operators[0], operators[1], operators[2], operators[3]);

    console.log(maxResult === 0 ? 0 : maxResult);
    console.log(minResult === 0 ? 0 : minResult);
});