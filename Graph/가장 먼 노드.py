from collections import deque, Counter

def solution(n, edge):
    answer = 0
    graph = [[] for _ in range(n + 1)]
    dist = {1: 0}
    dq = deque([1])
    
    for a, b in edge:
        graph[a].append(b)
        graph[b].append(a)
    
    while dq:
        cur = dq.popleft()
        for node in graph[cur]:
            if node not in dist:
                dist[node] = dist[cur] + 1
                dq.append(node)
    
    m = 0
    for d in dist.values():
        if d > m:
            answer = 1
            m = d
        elif d == m:
            answer += 1
            
    return answer