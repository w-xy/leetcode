/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
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
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast, *slow, *lastfast, *lastslow;
    if(head == NULL)
    {
        return NULL;
    }
    slow = head;
    lastslow = head;
    fast = head->next;
    if(fast == NULL)
    {
        return NULL;
    }
    lastfast = head;
    while(true)
    {
        printf("fast %04X slow %04X\n", ((unsigned long long)fast)&0xFFFF, ((unsigned long long)slow)&0xFFFF);
        if(fast == slow)
        {
            if(lastslow == lastfast)
            {
                return lastfast;
            }
            else
            {
                return fast;
            }
        }
        fast = fast->next;
        if(fast == NULL)
        {
            return NULL;
        }
        lastfast = fast;
        fast = fast->next;
        if(fast == NULL)
        {
            return NULL;
        }
        lastslow = slow;
        slow = slow->next;
    }
}
// @lc code=end

typedef struct ListNode ListNode;

ListNode *newNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->next = NULL;
    node->val = val;
    return node;
}

ListNode *createList(int *arr, int len, ListNode **observer)
{
    ListNode *head = newNode(0);
    ListNode *last = head, *node;
    for(int i = 0; i < len; ++i)
    {
        node = newNode(arr[i]);
        last->next = node;
        last = node;
        observer[i] = node;
    }
    return head;
}

ListNode *createCycleList(int *arr, int len, int pos, ListNode **observer)
{
    ListNode *head = createList(arr, len, observer);
    observer[len-1]->next = observer[pos];
    return head;
}

void deleteList(ListNode *head)
{
    ListNode *node = head, *next;
    while(node)
    {
        next = node->next;
        free(node);
        node = next;
    }
    return;
}

#define ARR_SZ(arr) (sizeof(arr)/sizeof(arr[0]))
int main()
{
    int arr[] = {-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5};
    int pos = 24;
    ListNode *ob[ARR_SZ(arr)] = {NULL};

    ListNode *head = createCycleList(arr, ARR_SZ(arr), pos, ob);
    ListNode *cyclepos = detectCycle(head);
    
    ListNode *node = head;
    int cnt = -1;
    while(node)
    {
        if(node == cyclepos)
        {
            printf("Return: %d\n", cnt);
            break;
        }
        node = node->next;
        cnt++;
    }

    deleteList(head);

    return cnt;
}