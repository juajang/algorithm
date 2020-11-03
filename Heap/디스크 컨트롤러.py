def solution(jobs):
    answer = 0
    time = 0
    length = len(jobs)
    
    jobs = sorted(jobs, key=lambda x: x[1])
    
    while len(jobs):
        for i in range(len(jobs)):
            if jobs[i][0] <= time:
                time += jobs[i][1]
                answer += time - jobs[i][0]
                jobs.pop(i)
                break
            if i == len(jobs) - 1:
                time += 1
                
    return answer // length