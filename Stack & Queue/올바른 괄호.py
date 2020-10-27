def solution(string):
    stack = []  
    for s in string:
        if s == '(':
            stack.append('(')
        elif stack:
            stack.pop()
        else:
            return False
        
    return not stack