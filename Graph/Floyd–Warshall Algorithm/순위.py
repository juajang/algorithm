def solution(n, results):
    answer = 0
    graph = [[False] * (n + 1) for _ in range(n + 1)]
    for a, b in results:
        graph[a][b] = True 
    for k in range(1, n + 1):                   # k = 거쳐가는 노드
        for i in range(1, n + 1):               # i = 출발 노드 
            for j in range(1, n + 1):           # j = 도착 노드
                if graph[i][k] and graph[k][j]: # i가 k를 이기고 k가 j를 이겼다면 i가 j를 이긴 것이다.
                    graph[i][j] = True
    for i in range(1, n + 1):
        count = 0
        for j in range(1, n + 1):
            if graph[i][j] or graph[j][i]:
                count += 1
        # 자기 자신을 제외한 나머지와의 승패 결과가 알려져 있는 경우 순위를 매길 수 있다.
        if count == n - 1:
            answer += 1
    return answer