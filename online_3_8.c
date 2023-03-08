#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
struct ListNode* middleNode(struct ListNode* head)
{
    if (!head)return NULL;
    struct ListNode* fast, * lower;
    fast = lower = head;
    while (fast && fast->next)
    {
        lower = lower->next;
        fast = fast->next->next;
    }
    return lower;
}
struct ListNode* reverseList(struct ListNode* head)
{
    if (!head)return NULL;
    struct ListNode* prev, * cur, * next;
    prev = NULL;
    cur = head;
    next = head->next;
    while (cur)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next) next = next->next;
    }
    return prev;
}
class PalindromeList {
public:
    bool chkPalindrome(ListNode* head) {
        struct ListNode* mid = middleNode(head);
        struct ListNode* rhead = reverseList(mid);
        while (head && rhead)
        {
            if (head->val != rhead->val) return false;
            head = head->next;
            rhead = rhead->next;
        }
        return true;

    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA, * tailB = headB;
    int coutA, coutB;
    coutA = coutB = 1;
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
    int gap = abs(coutB - coutA);
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
    return longList;

}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA, * tailB = headB;
    int coutA, coutB;
    coutA = coutB = 1;
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
    int gap = abs(coutB - coutA);
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
    return longList;

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