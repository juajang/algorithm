from bisect import bisect_left

n = int(input())
ports = list(map(int, input().split()))

# 가장 긴 증가하는 부분 수열 
result = []
for port in ports:
    if len(result) == 0 or result[-1] < port:
        result.append(port)
    else:
        idx = bisect_left(result, port)
        result[idx] = port
    
print(len(result))
