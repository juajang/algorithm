import sys
from copy import deepcopy
from itertools import permutations

INF = float('inf')
input = sys.stdin.readline

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
operations = [list(map(int, input().split())) for _ in range(K)]

def rotate(A, r, c, s):
    res = deepcopy(A)
    start_x, start_y = r-s, c-s
    end_x, end_y = r+s, c+s
    while start_x != r and start_y != c:
        x, y = start_x, start_y
        curr_dir = 0
        while True:
            nx = x + dx[curr_dir]
            ny = y + dy[curr_dir]
            res[nx][ny] = A[x][y]
            x, y = nx, ny
            cx = x + dx[curr_dir]
            cy = y + dy[curr_dir]
            if cx > end_x or cx < start_x or cy > end_y or cy < start_y:
                curr_dir += 1
                if curr_dir == 4:
                    break
        start_x += 1
        start_y += 1
        end_x -= 1
        end_y -= 1
    return res

operations_idx = [i for i in range(len(operations))]
candidates = list(permutations(operations_idx, len(operations)))

answer = INF
for candidate in candidates:
    result = deepcopy(A)
    for idx in candidate:
        r, c, s = operations[idx]
        result = rotate(result, r-1, c-1, s)
    for row in result:
        answer = min(answer, sum(row))

print(answer)
