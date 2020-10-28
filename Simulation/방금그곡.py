def split(sheet):
    music = []
    j = 0
    while j < len(sheet) - 1:
        if sheet[j + 1] == '#':
            music.append(sheet[j] + sheet[j + 1])
            j += 2
        else:
            music.append(sheet[j])
            j += 1
    if j == len(sheet) - 1:
        music.append(sheet[j])    
    return music

def solution(my, musicinfos):
    musicinfos = [m.split(",") for m in musicinfos]
    played = []
    for i, info in enumerate(musicinfos):
        music = split(info[3])
        start = int(info[0][0:2]) * 60 + int(info[0][3:5]) 
        end = int(info[1][0:2]) * 60 + int(info[1][3:5]) 
        m = end - start
        p = []
        j = 0
        for _ in range(m):
            p.append(music[j])
            j = 0 if j == len(music) - 1 else j + 1
        played.append((m, -i, p, info[2]))
    played.sort(reverse = True)
    lenMy = len(split(my))
    for p in played:
        for i in range(len(p[2]) - lenMy + 1):
            if "".join(p[2][i:i + lenMy]) == my:
                return p[3]
    return "(None)"