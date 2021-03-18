import sys
sys = sys.stdin.readline
INF = float('inf')

N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]
cache= [[0] * N for _ in range(N)]

for x in range(1, N):
    for i in range(N - x):
        j = i + x
        cache[i][j] = INF
        for k in range(i, j):
            print(i, j, k)
            cache[i][j] = min(cache[i][j], cache[i][k] + cache[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1])

print(cache[0][N - 1])