def solution(arr):
    answer = max(arr)
    i = 1
    while True:
        answer = max(arr) * i
        i += 1
        check = True
        for n in arr:
            if answer % n != 0:
                check = False
                break
        if check == True:
            break
    return answer