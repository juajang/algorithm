def solution(n):
    answer = []
    arr = [[] for _ in range(n)]
    start, end = 0, n-1
    idx = 1
    
    while start <= end:
        no = end - start + 1
        temp = [[] for _ in range(n)]
        
        for i in range(start, end+1):
            temp[i].append(idx)
            idx += 1
        for i in range(no-2):
            temp[end].append(idx)
            idx += 1
        for i in range(end, start, -1):
            temp[i].append(idx)
            idx += 1

        for i in range(start, end+1):
            k = len(arr[i]) // 2
            for j in temp[i]:
                arr[i].insert(k, j)
                k += 1
                
        start += 2
        end -= 1
        
    for i in arr:
        answer += i 
    return answer