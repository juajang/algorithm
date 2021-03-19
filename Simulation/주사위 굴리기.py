from copy import deepcopy
dx = (0, 0, 0, -1, 1)
dy = (0, 1, -1, 0, 0)

N, M, x, y, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
cmd = list(map(int, input().split()))

# 바닥면 0 윗면 1 동 2 남 3 서 4 북 5
dice = [0] * 6

for direction in cmd:
    nx = x + dx[direction]
    ny = y + dy[direction]

    if nx < 0 or nx >= N or ny < 0 or ny >= N:
        continue
    temp_dice = deepcopy(dice)
    if direction == 1:
        dice[0] = temp_dice[2]
        dice[4] = temp_dice[0]
        dice[1] = temp_dice[4]
        dice[2] = temp_dice[1]
    elif direction == 2:
        dice[0] = temp_dice[4]
        dice[2] = temp_dice[0]
        dice[1] = temp_dice[2]
        dice[4] = temp_dice[1]
    elif direction == 3:
        dice[0] = temp_dice[5]
        dice[3] = temp_dice[0]
        dice[1] = temp_dice[3]
        dice[5] = temp_dice[1]
    elif direction == 4:
        dice[0] = temp_dice[3]
        dice[5] = temp_dice[0]
        dice[1] = temp_dice[5]
        dice[3] = temp_dice[1]

    if board[nx][ny] == 0:
        board[nx][ny] = dice[0]
    else:
        dice[0] = board[nx][ny]
        board[nx][ny] = 0

    x, y = nx, ny
    print(dice[1])
    