import sys, math
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
airport = [[0,0]] + [list(map(int, input().split())) for _ in range(N)] + [[10000, 10000]]

def BFS(fuel):
    visited = [False] * (N + 2)
    dq = deque([[0, 0]])

    while len(dq):
        cur = dq.popleft()
        v = cur[0]
        cnt = cur[1]

        if cnt > K + 1:
            continue

        if v == N + 1:
            return True
        
        for i in range(1, N + 2):
            if visited[i]:
                 continue

            dist = math.sqrt(pow(airport[i][0] - airport[v][0],2) + pow(airport[i][1] - airport[v][1],2))

            if dist <= fuel:
                visited[i] = True
                dq.append([i, cnt + 1])

    return False
            

left = 0
right = 10000

while left <= right:
    mid = (left + right) // 2

    if BFS(mid * 10):
        right = mid - 1
    else:
        left = mid + 1

print(left)