def isPossible(n, time, times):
    count = 0
    for i in times:
        count += time // i
    return count >= n

def solution(n, times):
    answer = 0
    left, right = 0, max(times) * n
    while left <= right:
        mid = (left + right) // 2
        if isPossible(n, mid, times):
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    return answer