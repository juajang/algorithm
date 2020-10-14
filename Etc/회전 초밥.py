import sys
input = sys.stdin.readline

N, D, K, C = map(int, input().split())
arr = [int(input()) for _ in range(N)]

# 쿠폰 번호 초밥 처리 
check = [0] * (D + 1)
check[C] = 1
cnt = 1
answer = 0

# K개의 초밥 종류 세기 
for i in range(K):
    if check[arr[i]] == 0:
        cnt += 1
    check[arr[i]] += 1
    # 원형 큐처럼 배열 뒤에 추가 
    arr.append(arr[i])

# K의 크기로 슬라이딩 윈도우 
for i in range(N):
    answer = max(answer, cnt)

    # 가장 처음에 있는 초밥을 빼고 
    check[arr[i]] -= 1 
    if check[arr[i]] == 0:
        cnt -= 1
    
    # 가장 마지막에 있는 초밥 더하기 
    if check[arr[i + K]] == 0:
        cnt += 1

    check[arr[i + K]] += 1

print(answer)

