import sys, heapq
INF = float('inf')
input = sys.stdin.readline

def Dijkstra(start, arr):
    heap = []
    heapq.heappush(heap, (0, start))
    arr[start] = 0

    while heap:
        cost, cur = heapq.heappop(heap)

        for next, nextCost in graph[cur]:
            nextCost += cost
            if nextCost < arr[next]:
                arr[next] = nextCost
                heapq.heappush(heap, (nextCost, next))

T = int(input())

for _ in range(T):
    n, m, t = map(int, input().split())
    s, g, h = map(int, input().split())

    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d))
        graph[b].append((a, d))

    candi = []
    for _ in range(t):
        candi.append(int(input()))
    candi.sort()

    # S, G, H에서부터 목적지까지 거리 구하기   
    S = [INF] * (n + 1)
    G = [INF] * (n + 1)
    H = [INF] * (n + 1)

    Dijkstra(s, S)
    Dijkstra(g, G)
    Dijkstra(h, H)

    for v in candi:
        dist1 = S[g] + G[h] + H[v]
        dist2 = S[h] + H[g] + G[v]
        dist3 = S[v]
        
        # 경로가 없는 경우 
        if dist1 == INF and dist2 == INF and dist3 == INF:
            continue

        # g와 h를 지나간 경로가 최단 경로인 경우 
        if dist1 == dist3 or dist2 == dist3:
            print(v, end = ' ')
    print()