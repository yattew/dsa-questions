# https://leetcode.com/problems/valid-palindrome/
class Solution:
    def isPalindrome(self, s: str) -> bool:
        output = ''.join([char for char in s.lower() if char.isalpha() or char.isdigit()])
        return output == output[::-1]