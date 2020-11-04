def dfs(cur, tickets, visit, answer):
    for i, route in enumerate(tickets):
        if visit[i] == False and route[0] == cur:
            visit[i] = True
            answer.append(route[1])
            answer = dfs(route[1], tickets, visit, answer)
            if len(answer) == len(tickets) + 1:     
                break
            answer.pop(-1)
            visit[i] = False
    return answer

def solution(tickets):
    visit = [False] * len(tickets)
    tickets.sort()
    answer = dfs("ICN", tickets, visit, ["ICN"])
    return answer