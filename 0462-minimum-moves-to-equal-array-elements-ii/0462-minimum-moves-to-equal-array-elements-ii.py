class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        med = int(statistics.median(nums))
        moves = 0

        for num in nums:
            moves += abs(num - med)
        return moves