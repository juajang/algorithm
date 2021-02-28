import sys
import heapq

input = sys.stdin.readline

# 소스코드 출처: https://inspirit941.tistory.com/200

# 중앙값을 기준으로 작은 값, 최대 힙 
left = []
# 중앙값을 기준으로 큰 값, 최소 힙 
right = []

N = int(input())

for _ in range(N):
    num = int(input())

    if len(left) == len(right):
        # 힙은 (우선순위, 값)의 형태로 저장됨 
        # 최대 힙을 만들기 위해서는 우선순위에는 -를 붙여서 넣기 
        heapq.heappush(left, (-num, num))
    else:
        heapq.heappush(right, (num, num))

    # 최소 힙에서 가장 큰 값과 최대 힙에서 가장 작은 값 비교 
    # left의 원소가 더 큰 경우, left의 원소 < right 원소 조건을 지키도록 값을 서로 교환  

    # (우선순위, 값) 중 값만 가져와서 비교
    if right and left[0][1] > right[0][1]:
        leftValue = heapq.heappop(left)[1]
        rightValue = heapq.heappop(right)[1]
        heapq.heappush(right, (leftValue, leftValue))
        heapq.heappush(left, (-rightValue, rightValue))

    print(left[0][1])