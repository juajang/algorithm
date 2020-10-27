def solution(A,B):
    answer = 0
    A = sorted(A)
    B = sorted(B, reverse = True)
    for i in range(len(A)):
        a = A[0]
        b = B[0]
        answer += a * b
        del A[0]
        del B[0]
    return answer