function solution(n, stations, w) {
    let count = 0;  // 필요한 추가 기지국의 수
    let current = 1;  // 현재 위치 (1부터 시작)
    
    for (let i = 0; i < stations.length; i++) {
        let leftBoundary = stations[i] - w;  // 현재 기지국의 왼쪽 범위
        if (current < leftBoundary) {
            let uncoveredLength = leftBoundary - current;  
            count += Math.ceil(uncoveredLength / (2 * w + 1));  
        }
        current = stations[i] + w + 1;  
    }
    
    // 마지막 기지국 이후의 범위를 처리
    if (current <= n) {
        let uncoveredLength = n - current + 1;
        count += Math.ceil(uncoveredLength / (2 * w + 1));
    }
    
    return count;
}
