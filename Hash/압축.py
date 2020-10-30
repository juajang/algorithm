import string

def solution(msg):
    answer = []
    dic = {}
    for i, alpha in enumerate(string.ascii_uppercase):
        dic[alpha] = i + 1
    i = 0
    dicIdx = len(dic) + 1
    while i < len(msg):
        j = 1
        while i + j <= len(msg) and msg[i:i + j] in dic:
            j += 1
        j -= 1
        w = msg[i:i + j]      
        answer.append(dic[w])
        if i + j < len(msg):
            dic[w + msg[i + j]] = dicIdx
            dicIdx += 1
        i += j 
    return answer