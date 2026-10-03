class Solution:
    def longestValidParentheses(self, s: str) -> int:
        open = 0
        close = 0
        max_valid = 0

        for ch in s:
            if ch == '(':
                open += 1
            else:
                close += 1
            
            if open == close:
                max_valid = max(max_valid, 2*close)
            
            if close > open:
                open = close = 0
            
        open = close = 0
        for ch in reversed(s):
            if ch == '(':
                open += 1
            else:
                close += 1
            
            if open == close:
                max_valid = max(max_valid, 2*open)

            if open > close:
                open = close = 0
            
        return max_valid