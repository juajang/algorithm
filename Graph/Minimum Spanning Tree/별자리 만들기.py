import math
import heapq
N = int(input())
nodes = [list(map(float, input().split())) for _ in range(N)]

# 모든 노드를 이어야 한다 + 최소 비용 -> MST!

def calc_dist(x1, y1, x2, y2):
    x = (x1 - x2) ** 2
    y = (y1 - y2) ** 2
    return math.sqrt(x + y)

graph = [[] for _ in range(N)]
for i in range(N):
    x1, y1 = nodes[i]
    for j in range(i + 1, N):
        x2, y2 = nodes[j]
        dist = calc_dist(x1, y1, x2, y2)
        graph[i].append((dist, j))
        graph[j].append((dist, i))

pq = []
for dist, node in graph[0]:
    heapq.heappush(pq, (dist, node))

answer = 0
visit = {0}
while pq:
    dist, here = heapq.heappop(pq)
    if here in visit: 
        continue
    visit.add(here)
    answer += dist
    for dist, there in graph[here]:
        if there in visit:
            continue
        heapq.heappush(pq, (dist, there))

print("%.2f" % answer)
