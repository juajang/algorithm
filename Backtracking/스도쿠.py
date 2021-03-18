board = [list(map(int, input())) for _ in range(9)]
row = [[0] * 10 for _ in range(9)]
col = [[0] * 10 for _ in range(9)]
square = [[0] * 10 for _ in range(9)]

answer = []

for i in range(9):
    for j in range(9):
        curr = board[i][j]
        box = (i // 3) * 3 + j // 3 
        row[i][curr] = 1
        col[j][curr] = 1 
        square[box][curr] = 1

def print_board(board):
    for b in board:
        for i in b:
            print(i, end='')
        print()  

def backtracking(x, y):
    global answer 
    if x == 9:
        answer = board
        print_board(board)
        return

    if answer:
        return

    curr = board[x][y]
    box = (x // 3) * 3 + y // 3 

    if curr != 0:
        if y == 8:
            backtracking(x + 1, 0)
        else:
            backtracking(x, y + 1)
        
    else:
        for i in range(1, 10):
            if row[x][i] or col[y][i] or square[box][i]:
                continue
            row[x][i] = 1
            col[y][i] = 1 
            square[box][i] = 1
            board[x][y] = i

            if y == 8:
                backtracking(x + 1, 0)
            else:
                backtracking(x, y + 1)

            row[x][i] = 0
            col[y][i] = 0 
            square[box][i] = 0
            board[x][y] = 0

backtracking(0, 0)