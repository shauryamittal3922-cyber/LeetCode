class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums = sorted(x*x for x in nums)
        n = len(nums)
        mid = n//2

        res = sum(nums[mid:]) - sum(nums[:mid])
        return res