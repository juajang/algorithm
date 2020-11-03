from collections import deque

def solution(begin, target, words):
    answer = 0
    dq = deque()
    dq.append((begin, 0))
    visited = {}
    visited[begin] = True
    
    while dq:
        cur, cost = dq.popleft()
        if cur == target:
            answer = cost
            break
        for word in words:
            if word in visited:
                continue
            tmp = 0
            for i in range(len(word)):
                if word[i] == cur[i]:
                    tmp += 1
            if tmp == len(word) - 1:
                visited[word] = True
                dq.append((word, cost + 1))
            
    return answer