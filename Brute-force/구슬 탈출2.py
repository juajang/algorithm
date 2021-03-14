INF = float('inf')
dx = (-1, 0, 1, 0)
dy = (0, -1, 0, 1)

N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]
answer = INF
visited = set()

# 이 풀이는 DFS를 썼지만, 최단 경로를 찾는 경우에는 되도록 BFS 사용하기
# DFS로 도착 지점에 간 경우 그 루트가 최적의 루트가 아닐 수 있다 
# 따라서 visited에 count 값도 포함시켜서 저장해야 함 

# BFS인 경우 count가 1인 경로 탐색 -> count가 2인 경로 탐색 -> count가 3인 경로 -> ... 
# 여러 경로중 항상 count 값이 더 작은 경로를 먼저 발견 
# visited에 count 값 포함시키지 않아도 되고, 도착 지점을 발견하자마자 탐색을 끝내도 된다 

for i in range(N):
    for j in range(M):
        if board[i][j] == 'R':
            rx, ry = i, j
        elif board[i][j] == 'B':
            bx, by = i, j

def move(d, x, y):
    nx, ny = x, y
    while True:
        nx += dx[d] 
        ny += dy[d]
        if board[nx][ny] == '#':
            nx -= dx[d]
            ny -= dy[d]
            break
        if board[nx][ny] == 'O':
            break
    return (nx, ny)

def dfs(count, rx, ry, bx, by):
    global answer

    if count > 10:
        return 

    for d in range(4):
        next_rx, next_ry = move(d, rx, ry)
        next_bx, next_by = move(d, bx, by)

        if board[next_bx][next_by] == 'O':
            continue

        if board[next_rx][next_ry] == 'O':
            answer = min(count, answer)
            break

        # 구슬의 좌표가 겹치는 경우, 이전 위치에 따라 좌표 조정 
        if next_rx == next_bx and next_ry == next_by:
            if d == 0: # 위
                if rx > bx:
                    next_rx += 1
                else:
                    next_bx += 1
            elif d == 1: # 왼쪽
                if ry > by:
                    next_ry += 1
                else:
                    next_by += 1
            elif d == 2: # 아래 
                if rx > bx:
                    next_bx -= 1
                else:
                    next_rx -= 1
            elif d == 3: # 오른쪽
                if ry > by:
                    next_by -= 1
                else:
                    next_ry -= 1

        if (count, next_rx, next_ry, next_bx, next_by) not in visited:
            visited.add((count, next_rx, next_ry, next_bx, next_by))
            dfs(count + 1, next_rx, next_ry, next_bx, next_by)

visited.add((rx, ry, bx, by))
dfs(1, rx, ry, bx, by)

if answer == INF:
    print(-1)
else:
    print(answer)