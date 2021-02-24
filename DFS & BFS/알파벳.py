import sys
from collections import deque
input = sys.stdin.readline

d = ((1, 0), (-1, 0), (0, 1), (0, -1))

R, C = map(int, input().split())
arr = [list(input()) for _ in range(R)]

x, y = 0, 0
queue = deque()
queue.append((x, y, arr[0][0]))
answer = 1

while queue:
    x, y, alpha = queue.popleft()
    answer = max(answer, len(alpha))
    for i in range(4):
        nx = x + d[i][0]
        ny = y + d[i][1]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            continue
        if arr[nx][ny] in alpha: 
            continue
        queue.append((nx, ny, alpha + arr[nx][ny]))

print(answer)