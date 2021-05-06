def solution(N, number):
    answer = -1
    
    # dp[i]: N를 i+1개 사용해서 만든 연산의 결과 
    dp = []
    
    for i in range (1,9) : 
        all_case = set()
        curr = int(str(N) * i)
        all_case.add(curr)
        
        # N를 i개 사용해서 만들 수 있는 결과 모두 구하기 
        for j in range(0,i-1):
            # 이전 연산에서 만들어두었던 결과 활용 
            for op1 in dp[j]:
                for op2 in dp[-j-1] :
                    all_case.add(op1 - op2)
                    all_case.add(op1 + op2)
                    all_case.add(op1 * op2)
                    if op2 != 0:
                        all_case.add(op1 // op2)
        
        if number in all_case:
            answer = i
            break

        dp.append(all_case) 
        
    return answer
    