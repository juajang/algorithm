def solution(s):
    string = s.split(' ')
    numbers = [int(n) for n in string]
    numbers.sort()
    answer = str(numbers[0]) + " " + str(numbers[-1])
    return answer