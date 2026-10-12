class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        mod = 1000000007
        bit_count = [0] * 32

        for num in nums:
            for i in range(30):
                if(num >> i) & 1:
                    bit_count[i] += 1
        
        sq_sum = 0

        for _ in range(k):
            curr = 0
            for i in range(30):
                if bit_count[i] > 0:
                    curr |= (1 << i)
                    bit_count[i] -= 1

            sq_sum = (sq_sum + curr*curr) % mod
        
        return sq_sum