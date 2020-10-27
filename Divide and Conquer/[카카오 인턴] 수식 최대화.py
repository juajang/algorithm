from itertools import permutations

def calc(operator, i, expression):
    if i == 2:
        return str(eval(expression))
    # 낮은 우선순위의 연산을 하기 위해서는, 먼저 더 높은 우선순위의 연산을 해야한다. 
    if operator[i] == '+':
        res = eval('+'.join([calc(operator, i + 1, e) for e in expression.split('+')]))
    if operator[i] == '-':
        res = eval('-'.join([calc(operator, i + 1, e) for e in expression.split('-')]))
    if operator[i] == '*':
        res = eval('*'.join([calc(operator, i + 1, e) for e in expression.split('*')]))
    return str(res)

def solution(expression):
    answer = 0
    # 우선순위가 낮은 순대로 
    for operator in permutations(['+', '-', '*'], 3):
        answer = max(abs(int(calc(operator, 0, expression))), answer)
    return answer