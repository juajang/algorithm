# 나의 풀이 
def solution(citations):
    answer = 0

    check = [0] * 10010
    for c in citations:
        check[c] += 1

    m = max(citations)
    for i in range(m - 1, 0, -1):
        check[i] += check[i + 1]

    for i in range(m + 1):
        if check[i] >= i:
            answer = i

    return answer

# 정렬을 사용한 모범 답안 
def solution2(citations):
    citations = sorted(citations)
    l = len(citations)
    # H-Index는 가지고 있는 논문의 개수를 넘을 수 없다
    for i in range(l):
        # 인용 횟수가 가지고 있는 논문의 개수를 넘는 순간이 정답 
        if citations[i] >= l-i:
            return l-i
    return 0