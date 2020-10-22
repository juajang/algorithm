from itertools import permutations

def isPrime(num):
    if num < 2:
        return False
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

# 내가 푼 풀이 
def solution(numbers):
    answer = 0
    
    arr = []
    for i in range(len(numbers)):
        arr.append(int(numbers[i]))
        
    nums = []
    for i in range(len(numbers)):
        nums.append(list(permutations(arr, i + 1)))
    
    primes = {}
    for i in nums:
        for j in i:
            prod = 1
            sum = 0
            for k in j:
                sum += prod * k
                prod *= 10
            if sum in primes:
                continue
            elif isPrime(sum) == True:
                answer += 1
                primes[sum] = True

    return answer

# 에라토스테네스의 체를 이용한 풀이 
def solution2(n):
    a = set()
    
    # list를 이용하면 문자열을 바로 list로 만들 수 있다
    # 각 문자를 붙여 10진수로 만들고 싶을 때는 반복문이 아니라 join을 활용하자
    for i in range(len(n)):
        a |= set(map(int, map("".join, permutations(list(n), i + 1))))
        
    a -= set(range(0, 2))
    for i in range(2, int(max(a) ** 0.5) + 1):
        # i * 2, i * 3, ... 배열의 가장 큰 숫자까지 지워나가기 
        a -= set(range(i * 2, max(a) + 1, i))
    return len(a)