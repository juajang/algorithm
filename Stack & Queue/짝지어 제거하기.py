from collections import deque

def solution(s):
    stack = deque(s[0])
    for i in range(1, len(s)):
        if stack:
            prev = stack.pop()
            if prev != s[i]:
                stack.append(prev)
                stack.append(s[i])
        else:
            stack.append(s[i])
    return 1 if not stack else 0