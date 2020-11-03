def solution(n):
    cache = [0] * 60010
    cache[1] = 1
    cache[2] = 2
    for i in range(3, n + 1):
        cache[i] = (cache[i - 1] + cache[i - 2]) % (10 ** 9 + 7)
    return cache[n]