def solution(nums):
    s = set()
    for n in nums:
        s.add(n)
    if len(s) <= len(nums) // 2:
        return len(s)
    return len(nums) // 2