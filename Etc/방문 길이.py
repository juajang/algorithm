def solution(dirs):
    answer = 0
    
    path = {}
    x, y = 0, 0
    
    for dir in dirs:
        nx, ny = x, y
        if dir == "U":
            nx = x + 1
        elif dir == "D":
            nx = x - 1
        elif dir == "R":
            ny = y + 1
        elif dir == "L":
            ny = y - 1
            
        if nx > 5 or nx < -5 or ny > 5 or ny < -5:
            continue
            
        if path.get((x, y, nx, ny)) is None and path.get((nx, ny, x, y)) is None:
            answer += 1
            
        path[(x, y, nx, ny)] = True
        path[(nx, ny, x, y)] = True
        x, y = nx, ny
        
    return answer