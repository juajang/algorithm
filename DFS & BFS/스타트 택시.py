import sys 
from collections import deque
input = sys.stdin.readline

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

N, M, fuel = map(int, input().split())
area = [list(map(int, input().split())) for _ in range(N)]
tx, ty = map(int, input().split())
tx -= 1
ty -= 1
customers = {}
for i in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    customers[(x1 - 1, y1 - 1)] = [x2 - 1, y2 - 1]

def findNearestCustomer(tx, ty):
    if customers.get((tx,ty)) is not None:
        return tx, ty, 0
        
    dq = deque()
    visited = {(tx, ty): 1}
    dq.append((tx, ty, 0))
    nexts = []

    while dq:
        for _ in range(len(dq)):
            x, y, cost = dq.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx < 0 or nx >= N or ny < 0 or ny >= N:
                    continue
                if area[nx][ny] == 1 or visited.get((nx, ny)):
                    continue
                visited[(nx, ny)] = 1
                if customers.get((nx, ny)) is not None:
                    nexts.append([nx, ny, cost + 1])
                dq.append((nx, ny, cost + 1))
        if len(nexts) != 0:
            nexts.sort(key = lambda x : (x[0], x[1]))
            return nexts[0][0], nexts[0][1], nexts[0][2]

    return -1, -1, -1

def drive(tx, ty, cx, cy):
    dq = deque()
    visited = {(tx, ty): 1}
    dq.append((tx, ty, 0))

    while dq:
        x, y, cost = dq.popleft()
        if x == cx and y == cy:
            return cost
        if cost > fuel:
            return cost
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if area[nx][ny] == 1 or visited.get((nx, ny)):
                continue
            visited[(nx, ny)] = 1
            dq.append((nx, ny, cost + 1))

    return -1

while True:
    # 가장 가까운 손님을 찾고 택시가 손님까지 이동 
    tx, ty, cost = findNearestCustomer(tx, ty)
    fuel -= cost

    if fuel < 0 or tx == -1:
        print(-1)
        break

    # 손님의 목적지를 찾고 목적지까지 이동 
    cx, cy = customers[(tx, ty)]
    cost = drive(tx, ty, cx, cy)
    fuel -= cost

    if fuel < 0 or cost == -1:
        print(-1)
        break

    fuel += cost * 2
    del customers[(tx, ty)]
    tx = cx 
    ty = cy
    if not customers:
        print(fuel)
        break