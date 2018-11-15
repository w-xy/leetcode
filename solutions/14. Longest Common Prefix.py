'''
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:
All given inputs are in lowercase letters a-z.
'''
from functools import reduce

class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        zipped = zip(*strs)
        s = ''
        for list in zipped:
            ch = reduce(lambda x,y:x if x == y else 0, list)
            if ch == 0:
                break
            else:
                s += ch
        return s
