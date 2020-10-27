from collections import deque

def isCorrect(string):
    dq = deque()
    for s in string:
        if s == '(':
            dq.append(s)
        elif dq:
            dq.popleft()
        else:
            return False
    return False if dq else True

def divide(string):
    cntLeft = cntRight = 0
    for i in range(len(string)):
        if string[i] == '(':
            cntLeft += 1
        elif string[i] == ')':
            cntRight += 1
        if cntLeft == cntRight:
            break
    u = string[:i + 1]
    v = string[i + 1:]
    return u, v

def recurse(string):
    if string == '':
        return string
    u, v = divide(string)
    if isCorrect(u):
        return u + recurse(v)
    else:
        res = '('
        res += recurse(v)
        res += ')'
        u = u[1:-1]
        u = ''.join([')' if s == '(' else '(' for s in u])
        res += u 
        return res

def solution(p):
    if isCorrect(p):
        return p
    answer = recurse(p)
    return answer