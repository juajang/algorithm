import sys
from collections import deque
input = sys.stdin.readline

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = {}
shapes = {}
points = []

def DFS(x, y, idx):
    visited[(x, y)] = 1
    shapes[(x, y)] = idx
    points[idx] += 1

    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if visited.get((nx, ny)):
            continue
        if arr[nx][ny] == 1:
            DFS(nx, ny, idx)

idx = 0
for i in range(N):
    for j in range(M):
        if visited.get((i, j)) is None and arr[i][j] == 1:
            points.append(0)
            DFS(i, j, idx)
            idx += 1

answer = 0 

for i in range(N):
    for j in range(M):
        if arr[i][j] != 0:
            continue
        point = 0
        check = {}
        for d in range(4):
            nx = i + dx[d]
            ny = j + dy[d]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if shapes.get((nx, ny)) is not None:
                idx = shapes.get((nx, ny))
                if check.get(idx) is None:
                    check[idx] = True
                    point += points[idx]
        point += 1
        if point > answer:
            answer = point

print(answer)