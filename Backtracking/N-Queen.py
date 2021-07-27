def isPossible(x, y, n, col):
    for i in range(x):
        if y == col[i] or abs(x-i) == abs(y-col[i]):
            return False
    return True

def backtracking(x, n, col):
    if x == n:
        return 1
    
    count = 0
    
    for y in range(n):
        if isPossible(x, y, n, col):
            col[x] = y
            count += backtracking(x+1, n, col)

    return count
    
def solution(n):
    col = [0] * n
    answer = backtracking(0, n, col)
    return answer