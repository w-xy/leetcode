'''
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
'''
class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == '':
            return 0
        head = 0
        tail = len(needle)
        while tail <= len(haystack):
            if needle == haystack[head:tail]:
                return head
            head += 1
            tail += 1
        return -1

    def issame(self, haystack, needle, head, tail):
        phaystack = head
        pneedle = 0
        while phaystack < tail:
            if needle[pneedle] != haystack[phaystack]:
                return False
            phaystack += 1
            pneedle += 1
        return True
    def strStrSelfCmp(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == '':
            return 0
        head = 0
        tail = len(needle)
        while tail <= len(haystack):
            if self.issame(haystack, needle, head, tail):
                return head
            head += 1
            tail += 1
        return -1

def issame(self, haystack, needle, head, tail):
    phaystack = head
    pneedle = 0
    while phaystack < tail:
        if needle[pneedle] != haystack[phaystack]:
            return head+1, tail+1
        phaystack += 1
        pneedle += 1
    return True
def strStrKMP(self, haystack, needle):
    """
    :type haystack: str
    :type needle: str
    :rtype: int
    """
    if needle == '':
        return 0
    head = 0
    tail = len(needle)
    while tail <= len(haystack):
        ret = self.issame(haystack, needle, head, tail)
        if ret == True:
            return head
        else:
            head,tail = ret
    return -1
