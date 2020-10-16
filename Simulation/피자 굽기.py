import sys
input = sys.stdin.readline

D, N = map(int, input().split())
oven = list(map(int, input().split()))
pizza = list(map(int, input().split()))

# 피자가 들어갈 수 있는 오븐의 길이 구하기 
lens = [oven[0]]
minDepth = oven[0]

for i in range(1, D):
    # 현재 오븐의 길이가 더 짧다면, 길이 갱신 
    if oven[i] < minDepth:
        minDepth = oven[i]
        lens.append(oven[i])
    else:
        lens.append(minDepth)

# i: oven index / j: pizza index 
j = 0 
for i in reversed(range(D)):
    # 피자가 더 긴 경우, 피자를 넣을 수 없음
    if lens[i] < pizza[j]:
        continue 
    j += 1
    if j == N:
        answer = i
        break

if j == N:
    print(answer + 1)
else:
    print(0)

