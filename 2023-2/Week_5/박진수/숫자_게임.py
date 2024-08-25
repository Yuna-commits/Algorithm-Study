def solution(A, B):
    answer = 0
    A.sort()        # A와 B 오름차순 정렬
    B.sort()
    j = 0
  
    # B 팀원들이 A 팀원들을 이길 수 없는 경우
    if min(A) > max(B):
        return 0
      
    # A와 B 비교
    for i in range(len(A)):
        if A[j] < B[i]:
            answer += 1
            j += 1
          
    return answer
