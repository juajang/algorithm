def check(s):
    curr = []
    for a in s:
        if a == '[' or a == '(' or a == '{':
            curr.append(a)
        elif len(curr) > 0:
            last = curr[len(curr)-1]
            if a == ']' and last == '[':
                curr.pop(len(curr)-1)
            elif a == '}' and last == '{':
                curr.pop(len(curr)-1)
            elif a == ')' and last == '(':
                curr.pop(len(curr)-1)
        else:
            return False
        
    if len(curr) > 0:
        return False
    
    return True

def solution(s):
    answer = 0
    arr = s
    
    for _ in range(len(arr)):
        arr += arr[0]
        arr = arr[1:]
        if check(arr):
            answer += 1
        
    return answer