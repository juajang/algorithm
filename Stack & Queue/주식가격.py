from collections import deque

def solution(prices):
    N = len(prices)
    answer = [-1] * N
    
    dq = deque()
    
    for time in range(N):
        while dq:
            p, idx = dq.pop()

            # 가격이 떨어지지 않은 경우 
            if p <= prices[time]:
                dq.append((p, idx))
                break
            else:
                answer[idx] = time - idx
                    
        dq.append((prices[time], time))
    
    while dq:
        p, idx = dq.pop()
        answer[idx] = N - idx - 1

    return answer