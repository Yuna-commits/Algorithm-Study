def solve(N, budgets, M):
    budgets.sort()  # 예산 요청을 정렬
    total = sum(budgets)  # 예산 요청의 총합 계산
    if total <= M:
        return max(budgets)  # 총합이 예산 내라면, 최대값 반환

    dum = M
    result = 0

    for i in range(N):
        current_budget = budgets[i]
        dum_city = N - i

        if dum >= current_budget * dum_city:
            dum -= current_budget
            result = current_budget
        else:
            result = dum // dum_city  # 남은 예산을 나누어줌
            break

    return result

# 입력 받는 부분
N = int(input())  # 지방의 수
budgets = list(map(int, input().split()))  # 각 지방의 예산 요청
M = int(input())  # 총 예산

# 해결 및 출력
answer = solve(N, budgets, M)
print(answer)