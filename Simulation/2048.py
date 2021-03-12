import sys
from copy import deepcopy
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

# 소스코드 출처: https://hazung.tistory.com/77
# 블록을 상하좌우로 이동하는 방법이 아닌, 보드를 90도 돌리고 무조건 왼쪽으로 합치는 방법

def rotate(board):
    result = deepcopy(board)
    # 시계방향으로 90도 돌림 
    for i in range(N):
        for j in range(N):
            result[j][N-i-1] = board[i][j]
    return result

def merge(board):
    result = []
    for row in board:
        temp = [i for i in row if i != 0]
        for i in range(1, len(temp)):
            if temp[i-1] == temp[i]:
                temp[i-1] *= 2
                temp[i] = 0
        temp = [i for i in temp if i != 0]
        temp = temp + [0] * (N - len(temp))
        result.append(temp)
    return result
    
def dfs(board, count):
    score = max([max(i) for i in board])
    if count == 5:
        return score

    for _ in range(4):
        mergedBoard = merge(board)
        score = max(score, dfs(mergedBoard, count + 1))
        board = rotate(board)
    return score

print(dfs(board, 0))