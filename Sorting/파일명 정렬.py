def split(files):
    s = []
    for i, file in enumerate(files):
        start = 0
        while file[start].isdigit() is False:
            start += 1
        end = start
        while end < len(file) and file[end].isdigit():
            end += 1
        s.append([file[:start].lower(), int(file[start:end]), i])
    return s

def solution(files):
    answer = []
    parsedFiles = split(files)
    parsedFiles.sort()
    for file in parsedFiles:
        answer.append(files[file[2]])
    return answer

import re

# 정규 표현식을 이용한 모범 풀이
# 우선 순위가 더 낮은 쪽을 먼저 정렬하기 
def solution2(files):
    a = sorted(files, key=lambda file : int(re.findall('\d+', file)[0]))
    b = sorted(a, key=lambda file : re.split('\d+', file.lower())[0])
    return b