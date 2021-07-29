def solution(n):
    cache = [0] * (n + 1)
    cache[1] = 1
    if n > 1:
        cache[2] = 2
    
    for i in range(3, n + 1):
        cache[i] = (cache[i-1] + cache[i-2]) % 1234567
    
    return cache[n] 
    