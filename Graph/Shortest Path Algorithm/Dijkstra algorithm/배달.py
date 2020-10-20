from queue import PriorityQueue
INF = float('inf')

def solution(N, road, K):
    answer = 0
    
    ret = [INF] * (N + 1)
    graph = [[] for _ in range(N + 1)]

    for r in road:
        graph[r[0]].append((r[1], r[2]))
        graph[r[1]].append((r[0], r[2]))

    pq = PriorityQueue()
    ret[1] = 0
    pq.put((1, 0))
    
    while pq.qsize():
        tmp = pq.get()
        v, cost = tmp[0], tmp[1]
        
        if cost > ret[v]:
            continue
            
        for next in graph[v]:
            nextV = next[0]
            nextCost = next[1] + cost
            
            if nextCost < ret[nextV]:
                ret[nextV] = nextCost
                pq.put((nextV, nextCost))
    
    for i in range(1, N + 1):
        if ret[i] <= K:
            answer += 1
            
    return answer