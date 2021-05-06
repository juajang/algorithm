def getTime(hh, mm):
    rm, rh = mm, hh
    if mm != 0:
        rm -= 1 
    else:
        rm = 59
        rh -= 1
    return (rh, rm)

def solution(n, t, m, timetable):
    answer = ''
    times = []
    for time in timetable:
        times.append((int(time[:2]), int(time[3:])))
    times.sort()

    mm = 0
    hh = 9
    idx = 0
    con_mm = 0
    con_hh = 0
    for i in range(n):
        cnt = 0
        while cnt < m and idx+cnt < len(times):
            curr = times[idx+cnt]
            # 기다리고 있는 사람보다 일찍 와야 탈 수 있는 경우 
            if i == n-1 and cnt == m-1 and idx+cnt < len(times):
                con_hh, con_mm = getTime(curr[0], curr[1])
            if curr[0] < hh or (curr[0] <= hh and curr[1] <= mm):
                cnt += 1
            else:
                break
        idx += cnt
        if i != n-1:
            if mm + t >= 60:
                mm += t - 60
                hh += 1
            else:
                mm += t
    
    # 셔틀버스에 다 타고도 자리가 남는 경우 - 막차 시간에 맞춰서 오면 됨 
    if cnt < m:
        con_hh, con_mm = hh, mm

    answer = '0' + str(con_hh) if con_hh < 10 else str(con_hh)
    answer += ':'
    answer += '0' + str(con_mm) if con_mm < 10 else str(con_mm)
    return answer