def gcd(a, b):
    if b != 0:
        return gcd(b, a % b)
    else:
        return a
    
def solution(w,h):    
    g = gcd(w, h)
    smallW = w / g
    smallH = h / g
    
    # smallW + smallH - 1 = 최소 단위의 사각형에서 멀쩡하지 않은 사각형의 개수 
    answer = w * h - g * (smallW + smallH - 1)
    
    return answer