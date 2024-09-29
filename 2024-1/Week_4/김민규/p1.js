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
    const [N, M] = input[0].split(' ').map(Number);  // N: 행, M: 열
    const grid = input.slice(1).map(line => line.split(' ').map(Number));  // 0: 빈 칸, 1: 아기 상어 있는 칸


    const d = [
        [-1, 0], [1, 0], [0, -1], [0, 1],  // 상하좌우
        [-1, -1], [-1, 1], [1, -1], [1, 1] // 대각선
    ];

    function bfs(grid,N,M){
        const queue = [];
        const visited = Array.from({length:N}, () => Array(M).fill(false));
        for(let i =0; i< N ; i++){
            for(let j =0; j<M; j++){
                if(grid[i][j] === 1){
                    queue.push([i,j])
                    visited[i][j] = true;
                }
            }
        }
        let maxDistance = 0;

        while(queue.length > 0){
            const [x,y] = queue.shift();
            for(const [dx,dy] of d){
                const nx = x +dx;
                const ny = y +dy;

                if(nx >=0 && nx <N && ny >=0 && ny < M && !visited[nx][ny]){
                    queue.push([nx,ny]);
                    visited[nx][ny] = visited[x][y] + 1;  // 이전 칸에서의 거리를 기반으로 기록
                    maxDistance = Math.max(maxDistance, visited[nx][ny] - 1);  // 거리를 업데이트
                }
            }
        }
        console.log(maxDistance)
    }

    bfs(grid,N,M);
});