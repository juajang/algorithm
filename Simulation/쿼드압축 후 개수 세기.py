def dfs(answer, arr, x, y, l):
    if l == 1:
        return
    curr = arr[x][y]
    check = True
    ll = l // 2
    
    for i in range(x, x+l):
        for j in range(y, y+l):
            if curr != arr[i][j]:
                check = False
                break
                
    if check == False:
        dfs(answer, arr, x, y, ll)
        dfs(answer, arr, x+ll, y, ll)
        dfs(answer, arr, x, y+ll, ll)
        dfs(answer, arr, x+ll, y+ll, ll)
        
    else:
        for i in range(x, x+l):
            for j in range(y, y+l):
                arr[i][j] += 10
        answer[curr] += 1

def solution(arr):
    answer = [0, 0]
    dfs(answer, arr, 0, 0, len(arr))
    for row in arr:
        for i in row:
            if i == 0:
                answer[0] += 1
            elif i == 1:
                answer[1] += 1
    return answer