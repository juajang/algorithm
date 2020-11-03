def solution(genres, plays):
    answer = []
    album = []
    albumIdx = {}
    idx = 0
    for i in range(len(genres)):
        if genres[i] not in albumIdx:
            albumIdx[genres[i]] = idx
            idx += 1
            album.append([])
        album[albumIdx[genres[i]]].append((plays[i], i))
    rank = []
    counts = {}
    for plays in album:
        count = 0
        for play in plays:
            count += play[0]
        rank.append(count)
        plays = [(i, -j) for i, j in plays]
        counts[count] = plays
    rank.sort(reverse = True)
    for i in rank:
        counts[i] = sorted(counts[i], reverse = True)
        answer.append(-counts[i][0][1])
        if len(counts[i]) >= 2:
            answer.append(-counts[i][1][1])
    return answer