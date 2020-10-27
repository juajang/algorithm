import sys
sys.setrecursionlimit(10 ** 8)
cache = {}

def getPoint(land, x, y):
    if (x, y) in cache:
        return cache[(x, y)]
    if x == len(land):
        return 0
    maxPoint = 0
    for i in range(4):
        if i != y:
            maxPoint = max(maxPoint, getPoint(land, x + 1, i))
    cache[(x, y)] = land[x][y] + maxPoint
    return cache[(x, y)]

def solution(land):
    answer = 0
    for i in range(4):
        answer = max(answer, getPoint(land, 0, i))
    return answer