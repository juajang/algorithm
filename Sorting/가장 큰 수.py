def solution(numbers):
    # 맨 앞자리 수를 기준으로 정렬하기 위해서 string으로 변환
    # 333 > 303030 
    numbers = list(map(str, numbers)) 
    
    # 같은 숫자를 반복해서 만들고 정렬
    # 1 -> 111 / 10 -> 101010  ===> 1 > 10
    numbers.sort(key=lambda x: x*3, reverse=True) 
    
    return str(int(''.join(numbers)))