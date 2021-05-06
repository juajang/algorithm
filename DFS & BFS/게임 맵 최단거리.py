from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def solution(maps):
    answer = -1
    N, M = len(maps), len(maps[0])    
    x, y = 0, 0
    endX, endY = N-1, M-1
    
    dq = deque()
    dq.append((x, y, 0))
    visit = set()
    while dq:
        x, y, cost = dq.popleft()
        cost += 1
        if x == endX and y == endY:
            answer = cost
            break
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx >= N or nx < 0 or ny >= M or ny < 0:
                continue
            if (nx, ny) in visit or maps[nx][ny] == 0:
                continue
            visit.add((nx, ny))
            dq.append((nx, ny, cost))
            
    return answer