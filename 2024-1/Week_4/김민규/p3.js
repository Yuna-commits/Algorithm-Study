const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input;

rl.on('line', function (line) {
    input = parseInt(line.trim());
}).on('close', function () {
    // 입력: N자리 소수
    const N = input;

    function isPrime(num) {
        if (num < 2) return false;
        for (let i = 2; i <= Math.sqrt(num); i++) {
            if (num % i === 0) return false;
        }
        return true;
    }

    function findPrimes(currentNum, currentLength) {
        if(currentLength === N){
            console.log(currentNum)
            return;
        }

        for(let i = 1; i<=9; i++){
            const nextNum = currentNum * 10 + i
            if(isPrime(nextNum)){
                findPrimes(nextNum,currentLength+1)
            }
        }
    }


    findPrimes(2, 1);
    findPrimes(3, 1);
    findPrimes(5, 1);
    findPrimes(7, 1);
});