def solution(string):
    answer = [s.capitalize() for s in string.split(' ')]
    answer = ' '.join(answer)
    return answer