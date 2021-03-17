A, B, C = map(int, input().split())
cache = { 1: A }

def dp(B):
    if B in cache:
        return cache[B] % C
    if B % 2 == 0:
        cache[B] = dp(B // 2) * dp(B // 2)
    else:
        cache[B] = A * dp(B // 2) * dp(B // 2)
    return cache[B] % C

print(dp(B))