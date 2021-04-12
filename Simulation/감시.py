dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

cctv1 = [[0], [1], [2], [3]]
cctv2 = [[1, 3], [0, 2]]
cctv3 = [[0, 1], [1, 2], [2, 3], [3, 0]]
cctv4 = [[3, 0, 1], [0, 1, 2], [1, 2, 3], [2, 3, 0]]
cctv5 = [[0, 1, 2, 3]]
cctvs = { 1: cctv1, 2: cctv2, 3: cctv3, 4: cctv4, 5: cctv5 }

def find(x, y, directions):
    results = []
    for direction in directions:
        temp = set()
        for d in direction:
            nx, ny = x, y
            while True:
                nx += dx[d]
                ny += dy[d]
                if nx < 0 or nx >= N or ny < 0 or ny >= M:
                    break
                if board[nx][ny] == 6:
                    break
                if board[nx][ny] == 0:
                    temp.add((nx, ny))
        results.append(temp)
    return results

count = 0 
results = []
for i in range(N):
    for j in range(M):
        if board[i][j] in cctvs:
            result = find(i, j, cctvs[board[i][j]])
            results.append(result)
        elif board[i][j] == 0:
            count += 1

if len(result) == 0:
    print(count)
    
else:
    cells = results[0]
    for result in results[1:]:
        temp = []
        for candi in result:
            for cell in cells:
                temp.append(cell | candi)
        cells = temp   

    max_point = 0
    for cell in cells:
        if len(cell) > max_point:
            max_point = len(cell)
    answer = count - max_point
    print(answer)
