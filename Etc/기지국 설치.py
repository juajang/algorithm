def solution(n, stations, w):
    answer = 0
    
    start, end = 1, 0
    cover = w * 2 + 1
    
    for i in range(len(stations)):
        end = stations[i] - w - 1        
        dist = end - start + 1
        
        if dist < 1:
            start = stations[i] + w + 1
            continue
            
        answer += dist // cover
        if dist % cover:
            answer += 1
        
        start = stations[i] + w + 1

    if start <= n:
        end = n 
        dist = end - start + 1
        
        answer += dist // cover
        if dist % cover:
            answer += 1

    return answer