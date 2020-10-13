import sys
from collections import deque
input = sys.stdin.readline

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = {}
shapes = {}
points = [0]
zero = []

def BFS(x, y, idx):
    dq = deque()
    dq.append((x, y))
    visited[(x, y)] = True

    while dq:
        x, y = dq.popleft()
        arr[x][y] = idx
        points[idx] += 1
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if visited.get((nx, ny)):
                continue
            visited[(nx, ny)] = True
            if arr[nx][ny] == 1:
                dq.append((nx, ny))

idx = 1
for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            zero.append((i, j))
        if visited.get((i, j)) is None and arr[i][j] == 1:
            points.append(0)
            BFS(i, j, idx)
            idx += 1

answer = 0 
check = {}

for x, y in zero: 
        check.clear()
        point = 0
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if arr[nx][ny] > 0 and check.get(arr[nx][ny]) is None:
                idx = arr[nx][ny]
                check[idx] = True
                point += points[idx]
        if point > answer:
            answer = point

print(answer + 1)