class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        k = sum(nums) - x

        if(k < 0):
            return -1

        if(k == 0):
            return len(nums)
        
        curr_sum = 0
        left = 0
        max_len = -1

        for right in range(len(nums)):
            curr_sum += nums[right]
            
            while(curr_sum > k):
                curr_sum -= nums[left]
                left += 1

            if(curr_sum == k):
                max_len = max(max_len, right - left + 1)

        if(max_len == -1):
            return -1
        else:
            return len(nums) - max_len