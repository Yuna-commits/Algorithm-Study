import math

# 소수 판별 함수
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def find_primes(current_num, current_length, N):
    if current_length == N:
        print(current_num)
        return

    for i in range(1, 10):
        next_num = current_num * 10 + i
        if is_prime(next_num):
            find_primes(next_num, current_length + 1, N)

# 입력 받기
N = int(input().strip())

find_primes(2, 1, N)
find_primes(3, 1, N)
find_primes(5, 1, N)
find_primes(7, 1, N)