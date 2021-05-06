def solution(lines):
    answer = 0
    responses = []
    
    for line in lines:
        line = line[11:]
        hh, mm, ss = int(line[:2]), int(line[3:5]), float(line[6:12])
        cost = float(line[13:-1])
        print(hh, mm, ss, cost)
        endTime = hh * 3600 + mm * 60 + ss
        startTime = endTime - cost + 0.001
        responses.append((startTime, endTime))

    # 응답완료시간을 기준으로 오름차순 정렬되어 있음에 유의
    for i in range(len(responses)):
        end = responses[i][1] + 1
        count = 0
        for j in range(i, len(responses)):
            start = responses[j][0]
            if start < end:
                count += 1
        answer = max(count, answer)
    
    return answer