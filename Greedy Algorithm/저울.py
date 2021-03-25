N = int(input())
w = list(map(int, input().split()))

w.sort()
total = 1
for weight in w:
    if weight <= total:
        total += weight
    else:
        break

answer = total 
print(answer)