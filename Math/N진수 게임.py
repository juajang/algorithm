def getNum(x, n):
    arr = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    tmp = ''
    while x // n != 0:
        remainder = x % n
        tmp = arr[remainder] + tmp
        x = x // n
    tmp = arr[x % n] + tmp
    return tmp

def solution(n, t, m, p):
    answer = ''
    numbers = ''
    for i in range(t * m):
        numbers += getNum(i, n)
    idx = p - 1
    for i in range(t):
        answer += numbers[idx]
        idx += m
    return answer