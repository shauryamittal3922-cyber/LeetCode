class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        left = 0
        right = (m*n) - 1

        while left <= right:
            mid = int(left + (right - left) / 2)
            row = int(mid / n)
            col = mid % n

            if(matrix[row][col] == target):
                return True

            elif(matrix[row][col] < target):
                left = mid + 1
            else:
                right = mid - 1
        
        return False