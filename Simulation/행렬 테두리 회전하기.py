def solution(rows, columns, queries):
    answer = []
    arr = []
    arr.append([0] * (columns + 1))
    idx = 1
    for i in range(rows):
        arr.append([])
        arr[i+1].append(0)
        for _ in range(columns):
            arr[i+1].append(idx)
            idx += 1

    for x1, y1, x2, y2 in queries:
        curr = []
        x, y = x1, y1
        prev = arr[x][y]
        while True:
            print(x, y)
            if x == x1 and y < y2:
                y += 1
            elif x < x2 and y == y2:
                x += 1
            elif x == x2 and y > y2:
                y -= 1
            elif x > x1 and y == y1:
                x -= 1
            arr[x][y], prev = prev, arr[x][y]
            if x == x1 and y == y1:
                break
                
        for i in arr:
            for n in i:
                print("%02d "%n, end=' ')
            print()
        print()
    return answer

solution(6, 6, [[2,2,5,4],[3,3,6,6],[5,1,6,3]])
