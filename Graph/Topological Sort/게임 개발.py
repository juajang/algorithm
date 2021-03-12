import sys
import heapq
input = sys.stdin.readline

N = int(input())
time = [0] * (N + 1)
indegree = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]

for a in range(1, N + 1):
    arr = list(map(int, input().split()))
    time[a] = arr[0]
    for b in arr[1 : -1]: 
        graph[b].append(a)
        indegree[a] += 1

pq = []
answer = [0] * (N + 1)

for i in range(1, N + 1):
    if indegree[i] == 0:
        heapq.heappush(pq, i)
    answer[i] = time[i]

while pq:
    here = heapq.heappop(pq)
    for there in graph[here]:
        indegree[there] -= 1
        answer[there] = max(answer[there], answer[here] + time[there])
        if indegree[there] == 0:
            heapq.heappush(pq, there)

for t in answer[1:]:
    print(t)
