class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9*num:
            return ""
        
        nine = sum // 9
        rem = sum % 9

        if rem > 0:
            zero = num - nine - 1
            return "9" * nine + str(rem) + "0" * zero
        
        else:
            zero = num - nine
            return "9" * nine + "0" * zero