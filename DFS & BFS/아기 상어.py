from collections import deque
dx = (-1, 0, 1, 0)
dy = (0, -1, 0, 1)

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
fishes = set()
x, y = 0, 0
shark = 2

for i in range(N):
    for j in range(N):
        if board[i][j] == 9:
            x, y = i, j
        elif board[i][j] > 0:
            fishes.add((i, j))

def find_fishes(x, y):
    global shark
    dq = deque()
    dq.append((x, y, 0))
    visit = {(x, y)}
    result = []
    while dq:
        x, y, cost = dq.popleft()
        if (x, y) in fishes and board[x][y] < shark:
            result.append((cost, x, y))
            continue
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if (nx, ny) in visit or shark < board[nx][ny]:
                continue
            visit.add((nx, ny))
            dq.append((nx, ny, cost + 1))
    return result

time = 0
eat_count = 0
while True:
    eat = find_fishes(x, y)
    if len(eat) == 0:
        break

    eat = sorted(eat)
    cost, fish_x, fish_y = eat[0][0], eat[0][1], eat[0][2]
    fishes.remove((fish_x, fish_y))

    board[fish_x][fish_y] = 0
    board[x][y] = 0
    x, y = fish_x, fish_y 

    time += cost
    eat_count += 1
    if eat_count == shark:
        eat_count = 0
        shark += 1
    
print(time)
