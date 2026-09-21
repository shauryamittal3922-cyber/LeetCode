class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        result = [0] * k
        prev_count = [0] * k

        for num in nums:
            curr_count = [0] * k

            for rem in range(k):
                if(prev_count[rem] > 0):
                    new_rem = (rem * num) % k
                    curr_count[new_rem] += prev_count[rem]

            curr_count[num % k] += 1

            for i in range(k):
                result[i] += curr_count[i]

            prev_count = curr_count
        
        return result