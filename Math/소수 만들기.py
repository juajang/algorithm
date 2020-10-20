from itertools import combinations

def isPrime(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

def solution(nums):
    answer = 0

    comb = list(combinations(nums, 3))
    
    primes = {}
    
    for arr in comb:
        sum = 0
        for num in arr:
            sum += num
            
        if primes.get(sum) is None:
            primes[sum] = isPrime(sum)
            
        if primes[sum] == True:
            answer += 1
        
    return answer