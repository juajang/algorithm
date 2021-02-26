import sys
input = sys.stdin.readline

N, K = map(int, input().split())
cache = [[0] * (K + 1) for _ in range(N + 1)]

# 0-1 Knapsack Problem
# 소스코드 출처 https://hazung.tistory.com/52

for i in range(1, N + 1):
    weight, value = map(int, input().split())
    for j in range(1, K + 1):
        # 가방에 물건을 담을 수 있는 경우
        if j >= weight:
            cache[i][j] = max(cache[i - 1][j - weight] + value, cache[i - 1][j])
        else:
            cache[i][j] = cache[i - 1][j]

print(cache[N][K])