#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* tailA, * tailB;
    tailA = headA;
    tailB = headB;
    int coutA = 1, coutB = 1;
    while (tailA)
    {
        tailA = tailA->next;
        coutA++;
    }
    while (tailB)
    {
        tailB = tailB->next;
        coutB++;
    }
    if (tailA != tailB)return NULL;
    int gap = abs(coutA - coutB);
    struct ListNode* longList = headA, * shortList = headB;
    if (coutA < coutB)
    {
        longList = headB;
        shortList = headA;
    }
    while (gap)
    {
        longList = longList->next;
        gap--;
    }
    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return shortList;
}


struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            //第一种
            struct ListNode* meet = fast;
            // struct ListNode* start = head;
            // while(meet != start)
            // {
            //     meet = meet->next;
            //     start = start->next;
            // }
            // return meet;


            //第二种
            struct ListNode* list1 = head;
            struct ListNode* list2 = meet->next;
            meet->next = NULL;
            //变换为焦点问题
            struct ListNode* pos = getIntersectionNode(list1, list2);
            return pos;
        }
    }
    return NULL;
}
int main()
{
    struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp7 = (struct ListNode*)malloc(sizeof(struct ListNode));

    temp1->val = 1;
    temp2->val = 2;
    temp3->val = 6;
    temp4->val = 3;
    temp5->val = 4;
    temp6->val = 5;
    temp7->val = 6;
    

    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5; 
    temp5->next = temp6;
    temp6->next = temp7;
    temp7->next = NULL;

    removeElements(temp1, 6);

    return 0;
}