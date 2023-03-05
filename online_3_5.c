#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head) {
    //自己写的错误答案， 自己思路出现了问题，总是拿数组的相关思路带入思考
    // if(!head)return 0;
    // struct ListNode* left, *right;
    // left =right = head;
    // while(right->next != NULL)
    // {
    //     right = right->next;
    // }
    // while(left->next != right && left->next->next != right)
    // {
    //     int temp = right->val;
    //     right->val = left->val;
    //     left->val = temp;
    // }
    // return head;

    //第一种
    // if(head == NULL)
    // {
    //     return NULL;
    // }
    // struct ListNode* n1, *n2, *next;
    // n1 = NULL;
    // n2 = head;
    // next = head->next;
    // while(n2)
    // {
    //     n2->next = n1;
    //     n1 = n2;
    //     n2 = next;
    //     if(next)
    //         next = next->next;
    // }
    // return n1;


    //第二种
    if (head == NULL) return NULL;
    struct ListNode* cur, * next, * newcode;
    cur = head;
    next = head->next;
    newcode = NULL;
    while (cur)
    {
        cur->next = newcode;
        newcode = cur;
        cur = next;
        if (next)
            next = next->next;
    }
    return newcode;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    //自己写的， 用的是OJ链表的插入，会很烦， 而且没有写成功。应该用新列表，或则想想能不能用头插或者尾插， 尽量不要插入
    // if(!list1)
    // {
    //     return list2;
    // }
    // else if(!list2)
    // {
    //     return list1;
    // }
    // struct ListNode* head = list1;
    // if(list1->val > list2->val)
    // {
    //     head = list2;
    //     list2 = list2->next;
    //     head->next = list1;

    // }
    // while(list1 && list2)
    // {
    //     if(list1->val <= list2->val)
    //     {
    //         list1 = list1->next;
    //     }
    //     else
    //     {
    //         struct ListNode* temp = list1->next;
    //         list1->next = list2;
    //         lis2 = list2->next;
    //         list1->next->next = temp;
    //     }
    // }

    if (!list1) return list2;
    if (!list2) return list1;
    struct ListNode* newcode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newcode->next = NULL;
    struct ListNode* tail = newcode;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
    }
    if (list1)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }
    tail = newcode->next;
    free(newcode);
    newcode = NULL;
    return tail;
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