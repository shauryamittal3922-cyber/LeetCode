class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        both = min(need1, need2)
        res = both * min(costBoth, cost1 + cost2)
        need1 -= both
        need2 -= both
        res += need1 * min(costBoth, cost1) + need2 * min(costBoth, cost2)
        return res