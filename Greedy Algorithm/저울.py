N = int(input())
w = list(map(int, input().split()))

w.sort()
answer = 0
total = 0
for weight in w:
    if weight <= total + 1:
        total += weight
    else:
        break

if total == 0:
    print(1)
else:
    print(answer)