class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        idx = nums.index(0)

        clockwise = True
        for i in range(n):
            if nums[(idx + i) % n] != i:
                clockwise = False
                break
        
        anticlock = True
        for i in range(n):
            if nums[(idx - i + n) % n] != i:
                anticlock = False
                break
        
        ans = float('inf')
        if clockwise:
            ans = min(ans, idx)
            ans = min(ans, n - idx + 2)

        if anticlock:
            ans = min(ans, ((idx + 1) % n) + 1)
            ans = min(ans, 1 + (n - 1 - idx))

        return ans if ans != float('inf') else -1