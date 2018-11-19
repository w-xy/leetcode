'''
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeLists(self, l1, l2, p):
        if l1 == None:
            p.next = l2
            return
        if l2 == None:
            p.next = l1
            return
        if l1.val < l2.val:
            p.next = l1
            self.mergeLists(l1.next, l2, p.next)
        else:
            p.next = l2
            self.mergeLists(l1, l2.next, p.next)
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(None)
        self.mergeLists(l1, l2, head)
        return head.next
