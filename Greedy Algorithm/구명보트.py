def solution(people, limit):
    answer = 0
    people.sort()
    
    left, right = 0, len(people) - 1
    while left < right:
        if people[left] + people[right] <= limit:
            people[left] = 0
            people[right] = 0
            left += 1
            answer += 1
        right -= 1
    
    answer += sum(1 if a > 0 else 0 for a in people)
    return answer