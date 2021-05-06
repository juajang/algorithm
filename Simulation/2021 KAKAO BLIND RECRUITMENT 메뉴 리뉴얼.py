from itertools import combinations

def solution(orders, course):
    answer = []
    count = {}
    for order in orders:
        menu = [i for i in order]
        menu.sort()
        for n in course:
            for candidate in combinations(menu, n):
                if candidate not in count:
                    count[candidate] = 1
                else:
                    count[candidate] += 1
    
    courses = [[] for _ in range(11)]
    coursesCnt = [0] * 11
    for candidate in count:
        currCnt = count[candidate]
        currLen = len(candidate)
        menu = ''.join(candidate)
        if currCnt > coursesCnt[currLen]:
            courses[currLen] = [menu]
            coursesCnt[currLen] = currCnt
        elif currCnt == coursesCnt[currLen]:
            courses[currLen].append(menu)
    
    for c in course:
        if coursesCnt[c] < 2:
            continue
        for i in courses[c]: 
            answer.append(i)
    answer.sort()
    
    return answer