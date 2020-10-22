from collections import deque

def solution(progresses, speeds):
    answer = []
    
    dists = deque()
    for i in range(len(progresses)):
        day = 0
        while progresses[i] < 100:
            progresses[i] += speeds[i]
            day += 1 
        dists.append(day)
    
    last = -1 
    idx = -1
    while dists:
        d = dists.popleft()
        
        # 개발 순서가 앞에 있는 기능이 아직 완성되지 않은 경우
        if d <= last:
            answer[idx] += 1
        
        else:
            answer.append(1)
            last = d 
            idx += 1

    return answer