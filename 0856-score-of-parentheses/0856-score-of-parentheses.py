class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack = [0]

        for ch in s:
            if ch == '(':
                stack.append(0)
            else:
                score = stack.pop()

                curr_score = max(2*score, 1)
                stack[-1] += curr_score
        
        return stack.pop()