from collections import deque
from copy import deepcopy

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

def fillBoard(x, y, idx, fill, visit):
    dq = deque()
    dq.append((x, y))
    while dq:
        x, y = dq.popleft()
        fill[x][y] = idx
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if (nx, ny) in visit:
                continue
            if board[nx][ny] != board[x][y]:
                continue
            visit.add((nx, ny))
            dq.append((nx, ny))

time = 1
while True:
    idx = 1
    fill = [[0] * M for _ in range(N)]
    visit = set()

    count = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                count += 1
    
    for i in range(N):
        for j in range(M):
            if (i, j) not in visit:
                visit.add((i, j))
                fillBoard(i, j, idx, fill, visit)
                idx += 1

    new_board = deepcopy(board)
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                for d in range(4):
                    nx = i + dx[d]
                    ny = j + dy[d]
                    if nx < 0 or nx >= N or ny < 0 or ny >= M:
                        continue
                    if fill[nx][ny] == 1:
                        new_board[i][j] = 0
                        break
    board = new_board

    tmpCount = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                tmpCount += 1

    if tmpCount == 0:
        print(time)
        print(count)
        break

    time += 1
