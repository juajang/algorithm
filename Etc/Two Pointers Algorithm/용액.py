import sys
input = sys.stdin.readline
INF = float('inf')

N = int(input())
arr = list(map(int, input().split()))

left, right = 0, N - 1 
total = arr[left] + arr[right]
minTotal = INF
while left < right:
    if abs(minTotal) > abs(total):
        minTotal = total
        answer = (arr[left], arr[right])
        if total == 0: 
            break
    if total > 0:
        right -= 1
        total = arr[left] + arr[right]
    elif total < 0:
        left += 1
        total = arr[left] + arr[right]

for num in answer:
    print(num, end = ' ')