from collections import deque

def solution(cacheSize, cities):
    answer = 0
    cities = [city.lower() for city in cities]
    cache = []
    for city in cities:
        answer += 1 if city in cache else 5 
        if cacheSize > 0:
            if len(cache) < cacheSize:
                cache.append(city)
            elif city not in cache:
                cache.pop(0)
                cache.append(city)
            else:
                cache.pop(cache.index(city))
                cache.append(city)
    return answer