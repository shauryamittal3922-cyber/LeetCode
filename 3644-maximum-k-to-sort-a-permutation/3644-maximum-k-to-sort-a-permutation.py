class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        res = None

        for i in range(len(nums)):
            if nums[i] != i:
                if res is None:
                    res = nums[i]
                else:
                    res &= nums[i]
                
        return 0 if res is None else res