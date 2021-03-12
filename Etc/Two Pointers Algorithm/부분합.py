import sys
input = sys.stdin.readline
INF = float('INF')

N, S = map(int, input().split())
arr = list(map(int, input().split()))
arr.append(0)
answer = INF

left, right = 0, 0
total = arr[0]
while left <= right and right < N:
    if total < S:
        right += 1
        total += arr[right]
    elif total == S:
        answer = min(right - left + 1, answer)
        right += 1
        total += arr[right]
    elif total > S:
        answer = min(right - left + 1, answer)
        total -= arr[left]
        left += 1

if answer == INF:
    print(0)
else: 
    print(answer)