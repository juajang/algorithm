import sys
input = sys.stdin.readline
dx = (-1, 0, 1, 0)
dy = (0, -1, 0, 1)

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
visit = set()
answer = 0

def dfs(x, y, point, count):
    global answer
    if count == 4:
        answer = max(answer, point)
        return count

    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if (nx, ny) in visit:
            continue
        visit.add((nx, ny))
        dfs(nx, ny, point + board[nx][ny], count + 1)
        visit.remove((nx, ny))

def findT(x, y):
    global answer
    if x + 1 < N and y + 2 < M:
        answer = max(answer, board[x][y] + board[x][y+1] + board[x+1][y+1] + board[x][y+2])
    if x - 1 >= 0 and y + 2 < M:
        answer = max(answer, board[x][y] + board[x][y+1] + board[x-1][y+1] + board[x][y+2])
    if x + 2 < N and y + 1 < M:
        answer = max(answer, board[x][y] + board[x+1][y] + board[x+2][y] + board[x+1][y+1])
    if x + 2 < N and y - 1 >= 0:
        answer = max(answer, board[x][y] + board[x+1][y] + board[x+2][y] + board[x+1][y-1])
    
for i in range(N):
    for j in range(M):
        dfs(i, j, 0, 0)
        findT(i, j)

print(answer)
        