import sys
input = sys.stdin.readline

N = int(input())
min_cache = [[0] * 3 for _ in range(2)]
max_cache = [[0] * 3 for _ in range(2)]

for _ in range(N):
    a, b, c = map(int, input().split())
    min_cache[1][0] = a + min(min_cache[0][0], min_cache[0][1])
    min_cache[1][1] = b + min(min_cache[0][0], min_cache[0][1], min_cache[0][2])
    min_cache[1][2] = c + min(min_cache[0][1], min_cache[0][2])

    min_cache[0][0] = min_cache[1][0]
    min_cache[0][1] = min_cache[1][1]
    min_cache[0][2] = min_cache[1][2]

    max_cache[1][0] = a + max(max_cache[0][0], max_cache[0][1])
    max_cache[1][1] = b + max(max_cache[0][0], max_cache[0][1], max_cache[0][2])
    max_cache[1][2] = c + max(max_cache[0][1], max_cache[0][2])

    max_cache[0][0] = max_cache[1][0]
    max_cache[0][1] = max_cache[1][1]
    max_cache[0][2] = max_cache[1][2]

print(max(max_cache[0]), min(min_cache[0]))
