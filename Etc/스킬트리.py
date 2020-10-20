def solution(skill, skill_trees):
    answer = 0
    
    check = {}
    for i in skill:
        check[i] = True

    for tree in skill_trees:
        j = 0
        isValid = True
        for i in range(len(tree)):
            # 선행 스킬이 필요한 스킬이라면
            if check.get(tree[i]) is not None:
                if tree[i] != skill[j]:
                    isValid = False
                    break
                j += 1
            if i == len(tree) - 1:
                answer += 1
                
    return answer