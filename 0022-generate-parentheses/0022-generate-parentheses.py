class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        
        res = []

        def backtrack(open, close, curr):
            if open == n and close == n:
                res.append(curr)
                return

            if open < n:
                backtrack(open + 1, close, curr + '(')
            
            if close < open:
                backtrack(open, close + 1, curr + ')')

        backtrack(0, 0, "")
        return res