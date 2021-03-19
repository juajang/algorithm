import sys
sys.setrecursionlimit(100100)
dx = (-1, 0, 1, 0)
dy = (0, -1, 0, 1)

R, C = map(int, input().split())
cave = [list(input()) for _ in range(R)]
N = int(input())
sticks = list(map(int, input().split()))
flag = False

def find_cluster(x, y, visit, cluster):
    global flag
    cluster.append((x, y))
    if x == R-1:
        flag = True
        return 
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            continue
        if (nx, ny) in visit or cave[nx][ny] != 'x':
            continue
        visit.add((nx, ny))
        find_cluster(nx, ny, visit, cluster)

for i in range(1, N+1):
    if i % 2:
        x, y = R - sticks[i-1], 0
        while y < C and cave[x][y] != 'x':
            y += 1
    else:
        x, y = R - sticks[i-1], C - 1
        while y >= 0 and cave[x][y] != 'x':
            y -= 1

    if y == C or y < 0:
        continue

    cave[x][y] = '.'

    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            continue
        if cave[nx][ny] != 'x':
            continue
        visit = {(nx, ny)}
        cluster = [(nx, ny)]
        flag = False
        find_cluster(nx, ny, visit, cluster)
        if flag == False:
            break

    if flag:
        continue  

    cluster = sorted(cluster, reverse=True)
    step = R
    for x, y in cluster:
        nx, ny = x, y
        tmp = 0
        while nx + 1 < R and cave[nx+1][ny] == '.':
            nx += 1
            tmp += 1
        if (nx + 1, y) in cluster:
            continue
        step = min(step, tmp)

    for x, y in cluster:
        nx, ny = x + step, y
        cave[nx][ny] = 'x'
        cave[x][y] = '.'

for i in cave:
    for j in i:
        print(j, end='')
    print()
