N = 3
r, c, k = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(3)]
r -= 1
c -= 1

def sort_row():
    result = []
    max_len = 0
    for row in A:
        count = {}
        tmp = []
        for n in row:
            if n in count:
                count[n] += 1
            else:
                count[n] = 1

        for n in count.keys():
            if n == 0:
                continue
            tmp.append((count[n], n))
        tmp.sort()

        result_arr = []
        for cnt, num in tmp:
            result_arr.append(num)
            result_arr.append(cnt)
        max_len = max(max_len, len(result_arr))
        result.append(result_arr)

    for arr in result:
        len_arr = len(arr)
        for _ in range(len_arr, max_len):
            arr.append(0)
    
    return result

def sort_column():
    result = []
    max_len = 0
    for j in range(len(A[0])):
        count = {}
        tmp = []
        for i in range(len(A)):
            n = A[i][j]
            if n in count:
                count[n] += 1
            else:
                count[n] = 1

        for n in count.keys():
            if n == 0:
                continue
            tmp.append((count[n], n))
        tmp.sort()

        result_arr = []
        for cnt, num in tmp:
            result_arr.append(num)
            result_arr.append(cnt)
        max_len = max(max_len, len(result_arr))
        result.append(result_arr)
    
    for arr in result:
        len_arr = len(arr)
        for _ in range(len_arr, max_len):
            arr.append(0)
    
    result_arr = [[0] * len(A[0]) for _ in range(max_len)]
    for j in range(len(A[0])):
        for i in range(max_len):
            result_arr[i][j] = result[j][i]
    return result_arr

answer = 0
while True:
    if answer > 100:
        break
    if r < len(A) and c < len(A[0]) and A[r][c] == k:
        break
    answer += 1
    if len(A) >= len(A[0]):
        A = sort_row()
    else:
        A = sort_column()
print(answer if answer <= 100 else -1)