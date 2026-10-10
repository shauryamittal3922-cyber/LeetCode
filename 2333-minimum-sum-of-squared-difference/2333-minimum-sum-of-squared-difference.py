class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        diffs = [abs(a - b) for a, b in zip(nums1, nums2)]

        if sum(diffs) <= k:
            return 0

        max_diff = max(diffs)
        freq = [0] * (max_diff + 1)

        for diff in diffs:
            freq[diff] += 1

        for diff in range(max_diff, 0, -1):
            moves = min(k, freq[diff])
            freq[diff] -= moves
            freq[diff - 1] += moves
            k -= moves

            if k == 0:
                break

        return sum(diff**2 * count for diff, count in enumerate(freq))