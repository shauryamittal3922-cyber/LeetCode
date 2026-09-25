class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        res = set()

        def dfs(exp: str):
            j = exp.find('}')

            if j == -1:
                res.add(exp)
                return
            
            i = exp.rfind('{', 0, j)

            before = exp[:i]
            after = exp[j+1:]
            between = exp[i+1:j].split(',')

            for k in  between:
                dfs(before + k + after)

        dfs(expression)
        return sorted(list(res))