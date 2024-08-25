def solution(sticker):
    index = len(sticker)
    # 첫번째 스티커가 포함된 경우와 포함되지 않은 경우
    dp1 = [sticker[i] for i in range(0, index-1)]
    dp2 = [sticker[j] for j in range(1, index)]
    
    # 스티커가 2개 이하인 경우
    if index <= 2:
        return max(sticker)

    # i번째 스티커를 때는 경우와 때지 않는 경우 비교
    for i in range(1, index-1):
        if i == 1:
            dp1[i] = max(dp1[i-1], dp1[i])
            dp2[i] = max(dp2[i-1], dp2[i])
        else:
            dp1[i] = max(dp1[i-1], dp1[i-2] + dp1[i])
            dp2[i] = max(dp2[i-1], dp2[i-2] + dp2[i])

    # dp연산이 끝난 후 첫번째 스티커가 포함된 경우와 포함되지 않은 경우 비교
    return max(dp1[index-2], dp2[index-2])
