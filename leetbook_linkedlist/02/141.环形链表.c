/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdio.h>


bool hasCycle(struct ListNode *head) {
    struct ListNode *fast, *slow, *next;
    if(head == NULL)
    {
        return false;
    }
    slow = head;
    fast = head->next;
    if(fast == NULL)
    {
        return false;
    }
    while(true)
    {
        if(fast == slow)
        {
            return true;
        }
        fast = fast->next;
        if(fast == NULL)
        {
            return false;
        }
        fast = fast->next;
        if(fast == NULL)
        {
            return false;
        }
        slow = slow->next;
    }
}
// @lc code=end

