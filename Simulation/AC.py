import sys
from copy import deepcopy
input = sys.stdin.readline

K = int(input())
for _ in range(K):
    p = input()
    n = int(input())
    if n > 0:
        numbers = list(map(int, input()[1:-2].split(",")))
    else:
        t = input()
        numbers = []

    isError = False
    reverse = False
    start, end = 0, n
    for cmd in p:
        if cmd == "R":
            reverse = not reverse
        elif cmd == "D":
            if start >= end:
                isError = True
                break
            if reverse:
                end -= 1
            else:
                start += 1
    
    if isError == False:
        print('[', end='')
        rg = range(end-1, start-1, -1) if reverse else range(start, end)
        end = start if reverse else end - 1
        for i in rg:
            if i != end:
                print(numbers[i], end=',')
            else:
                print(numbers[i], end='')
        print(']')
    else:
        print("error")
