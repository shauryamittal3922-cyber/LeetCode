class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []

        for i in s:
            if i == ')':
                temp = []
                while stack and stack[-1] != '(':
                    temp.append(stack.pop())

                if stack:
                    stack.pop()

                stack.extend(temp)

            else:
                stack.append(i)
        
        return "".join(stack)