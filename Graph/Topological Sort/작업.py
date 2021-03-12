import sys
import heapq
input = sys.stdin.readline

N = int(input())
time = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]
indegree = [0] * (N + 1)

for a in range(1, N + 1):
    arr = list(map(int, input().split()))
    time[a] = arr[0]
    for b in arr[2:]:
        graph[a].append(b)
        indegree[b] += 1

pq = []
result = [0] * (N +  1)
for i in range(1, N + 1):
    if indegree[i] == 0:
        heapq.heappush(pq, i)
    result[i] = time[i]

while pq:
    here = heapq.heappop(pq)
    for there in graph[here]:
        result[there] = max(result[there], result[here] + time[there])
        indegree[there] -= 1
        if indegree[there] == 0:
            heapq.heappush(pq, there)

answer = 0
for n in result:
    answer = max(answer, n)
print(answer)