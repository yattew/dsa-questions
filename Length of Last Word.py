# https://leetcode.com/problems/length-of-last-word/
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        substr = 0
        s = s.rstrip()
        for i in s[::-1]:
            if i not in ' ':
                substr+=1
                continue
            break
        return substr