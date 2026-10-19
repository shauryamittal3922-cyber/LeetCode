class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        low = 0
        count = 0

        for i in nums:
            if i < target:
                low += 1
            elif i == target:
                count += 1
            
        return list(range(low, low + count))