class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        mod = 10**9 + 7

        def dfs(arr):
            if len(arr) <= 2:
                return 1

            left = [x for x in arr[1:] if x < arr[0]]
            right = [x for x in arr[1:] if x > arr[0]]

            return math.comb(len(arr) - 1, len(left)) * dfs(left) * dfs(right) % mod
        
        return (dfs(nums) - 1) % mod