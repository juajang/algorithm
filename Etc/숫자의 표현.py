def find(start, n):
    s = 0
    for i in range(start, n + 1):
        s += i
        if s == n:
            return True
        elif s > n:
            return False

def solution(n):
    answer = 0
    for i in range(1, n + 1):
        if find(i, n):
            answer += 1
    return answer