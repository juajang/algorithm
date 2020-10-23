# 같은 문자열이 10번 이상 나온 경우 -> 10ab... 2글자 추가됨 
def calcLen(cnt):
    if cnt >= 100:
        return 3
    if cnt >= 10:
        return 2
    if cnt > 1:
        return 1
    return 0

def solution(s):
    answer = 1000
    
    for n in range(1, len(s) + 1):
        prev = "".join(s[:n])
        i = n
        str_len = 0
        cnt = 1
        
        # 1, 2, 3 ... 개씩 잘라서 문자열 압축 
        while i < len(s) - n + 1:
            cur = "".join(s[i : i + n])
            i += n
            
            # 이전에 나왔던 문자열과 같은 경우, 압축 가능 
            if prev == cur:
                cnt += 1

            else:
                str_len += n + calcLen(cnt)
                prev = cur
                cnt = 1
            
        str_len += n + calcLen(cnt)
            
        # 문자열이 자르고 남은 경우 
        if len(s) % n:
            str_len += len(s) % n

        answer = min(str_len, answer)
            
    return answer