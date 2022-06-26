# https://leetcode.com/problems/valid-parentheses/
class Solution:
    def isValid(self, s: str) -> bool:
        l_set = {'(','{','['}
        c_dict = {
            '(':')',
            '{':'}',
            '[':']'
        }
        stack = []
        for i in s:
            try:
                if i in l_set:
                    stack.append(i)
                elif c_dict[stack[-1]] == i:
                    stack.pop()
                else:
                    break
            except:
                return False
        if len(stack)!=0:
            return False
        return True