def solution(s):
    tuples = s[2:-2].split('},{')
    tuples = [tuple(map(int, t.split(','))) for t in tuples]
    count = [0] * 100010
    arr = []
    for t in tuples:
        for n in t:
            count[n] += 1
        if len(t) > len(arr):
            arr = t
    answer = [0] * len(arr)
    for n in arr:
        answer[len(arr) - count[n]] = n
    return answer
