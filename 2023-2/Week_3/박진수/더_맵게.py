import heapq
def solution(scoville, K):
    heapq.heapify(scoville)                 # 리스트를 최소 heap으로 변환
    answer = 0
    while 1:
        num1 = heapq.heappop(scoville)
        if num1 >= K:                       # 제일 맵지 않은 음식이 K보다 크면 answer 반환
            return answer
        if len(scoville) == 0:              # 음식이 없으면 -1 반환
            return -1
        else:
            num2 = heapq.heappop(scoville)
            heapq.heappush(scoville, num1+(num2*2))
            answer += 1
    return answer
