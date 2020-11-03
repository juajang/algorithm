dx = [1, 0]
dy = [0, 1]
cache = {}

def dp(x, y, m, n, puddles):
    if (x, y) in cache:
        return cache[(x, y)]
    if x == m and y == n:
        cache[(x, y)] = 1
        return cache[(x, y)]
    cache[(x, y)] = 0
    for i in range(2):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 1 or nx > m or ny < 1 or ny > n:
            continue
        flag = False
        for px, py in puddles:
            if px == x and py == y:
                flag = True
                break
        if flag:
            break
        cache[(x, y)] = (dp(nx, ny, m, n, puddles) + cache[(x, y)]) % (10 ** 9 + 7)
    return cache[(x, y)]
        
def solution(m, n, puddles):
    answer = dp(1, 1, m, n, puddles)
    return answer