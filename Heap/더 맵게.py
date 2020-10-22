import heapq

def solution(scoville, K):
    answer = 0
    heap = []
    
    for s in scoville:
        heapq.heappush(heap, s)
        
    while heap:
        a = heapq.heappop(heap)
        
        if a >= K:
            break
            
        if heap:
            b = heapq.heappop(heap)
        else:
            break
        
        heapq.heappush(heap, a + b * 2)
        answer += 1
        
    if a < K:
        answer = -1
        
    return answer