class Solution:
    def maxDepth(self, s: str) -> int:
        max_depth = 0
        bracket = 0

        for i in range(len(s)):
            if s[i] == '(':
                bracket += 1
            elif s[i] == ')':
                if max_depth < bracket:
                    max_depth = bracket
                bracket -= 1
            else:
                pass
        
        return max_depth