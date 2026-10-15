class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)

        count_tree = [0] * (n+1)
        sum_tree = [0] * (n+1)

        last = {}
        ans = 0

        for right, num in enumerate(nums):
            prev = last.get(num, -1)

            count = 0
            idx_sum = 0

            i = n-prev-1

            while i > 0:
                count += count_tree[i]
                idx_sum += sum_tree[i]
                i -= i & -i

            length = right - prev

            ans += (n - right) * (length * length - 2 * (idx_sum - prev * count))

            i = n-prev

            while i <= n:
                count_tree[i] += 1
                sum_tree[i] += prev
                i += i & -i

            last[num] = right

        return ans