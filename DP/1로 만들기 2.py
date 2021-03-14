X = int(input())
cache = [[] for _ in range(X + 1)]
cache[1] = [1]

for i in range(2, X + 1): 
    length_res3, length_res2, length_res1 = i + 1, i + 1, i + 1

    if i % 3 == 0:
        res3 = [i] + cache[i // 3] 
        length_res3 = len(res3)
    if i % 2 == 0:
        res2 = [i] + cache[i // 2] 
        length_res2 = len(res2)

    res1 = [i] + cache[i - 1]
    length_res1 = len(res1)

    # 부등호에 유의, 같은 연산 횟수라도 방법은 여러가지가 존재할 수 있다
    if length_res3 <= length_res2 and length_res3 <= length_res1:
        cache[i] = res3
    elif length_res2 <= length_res3 and length_res2 <= length_res1:
        cache[i] = res2
    else:
        cache[i] = res1

print(len(cache[X]) - 1)
for i in cache[X]:
    print(i, end=' ')