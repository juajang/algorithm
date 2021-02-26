import sys
input = sys.stdin.readline

N = int(input())
buildings = list(map(int, input().split()))
res = [0] * N

# 두 빌딩 사이의 기울기를 이용해서 푸는 문제
# A에서 B를 볼 수 있으려면 A와 B를 잇는 선분의 기울기는 A와 B보다 앞에 있는 다른 빌딩들을 잇는 선분의 기울기보다 커야한다.

for i in range(N):
    m = -1000000010
    for j in range(i + 1, N):
        slope = (buildings[j] - buildings[i]) / (j - i)
        if slope > m: 
            m = slope
            res[i] += 1
            # A에서 B를 볼 수 있으면 B에서도 A를 볼 수 있다
            res[j] += 1 

answer = 0
for i in res:
    answer = max(answer, i)

print(answer)
