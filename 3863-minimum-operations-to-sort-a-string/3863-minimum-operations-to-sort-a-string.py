class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)

        if all(s[i] <= s[i+1] for i in range(n-1)):
            return 0

        if n == 2:
            return -1

        minm = min(s)
        maxm = max(s)

        if s[0] == minm or s[-1] == maxm:
            return 1
        
        if minm in s[:-1] or maxm in s[1:]:
            return 2
        
        return 3