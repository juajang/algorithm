from collections import deque

def solution(bridge_length, weight, truck_weights):
    # 트럭이 다리를 건너기 시작한 시간
    crossing = deque()
    curWeight = 0

    i = 0
    time = 0
    
    while i < len(truck_weights):
        time += 1
        while crossing:
            t, w = crossing.popleft()
            # 트럭이 아직 다리에 있는 경우
            if t + bridge_length > time:
                crossing.appendleft((t, w))
                break
            curWeight -= w
                
        # 트럭이 추가로 건널 수 있음 
        if curWeight + truck_weights[i] <= weight:
            curWeight += truck_weights[i]
            crossing.append((time, truck_weights[i]))
            i += 1
            
    max_t = 0
    while crossing:
        t, w = crossing.popleft()
        max_t = max(t, max_t)
    
    time += time - max_t + bridge_length
    return time