import sys
sys = sys.stdin.readline
INF = float('inf')

N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]

# cache[i][j] - i번째 행렬부터 j번째 행렬까지의 곱의 optimal 연산 횟수
cache= [[0] * N for _ in range(N)]

for x in range(1, N):
    for i in range(N - x):
        j = i + x
        cache[i][j] = INF
        for k in range(i, j):
            cache[i][j] = min(cache[i][j], cache[i][k] + cache[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1])

print(cache[0][N - 1])
