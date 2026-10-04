class Solution:
    def checkValidString(self, s: str) -> bool:
        open = []
        asterisk = []

        for i in range(len(s)):
            if s[i] == '(':
                open.append(i)
            elif s[i] == '*':
                asterisk.append(i)
            else:
                if open:
                    open.pop()
                elif asterisk:
                    asterisk.pop()
                else:
                    return False
        
        while open and asterisk:
            if open[-1] > asterisk[-1]:
                return False
            open.pop()
            asterisk.pop()

        return len(open) == 0