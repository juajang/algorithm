def solution(A, B):
    answer = 0
    
    A.sort()
    B.sort()
    N = len(A)
    
    j = 0
    for i in range(N):
        while j < N and A[i] >= B[j]:
            j += 1
        if j < N and A[i] < B[j]:
            answer += 1
            j += 1
            
    return answer