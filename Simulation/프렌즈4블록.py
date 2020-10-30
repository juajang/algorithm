def find(m, n, board):
    tmp = []
    for i in range(m - 1):
        for j in range(n - 1):
            if board[i][j] == '':
                continue
            if board[i][j] == board[i][j + 1] == board[i + 1][j] == board[i + 1][j + 1]:
                tmp.extend([(i, j), (i, j + 1), (i + 1, j), (i + 1, j + 1)])
    return set(tmp)

def erase(blocks, m, n, board):
    for i in range(m):
        for j in range(n):
            if (i, j) in blocks:
                board[i][j] = ''
                for k in range(i - 1, -1, -1):
                    board[k + 1][j] = board[k][j]
                    board[k][j] = ''
    
def solution(m, n, board):
    answer = 0
    tmp = [[] for _ in range(len(board))]
    for i, b in enumerate(board):
        for block in b:
            tmp[i].append(block)
    board = tmp
    while True:
        blocks = find(m, n, board)
        if len(blocks) == 0:
            break
        answer += len(blocks)
        erase(blocks, m, n, board)
    return answer