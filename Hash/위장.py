from collections import Counter
from functools import reduce

def solution(clothes):
    # Counter: 컨테이너에 동일한 값의 자료가 몇 개인지 파악 
    cnt = Counter([kind for name, kind in clothes])
    
    # 옷의 종류 + 1 (옷을 안 입는 경우)씩 곱해주기
    # -1은 옷을 모두 안 입는 경우 
    answer = reduce(lambda x, y: x * (y + 1), cnt.values(), 1) - 1
    return answer