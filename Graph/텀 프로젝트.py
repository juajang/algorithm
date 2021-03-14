import sys
from collections import deque
input = sys.stdin.readline

# 소스코드 출처: https://suri78.tistory.com/128

T = int(input())
for _ in range(T):
    N = int(input())
    table = [0] + list(map(int, input().split()))
    group = [0] * (N + 1)

    index = 1
    for i in range(1, N + 1):
        if group[i] == 0:
            # 이미 다른 팀에 배정되어있거나,
            # 사이클을 이뤄서 방문했던 노드로 다시 돌아오는 경우 반복 끝 
            while group[i] == 0:
                group[i] = index
                i = table[i]
            # 사이클을 이뤄서 while 반복문이 끝난 경우에만 팀 배정  
            while group[i] == index:
                group[i] = -1
                i = table[i]
            index += 1

    count = 0
    for g in group:
        if g > 0:
            count += 1
    print(count)