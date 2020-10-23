from collections import deque

# 내가 푼 방법 
def solution(priorities, location):
    answer = 0
    check = {}
    dq = deque()
    
    for p in priorities:
        dq.append(p)
        if p in check:
            check[p] += 1
        else:
            check[p] = 1
            
    idx = 0
    printed = 0
    while dq:
        cur = dq.popleft()
        flag = True
        for p in priorities:
            if cur < p and check[p] > 0:
                flag = False
                break      
        
        if flag == False:
            dq.append(cur)
            if location == idx:
                location += len(dq)
            idx += 1
            continue

        printed += 1
        if location == idx:
            answer = printed
            break
        idx += 1
        check[cur] -= 1

    return answer

# enumerate와 any를 활용한 모범 답안 
def solution2(priorities, location):
    queue =  [(i,p) for i,p in enumerate(priorities)]
    answer = 0
    while True:
        cur = queue.pop(0)
        if any(cur[1] < q[1] for q in queue):
            queue.append(cur)
        else:
            answer += 1
            if cur[0] == location:
                return answer