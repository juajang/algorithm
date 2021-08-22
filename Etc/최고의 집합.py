def solution(n, s):
    answer = [-1]
    
    # 최대한 균등하게 나누기 
    numbers = [s // n for _ in range(n)]
    
    # 나누고 남은 남은 나머지 배분 
    for i in range(s % n):
        numbers[i] += 1
    
    if sum(numbers) < n:
        return answer
    else:
        answer = numbers
    
    answer.sort()
    return answer
    