# https://leetcode.com/problems/pascals-triangle-ii/
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        result = []
        row = [1]
        for j in range(rowIndex+1):
            result=row
            nextrow = []
            nextrow.append(1)
            for i in range(len(row)-1):
                sumTwoEle = row[i]+row[i+1]
                nextrow.append(sumTwoEle)
            nextrow.append(1)
            row=nextrow
        return result 