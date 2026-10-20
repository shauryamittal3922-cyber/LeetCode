class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0

        for k in range(1, n+1):
            if n % k != 0:
                continue
            
            prev_max = float('-inf')
            sortable = True

            for start in range(0, n, k):
                block_min = min(nums[start : (start + k)])
                block_max = max(nums[start : (start + k)])

                if prev_max > block_min:
                    sortable = False
                    break
                descents = 0

                for i in range(start, (start + k)):
                    nxt = start + (i - start + 1) % k

                    if nums[i] > nums[nxt]:
                        descents += 1

                    if descents > 1:
                        sortable = False
                        break
                    
                prev_max = block_max

            if sortable:
                ans += k
        
        return ans