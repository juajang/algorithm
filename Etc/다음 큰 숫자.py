def count(n):
    total = 0
    while n >= 2:
        if n % 2:
            total += 1
        n = n // 2
    return total 

def solution(n):
    answer = n + 1
    while count(n) != count(answer):
        answer += 1
    return answer