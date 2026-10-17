class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def digit_sum(x: list[int]) -> int:
            return sum(int(d) for d in str(x))
        
        n = len(nums)

        sorted_nums = sorted(nums, key = lambda x: (digit_sum(x), x))

        pos = {val : i for i, val in enumerate(sorted_nums)}
        vis = [False] * n
        swaps = 0

        for i in range(n):
            if vis[i] or pos[nums[i]] == i:
                continue

            j = i
            while vis[j] == False:
                vis[j] = True
                j = pos[nums[j]]
                swaps += 1
            
            swaps -= 1

        return swaps