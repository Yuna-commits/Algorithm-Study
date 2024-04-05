function solution(targets) {
    // 시작점을 기준으로 오름차순으로 정렬
    targets.sort((a, b) => a[1] - b[1]);
    let shoot = 0;
    let end = -1;
    for(let i =0; i< targets.length; i++){
        const [a, b] = targets[i]
        if(end <= a){
            shoot++
            end = b
        }
    }
    return shoot
}
