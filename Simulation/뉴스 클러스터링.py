def split(s):
    s = s.lower()
    arr = []
    for i in range(len(s) - 1):
        if s[i].isalpha() and s[i + 1].isalpha():
            arr.append(s[i] + s[i + 1])
    return arr

def solution(str1, str2):
    a = split(str1)
    b = split(str2)
    if len(a) == 0 and len(b) == 0:
        return 65536
    check = {}
    for s in a:
        if s in check:
            check[s] += 1
        else:
            check[s] = 1
    intersection = 0
    for s in b:
        if s in check and check[s] > 0:
            check[s] -= 1
            intersection += 1
    union = len(a) + len(b) - intersection
    jac = int(intersection / union * 65536)
    return jac