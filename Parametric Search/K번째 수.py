N = int(input())
K = int(input())

# 풀이 출처 https://dsbook.tistory.com/224

low, high = 1, K
answer = -1
while low <= high:
    count = 0
    mid = (low + high) // 2

    # N * N의 행렬에서 mid보다 같거나 작은 수가 몇 개인지 세기 
    for i in range(1, N+1):
        count += min(mid // i, N)

    if count < K:
        low = mid + 1
    else:
        answer = mid
        high = mid - 1

print(answer)