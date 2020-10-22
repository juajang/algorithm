from collections import deque
INF = float('inf')

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
groups = []
parent = []

def labeling(fill, land, height, x, y, idx):
    q = deque()
    q.append((x, y))
    N = len(land[0])
    fill[x][y] = idx
    
    while q:
        x, y = q.popleft()
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
                
            if fill[nx][ny] == 0:
                diff = abs(land[x][y] - land[nx][ny])
                
                if diff <= height:
                    fill[nx][ny] = idx
                    q.append((nx, ny))

def getDistanceBetweenGroups(land, fill, height):
    N = len(fill)
    for x in range(N):
        for y in range(N):
            for d in range(4):
                nx = x + dx[d]
                ny = y + dy[d]
                
                if nx < 0 or nx >= N or ny < 0 or ny >= N:
                    continue
                
                if fill[x][y] != fill[nx][ny]:
                    diff = abs(land[x][y] - land[nx][ny])
                    groups.append((diff, fill[x][y], fill[nx][ny]))

def Find(a):
    if a == parent[a]:
        return a
    parent[a] = Find(parent[a])
    return parent[a]
    
def Union(a, b):
    a = Find(a)
    b = Find(b)
    parent[b] = a
    
def isSameParent(a, b):
    a = Find(a)
    b = Find(b)
    if a == b:
        return True
    return False

# 크루스칼 알고리즘, 모든 노드를 최소의 비용으로 탐색하기 
def MST(groupCnt):
    # cost를 기준으로 오름차순 정렬 
    groups.sort()
    totalCost = 0
    
    # 노드의 개수만큼 초기화
    for i in range(groupCnt + 1):
        parent.append(i)
        
    # 사이클을 확인하면서 노드 a, 노드 b를 연결
    for cost, a, b in groups:
        if isSameParent(a, b) == False:
            Union(a, b) 
            totalCost += cost
    
    return totalCost
    
def solution(land, height):
    N = len(land)
    fill = [[0] * N for _ in range(N)]

    idx = 0
    for i in range(N):
        for j in range(N):
            if fill[i][j] == 0:
                idx += 1
                labeling(fill, land, height, i, j, idx)
                
    getDistanceBetweenGroups(land, fill, height)      
    answer = MST(idx)
    
    return answer