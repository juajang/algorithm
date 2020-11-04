def solution(routes):
    answer = 1
    routes.sort()
    start, end = -30000, 30000
    for route in routes:
        if end < route[0]:
            start = route[0]
            end = route[1]
            answer += 1
        if start < route[0]:
            start = route[0]
        if end > route[1]:
            end = route[1]
    return answer