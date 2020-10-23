def solution(number, k):
    collected = []
    
    for i, num in enumerate(number):
        # 이미 뽑은 숫자가 현재 숫자보다 작은 경우, 이미 뽑은 숫자를 제거 
        while len(collected) > 0 and collected[-1] < num and k > 0:
            collected.pop()
            k -= 1
        # 더 이상 제거하지 못하는 경우, 나머지 숫자들을 추가
        if k == 0:
            collected += list(number[i:])
            break
        collected.append(num)
    # 숫자가 오름차순으로 되어있어 k만큼 뽑지 못한 경우, 남은 k만큼 뒤를 자른다
    collected = collected[:-k] if k > 0 else collected
    answer = ''.join(collected)
    return answer