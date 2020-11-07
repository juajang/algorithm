from itertools import combinations

def solution(numbers):
    comb = list(map(sum, list(combinations(numbers, 2))))
    comb = list(set(comb))
    comb.sort()
    return comb