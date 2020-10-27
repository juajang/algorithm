def solution(board):
    answer = 0
    
    row = len(board)
    col = len(board[0])

    if row <= 1 or col <= 1:
        return 1
    
    for i in range(1, row):
        for j in range(1, col):
            if board[i][j] == 0:
                continue
            cur = min (board[i-1][j], board[i][j-1], board[i-1][j-1]) + 1
            board[i][j] = cur
            answer = max(board[i][j] ** 2, answer)
            
    return answer