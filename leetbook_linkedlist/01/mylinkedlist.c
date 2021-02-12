#include <stdio.h>
#include <malloc.h>

typedef struct MyLinkedList_t{
    int val;
    struct MyLinkedList_t *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->next = NULL;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *ptr = obj;
    int cnt;
    for(cnt = 0; cnt <= index; ++cnt)
    {
        ptr = ptr->next;
        if(ptr == NULL)
        {
            return -1;
        }
    }
    return ptr->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *new = myLinkedListCreate();
    new->next = obj->next;
    new->val = val;
    obj->next = new;
    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *ptr = obj;
    MyLinkedList *next;
    while(NULL != (next = ptr->next))
    {
        ptr = next;
    }

    ptr->next = myLinkedListCreate();
    ptr->next->val = val;
    
    return;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *ptr = obj;
    MyLinkedList *next = ptr->next;
    int cnt;
    for(cnt = 0; cnt < index; ++cnt)
    {
        if(next == NULL)
        {
            return;
        }
        ptr = next;
        next = ptr->next;
    }

    ptr->next = myLinkedListCreate();
    ptr->next->next = next;
    ptr->next->val = val;

    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *ptr = obj;
    MyLinkedList *next = obj->next;
    int cnt;
    for(cnt = 0; cnt < index; ++cnt)
    {
        if(next == NULL)
        {
            return;
        }
        ptr = next;
        next = ptr->next;
    }
    if(next == NULL)
    {
        return;
    }
    ptr->next = next->next;
    free(next);
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *ptr = obj;
    MyLinkedList *next;
    while(ptr)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return;
}

void myLinkedListPrint(MyLinkedList* obj)
{
    MyLinkedList *ptr = obj->next;
    while(ptr)
    {
        printf(" -> %d", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

int main()
{
    MyLinkedList *obj = myLinkedListCreate();
    // myLinkedListAddAtHead(obj, 4);
    // myLinkedListGet(obj, 1);
    // myLinkedListAddAtHead(obj, 1);
    // myLinkedListAddAtHead(obj, 5);
    // myLinkedListDeleteAtIndex(obj, 3);
    // myLinkedListAddAtHead(obj, 7);
    // myLinkedListGet(obj, 3);
    // myLinkedListGet(obj, 3);
    // myLinkedListGet(obj, 3);
    // myLinkedListAddAtHead(obj, 1);
    // myLinkedListDeleteAtIndex(obj, 4);

    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);
    int a = myLinkedListGet(obj, 1);
    myLinkedListDeleteAtIndex(obj, 1);
    int b = myLinkedListGet(obj, 1);
    printf("%d %d\n", a, b);


    return 0;
}