import heapq

def solution(n, works):
    answer = 0
    done = []
    for w in works:
        heapq.heappush(done, -w)
    
    for _ in range(n):
        curr = -heapq.heappop(done)
        heapq.heappush(done, -(curr - 1))

    while done:
        tmp = -heapq.heappop(done)
        if tmp > 0:
            answer += tmp * tmp
            
    return answer