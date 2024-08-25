def solution(phone_book):
    phone_book.sort()                       # 정렬
    for i in range(len(phone_book)-1):
        num1 = phone_book[i]
        num2 = phone_book[i+1]
        if num1 == num2[:len(num1)]:        # num1과 num1의 길이까지의 num2를 비교
            return False
    return True
