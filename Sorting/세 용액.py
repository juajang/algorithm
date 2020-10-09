import sys
input = sys.stdin.readline

N = int(input())
liquid = [int(x) for x in input().split()]

liquid.sort()
min = float('inf')
ans = [0]*3

for i in range(N - 2):
    left, right = i + 1, N - 1

    while left < right:
        sum = liquid[i] + liquid[left] + liquid[right]

        if abs(sum) < min:
            min = abs(sum)
            ans[0], ans[1], ans[2] = liquid[i], liquid[left], liquid[right]

        if sum > 0:
            right -= 1
            
        else:
            left += 1

print(ans[0], ans[1], ans[2])

            