def solution(n, money):
    answer = 0
    cache = [0] * (n + 1)
    
    for i in range(n + 1):
        if i % money[0] == 0:
            cache[i] = 1
    
    # 1로만 n을 만들고, 2로만 n을 만들고... 화폐 단위만큼 반복 
    for m in money[1:]:
        # (2, 3) -> 5, (3, 2) -> 5는 같은 경우
        # 따라서 중복 합산되는 것을 막기 위해 i >= m 인 경우에만 갱신 
        for i in range(1, n + 1):
            if i >= m:
                cache[i] += cache[i - m] % 1000000007
                
    return cache[n] 