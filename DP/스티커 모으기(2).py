def solution(sticker):
    n = len(sticker)
    cache1 = [0] * 100010
    cache2 = [0] * 100010
    
    if n <= 2:
        return max(sticker)
    
    # 원형으로 연결되어 있기 때문에 마지막 스티커를 뜯으면 첫 번째 스티커를 뜯지 못함 
    # 따라서 마지막 스티커와 첫 번째 스티커 둘 중 하나를 포기해야 하고, 이 두 가지 경우의 dp를 진행하기  
    
    # 1번 스티커를 뜯고 시작하는 dp, 마지막 스티커는 얻을 수 없음 
    cache1[0] = cache1[1] = sticker[0]
    for i in range(2, n - 1):
        cache1[i] = max(cache1[i - 1], cache1[i - 2] + sticker[i])
    
    # 1번 스티커는 두고 2번 스티커를 뜯고 시작하는 dp
    cache2[0] = 0
    cache2[1] = sticker[1]
    for i in range(2, n):
        cache2[i] = max(cache2[i - 1], cache2[i - 2] + sticker[i])
    
    answer = max(cache1[n - 2], cache2[n - 1])
    return answer