class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        res = 0
        match = True

        for i in range(len(nums)):
            if nums[i] != i:
                if match:
                    res = nums[i]
                    match = False
                else:
                    res &= nums[i]
                
        return res