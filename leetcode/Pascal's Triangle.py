# https://leetcode.com/problems/pascals-triangle/
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = []
        row = [1]
        for j in range(numRows):
            result.append(row)
            nextrow = []
            nextrow.append(1)
            for i in range(len(row)-1):
                sumTwoEle = row[i]+row[i+1]
                nextrow.append(sumTwoEle)
            nextrow.append(1)
            row=nextrow
        return result  