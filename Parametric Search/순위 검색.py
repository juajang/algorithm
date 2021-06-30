from itertools import combinations 

def solution(info, queries):
    answer = []
    info_dict = {}
    
    for information in info:
        temp = information.split(' ')
        for i in range(5):
            for comb in combinations(temp[:4], i):
                key = ''.join(comb)
                if key in info_dict:
                    info_dict[key].append(int(temp[-1]))
                else:
                    info_dict[key] = [int(temp[-1])]
    
    # 이분 탐색을 위한 정렬
    for key in info_dict:
        info_dict[key].sort()
        
    for query in queries:
        conditions = [i for i in query.split(' and ') if i != '-']
        conditions[-1], target_score = conditions[-1].split(' ')
        if conditions[-1] == '-':
            del conditions[-1]
        res = ''.join(conditions)

        # 점수를 제외한 조건이 맞는 경우 - 점수가 기준에 미치는지 이분탐색으로 확인 
        # lower bound: target_score 이상인 값이 처음으로 나타나는 위치 
        if res in info_dict:
            scores = info_dict[res]
            left, right = 0, len(scores) - 1
            while left <= right:
                mid = (left + right) // 2
                if int(target_score) > scores[mid]:
                    left = mid + 1
                else:
                    right = mid - 1 
            
            # target_score 이상인 값의 개수 
            # [50, 80, 150, 210] / target 100 -> left 2
            answer.append(len(scores) - left)
            
        else:
            answer.append(0)
            
    return answer