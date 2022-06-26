# https://leetcode.com/problems/longest-common-prefix/
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = min(len(x) for x in strs)
        substr = ""
        for i in range(min_len):
            char = strs[0][i]
            flag = True
            for j in strs[1:]:
                if j[i]!=char:
                    flag = False
                    break
            if flag:
                substr+=char
            else:
                break
        return substr