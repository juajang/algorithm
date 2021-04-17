dx = [0, -1, 1, 0, 0]
dy = [0, 0, 0, 1, -1]

R, C, M = map(int, input().split())
grid = [[0] * (C+1) for _ in range(R+1)]
sharks = {}

for _ in range(M):
    r, c, s, d, z = map(int, input().split())
    sharks[z] = (r, c, s, d)
    grid[r][c] = z

def fishing(curr):
    for i in range(1, R+1):
        if grid[i][curr] > 0:
            size = grid[i][curr]
            sharks[size] = -1
            grid[i][curr] = 0
            return size
    return 0

def move_sharks():
    res = [[0] * (C+1) for _ in range(R+1)]
    for size in sharks:
        if sharks[size] == -1:
            continue
        r, c, s, d = sharks[size]
        x, y = r, c

        # 상어가 제자리로 돌아오는 경우 
        if d == 1 or d == 2:
            rotate = (R - 1) * 2
        else:
            rotate = (C - 1) * 2
        if s >= rotate:
            s %= rotate     

        for _ in range(s):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx > R or nx < 1 or ny > C or ny < 1:
                if d == 1 or d == 3:
                    d += 1
                else:
                    d -= 1
                nx = x + dx[d]
                ny = y + dy[d]
            x, y = nx, ny
        
        if size >= res[x][y]:
            if res[x][y] > 0:
                sharks[res[x][y]] = -1
            sharks[size] = (x, y, s, d)
            res[x][y] = size
        else:
            sharks[size] = -1

    return res

answer = 0
for i in range(1, C+1):
    answer += fishing(i)
    grid = move_sharks()
print(answer)
