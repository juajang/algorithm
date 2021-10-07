from itertools import product

# 풀이 출처 https://latte-is-horse.tistory.com/m/217?category=0

def solution(word):
    dictionary = []
    for i in range(1, 6):
        dictionary.extend(list(map(''.join, product(['A', 'E', 'I', 'O', 'U'], repeat = i))))
    dictionary.sort()
    return dictionary.index(word) + 1