N = int(input())
M = int(input())
graph = [list(map(int, input().split())) for _ in range(M)]
parent = [i for i in range(N+1)]

def Find(x):
    if parent[x] == x:
        return x
    y = Find(parent[x])
    parent[x] = y
    return y

def Union(x, y):
    x = Find(x)
    y = Find(y)
    parent[x] = y

graph.sort(key=lambda x:x[2])
answer = 0
count = 0
for a, b, cost in graph:
    if count == N-1:
        break
    if Find(a) == Find(b):
        continue
    Union(a, b)
    answer += cost
    count += 1

print(answer)
