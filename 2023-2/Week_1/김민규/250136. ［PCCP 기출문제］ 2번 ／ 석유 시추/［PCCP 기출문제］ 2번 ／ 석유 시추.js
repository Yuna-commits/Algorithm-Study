
function solution(land) {
    let queue = [[0,0]];  // bfs 큐 (y,x)
    const n = land.length; // 세로
    const m = land[0].length; // 가로
    
    const dx = [-1,1,0,0] // 좌우이동
    const dy = [0,0,-1,1] // 상하이동
    
    let oilMap = new Map()
    
    for(let i =0; i<m; i++){
        for(let j =0; j<n; j++){
            let temp = 0;
            let indexSet = new Set();
            if(land[j][i] === 1){
                queue =[[j,i]];
                while(queue.length > 0){
                    let [y,x] = queue.shift()
                    if(land[y][x] ===1){
                        land[y][x] =0
                        temp++
                        if(!indexSet.has(x)){
                            indexSet.add(x)
                        }
                        for(let k =0; k<4; k++){
                            let ny = y + dy[k];
                            let nx = x + dx[k];
                 
                            
                            if(nx >=0 && ny >=0 && nx < m && ny <n && land[ny][nx] === 1 ){
                                queue.push([ny,nx])
                            }
                        }
                    }
                }
            }
            if(temp !== 0){
                for(let index of indexSet){
                    oilMap.set(index, oilMap.has(index) ? oilMap.get(index) + temp : temp)
                }
            }
            
        }
    }
      return Math.max(...oilMap.values())
}