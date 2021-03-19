import sys
from collections import deque
input = sys.stdin.readline

dx = (-1, 0, 1, 0)
dy = (0, -1, 0, 1)

N, L, R = map(int, input().split())
land = [list(map(int, input().split())) for _ in range(N)]

def find_union(x, y, visit):
    dq = deque()
    dq.append((x, y))
    result = [(x, y)]
    visit.add((x, y))
    while dq:
        x, y = dq.popleft()
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if (nx, ny) in visit:
                continue
            diff = abs(land[x][y] - land[nx][ny])
            if diff >= L and diff <= R:
                result.append((nx, ny))
                visit.add((nx, ny))
                dq.append((nx, ny))

    if len(result) > 1:
        return result

answer = 0
while True:
    unions = []
    visit = set()
    for i in range(N):
        for j in range(N):
            if (i, j) in visit:
                continue
            print(visit)
            result = find_union(i, j, visit)
            if result:
                unions.append(result)

    if len(unions) == 0:
        break

    for union in unions:
        total = 0
        for x, y in union:
            total += land[x][y]
        population = total // len(union)
        for x, y in union:
            land[x][y] = population
    answer += 1

print(answer)