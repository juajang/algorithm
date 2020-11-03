parent = [i for i in range(100)]

def Find(x):
    if parent[x] == x:
        return x
    parent[x] = Find(parent[x])
    return parent[x]

def Union(x, y):
    x = Find(x)
    y = Find(y)
    parent[x] = y

def solution(n, costs):
    answer = 0
    costs = sorted(costs, key = lambda x: x[2])
    for a, b, cost in costs:
        if Find(a) == Find(b):
            continue
        Union(a, b)
        answer += cost
    return answer