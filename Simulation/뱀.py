from collections import deque
dx = (0, 1, 0, -1)
dy = (1, 0, -1, 0)

N = int(input())
K = int(input())
board = [[0] * (N+1) for _ in range(N+1)]
for _ in range(K):
    x, y = map(int, (input().split()))
    board[x][y] = 1
L = int(input())
directions = [list(input().split()) for _ in range(L)]

x, y = 1, 1
board[x][y] = 2
snake = deque()
snake.append((1, 1))
time = 0
curr_dir = 0
directions_index = 0

while True:
    if directions_index < L and time == int(directions[directions_index][0]):
        direction = directions[directions_index][1]
        directions_index += 1
        if direction == 'L':
            if curr_dir == 0:
                curr_dir = 3
            else:
                curr_dir -= 1
        elif direction == 'D':
            if curr_dir == 3:
                curr_dir = 0
            else:
                curr_dir += 1
    
    nx = x + dx[curr_dir]
    ny = y + dy[curr_dir]
    time += 1

    if nx < 1 or nx > N or ny < 1 or ny > N:
        break
    if board[nx][ny] == 2:
        break

    if board[nx][ny] == 1:
        board[nx][ny] = 0
    elif board[nx][ny] == 0:
        tail_x, tail_y = snake.popleft()
        board[tail_x][tail_y] = 0
    
    board[nx][ny] = 2
    snake.append((nx, ny))
    x, y = nx, ny

print(time)