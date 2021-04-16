import sys
input = sys.stdin.readline

N, M, H = map(int, input().split())
ladders = [[0] * (H+1) for _ in range(N+1)]

# ladders[b][a] b번 세로선과 b+1번 세로선을 a에서 연결 
for _ in range(M):
    a, b = map(int, input().split())
    ladders[b][a] = 1

def check():
    for i in range(1, N+1):
        curr = i
        for j in range(1, H+1):
            if ladders[curr][j]:
                curr += 1
            elif ladders[curr-1][j]:
                curr -= 1
        if curr != i:
            return False
    return True    

def backtracking(count, idx):
    global answer
    if count >= answer:
        return
    if check():
        answer = count
        return
    for i in range(1, N):
        for j in range(idx, H+1):
            if ladders[i][j] == 0 and ladders[i-1][j] == 0 and ladders[i+1][j] == 0:
                ladders[i][j] = 1
                backtracking(count + 1, j)
                ladders[i][j] = 0

answer = 4
backtracking(0, 1)
print(answer if answer < 4 else -1)
