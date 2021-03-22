import sys
input = sys.stdin.readline

N = int(input())
A, B, C, D = [], [], [], []
for i in range(N):
    a, b, c, d = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)
    D.append(d)

AB = []
CD = []
for i in range(N):
    for j in range(N):
        AB.append(A[i] + B[j])
        CD.append(C[i] + D[j])

AB.sort()
CD.sort()

answer = 0
left, right = 0, len(CD) - 1
while left < len(AB) and right >= 0:
    total = AB[left] + CD[right]

    if total == 0: 
        left_count, right_count = 1, 1
        left_tmp = left

        left += 1
        while left < len(AB) and AB[left] + CD[right] == 0:
            left_count += 1
            left += 1

        right -= 1
        while right >= 0 and AB[left_tmp] + CD[right] == 0:
            right_count += 1
            right -= 1
            
        answer += (left_count * right_count)

    elif total > 0:
        right -= 1
    else:
        left += 1

print(answer)