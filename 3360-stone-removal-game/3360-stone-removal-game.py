class Solution:
    def canAliceWin(self, n: int) -> bool:
        
        k = 10
        while n >= 0 and k > 0:
            n -= k
            k -= 1
        

        if k % 2 == 0:
            return True
        return False