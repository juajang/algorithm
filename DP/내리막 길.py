import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

M, N = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(M)]

cache = {}

def DP(x, y):
    if cache.get((x, y)) is not None:
        return cache[(x, y)]

    if x == M - 1 and y == N - 1:
        cache[(x, y)] = 1
        return cache[(x, y)]

    cache[(x, y)] = 0

    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if nx < 0 or nx >= M or ny < 0 or ny >= N:
            continue
        if arr[nx][ny] < arr[x][y]:
            cache[(x, y)] += DP(nx, ny)

    return cache[(x, y)]

answer = DP(0, 0)
print(answer)