def solution(gems):
    TYPE_NUM = len(set(gems))
    GEMS_NUM = len(gems)
    answer = []
    
    start, end = 0, 0
    DIST, INDEX = 0, 1
    
    curr = {gems[0]: 1}
    while start < GEMS_NUM and end < GEMS_NUM:
        if len(curr) < TYPE_NUM:
            end += 1
            if end == GEMS_NUM:
                break
            # 보석 종류 count + 1
            curr[gems[end]] = curr.get(gems[end], 0) + 1
        else:
            answer.append((end - start, [start + 1, end + 1]))
            curr[gems[start]] -= 1
            if curr[gems[start]] == 0:
                del curr[gems[start]]
            start += 1
    answer = sorted(answer, key=lambda x:(x[DIST], x[INDEX]))
    return answer[0][INDEX]
    