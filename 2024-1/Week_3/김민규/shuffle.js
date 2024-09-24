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
        const [N, K] = input[0].split(' ').map(Number);  // N: 카드 개수, K: 셔플 횟수
        const shuffledCards = input[1].split(' ').map(Number);  // K번 셔플한 후 카드 배열
        const D = input[2].split(' ').map(Number);  // D 배열
        let currentArray = [...shuffledCards]
        // 여기서부터 원래 카드 복구 로직을 구현하시면 됩니다.
        let count = K
        // D가 4,3,1,2,5 면 4번 자리에 있는 카드를 1번 자리로 3번 자리에 있는 카드를 2번 자리로..
        while(count > 0){
            let temp = []
            for(let i =0; i<N; i++){
                temp[D[i]-1] = currentArray[i]
            }
            currentArray = [...temp]
            count--
        }
        console.log(currentArray);
        return currentArray
    });