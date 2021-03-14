import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    table = [0] + list(map(int, input().split()))
    done = [False] * (N + 1)
    visited = [False] * (N + 1)

    for i in range(1, N + 1):
        if table[i] == 0:
            continue
        dq = deque()
        dq.append(table[i])
        team = [i]
        while dq:
            curr = dq.popleft()
            nxt = table[curr]
            if visited[nxt] and not done[nxt]:
                while node != nx:

            elif not vistied[nxt]:
                dq.append(nxt)
                
            done[curr] = True
    count = 0
    for i in range(1, N + 1):
        if not done[i]:
            count += 1
    print(count)