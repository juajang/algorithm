# 풀이 참고 https://minnnne.tistory.com/44
cache = {}

def factorial(n):
    if n == 1:
        return 1
    if n in cache:
        return cache[n]
    else:
        cache[n] = n * factorial(n - 1)
        return cache[n]
    
def solution(n, k):
    answer = []
    numbers = [i for i in range(1, n + 1)]

    while n:
        width = factorial(n) / n
        curr = int((k - 1) // width)
        answer.append(numbers[curr])
        del numbers[curr]
        k -= curr * width
        n -= 1
        
    return answer