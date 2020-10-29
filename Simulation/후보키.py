from itertools import combinations
from collections import deque

# 내가 푼 💩 풀이
def solution(relation):
    answer = 0
    keys = set()
    candidates = []
    col = len(relation[0])
    cidx = [i for i in range(col)]
    for i in range(1, col + 1):
        candidates.append(list(combinations(cidx, i)))
    cidx = []
    for candi in candidates:
        for c in candi:
            cidx.append(c)

    for c in cidx:
        check = True
        for key in keys:
            check = False
            for k in key:
                if k not in c:
                    check = True
                    break
            if check == False:
                break
        if not check:
            continue
        s = []
        flag = True
        for rel in relation:
            tmp = []
            for i in c:
                tmp.append(rel[i])
            for j in s:
                if tmp == j:
                    flag = False
                    break
            s.append(tmp)
        if flag:
            answer += 1
            for i in c:
                keys.add(c)
    return answer

# 훨씬 깔끔한 풀이 
# 리스트 x가 y에 포함되는지 알고싶다면 x, y를 set으로 만들고 intersection을 이용하자
# 리스트의 요소들을 모두 튜플로 묶을 수 있다 => 집합에 넣을 수 있음
# 두 리스트를 합치고 싶을때는 extend를 이용하자 
def solution2(relation):
    n_row=len(relation)
    n_col=len(relation[0])  #->runtime error 우려되는 부분

    candidates=[]
    for i in range(1,n_col+1):
        candidates.extend(combinations(range(n_col),i))

    final=[]
    for keys in candidates:
        tmp=[tuple([item[key] for key in keys]) for item in relation]
        if len(set(tmp))==n_row:
            final.append(keys)

    answer=set(final[:])
    for i in range(len(final)):
        for j in range(i+1,len(final)):
            if len(final[i])==len(set(final[i]).intersection(set(final[j]))):
                answer.discard(final[j])

    return len(answer)