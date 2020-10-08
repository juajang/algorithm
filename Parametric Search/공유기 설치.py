import sys
N, C = map(int, (input().split()))
house = [int(sys.stdin.readline()) for _ in range(N)]

# 해당 거리에서 설치될 수 있는 공유기 수 
def countRouter(dist):
    cnt = 1
    curHouse = house[0]
    for i in range(1,N):
        # 이전 집에서 일정 거리보다 멀리 떨어진 집인 경우, 공유기 설치
        if curHouse + dist <= house[i]:
            cnt += 1
            curHouse = house[i]
    return cnt

house = sorted(house)
# dist의 범위: 첫 집과 끝 집 사이의 거리 
left, right = 1, house[-1] - house[0]

# 이분 탐색 
while left <= right:
    mid = (left + right) // 2

    # 일정 거리를 두고 설치된 공유기 숫자가 너무 많은 경우 
    if countRouter(mid) >= C:
        answer = mid
        left = mid + 1
    else:
        right = mid - 1

print(answer)
