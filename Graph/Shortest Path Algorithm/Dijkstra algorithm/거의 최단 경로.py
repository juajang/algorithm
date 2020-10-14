import sys
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline
INF = float('inf')

def Dijkstra(start, dist, check, heap):
    heappush(heap, (0, start))
    dist[start] = 0

    while heap:
        cost, cur = heappop(heap)

        if dist[cur] < cost:
            continue

        for next, nextCost in graph[cur]:
            nextCost += cost
            if nextCost < dist[next] and check[cur][next] is False :
                dist[next] = nextCost
                heappush(heap, (nextCost, next)) 


def Erase(start, dest, check):
    q = deque()
    q.append(start)
    while q:
        cur = q.popleft()
        if cur == dest:
            continue
        for next, nextCost in graph2[cur]:
            if dist[cur] == dist[next] + nextCost:
                check[next][cur] = True
                q.append(next)


while True:
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        break

    S, D = map(int, input().split())

    graph = [[] for _ in range(N)]
    graph2 = [[] for _ in range(N)]
    for _ in range(M):
        U, V, P = map(int, input().split())
        graph[U].append([V, P])
        graph2[V].append([U, P])

    dist = [INF] * N
    check = [[False] * N for _ in range(N)]
    heap = []
    Dijkstra(S, dist, check, heap)

    Erase(D, S, check)

    dist = [INF] * N

    Dijkstra(S, dist, check, heap)

    if dist[D] == INF:
        print(-1)
    else:
        print(dist[D])


    
