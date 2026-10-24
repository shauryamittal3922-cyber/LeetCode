class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        def totalDays(date: str) -> int:
            month = int(date[0:2])
            day = int(date[3:5])

            return sum(days[:month - 1]) + day
        
        alice_start = totalDays(arriveAlice)
        alice_end = totalDays(leaveAlice)
        bob_start = totalDays(arriveBob)
        bob_end = totalDays(leaveBob)

        start = max(alice_start, bob_start)
        end = min(alice_end, bob_end)

        if start > end:
            return 0
        return end - start + 1