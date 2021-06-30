def solution(s):
    answer = [0, 0]
    arr = [int(i) for i in s]

    while arr != [1]:
        prevLen = len(arr)
        arr = [i for i in arr if i != 0]
        num = len(arr)
        answer[1] += prevLen - num
        answer[0] += 1
        
        # 2진법으로 표현 
        res = []
        while num > 1:
            res.append(num % 2)
            num = num // 2
        res.append(num)
        res.reverse()
        
        arr = [i for i in res]
        
    return answer