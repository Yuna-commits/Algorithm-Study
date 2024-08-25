def solution(M, N, puddles):
    dp = [[0 for _ in range(M+1)] for _ in range(N+1)]   # dp 테이블 초기화
    dp[1][1] = 1                                         # 시작 지점 위치

    for puddle in puddles:
        dp[puddle[1]][puddle[0]] = -1           # puddle 위치를 -1로 표시

    for i in range(1,N+1):
        for j in range(1,M+1):
            if dp[i][j] == -1:                  # puddle일경우 0으로 바꾸기
                dp[i][j] = 0
                continue                                  
            dp[i][j] += dp[i-1][j]+dp[i][j-1]    # dp 더하기
    return dp[N][M] % 1000000007
