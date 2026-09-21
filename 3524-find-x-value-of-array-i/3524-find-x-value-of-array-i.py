class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        result = [0] * k
        prev_rem = [0] * k

        for num in nums:
            curr_rem = [0] * k

            for rem in range(k):
                if(prev_rem[rem] > 0):
                    new_rem = (rem * num) % k
                    curr_rem[new_rem] += prev_rem[rem]

            curr_rem[num % k] += 1

            for i in range(k):
                result[i] += curr_rem[i]

            prev_rem = curr_rem
        
        return result