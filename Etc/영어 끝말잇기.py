def solution(n, words):
    answer = []
    
    count = [0] * (n + 1)
    check = {}
    end = words[0][0]
    
    idx = 1
    for word in words:
        if idx > n:
            idx = 1
            count[idx] += 1
        else:
            count[idx] += 1
            
        if end != word[0] or (check.get(word) is not None and check[word] == True):
            answer.append(idx)
            answer.append(count[idx])
            break
            
        check[word] = True
        end = word[-1]
        idx += 1
    
    if len(answer) == 0:
        answer.append(0)
        answer.append(0)
        
    return answer