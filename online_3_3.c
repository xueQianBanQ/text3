#define _CRT_SECURE_NO_WARNINGS 1
///////////////////////////////////////////����

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    if (head == NULL)return NULL;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}



/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    if (pListHead == NULL)return NULL;//��ֹ������б�
//    struct ListNode* fast, * slow;
//    fast = slow = pListHead;
//    while (k--)//ִ��k��
//    {
//        if (fast == NULL)return NULL;//��ֹk�Ĵ�������oj���������   
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}



//#include <stdio.h>
//
//struct temple
//{
//	char a;
//	int b;
//	double c;
//};
//int main()
//{
//	struct temple temp1;
//	printf("%d\n", sizeof(temp1));
//}



#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
  };
 

//struct ListNode* removeElements(struct ListNode* head, int val) {
//    //��һ�֣��Լ�д�ģ�
//    // struct ListNode* cur = head;
//    // while(cur)
//    // {
//    //     if(cur->next!=NULL&&cur->next->val == val)
//    //     {
//    //         struct ListNode* del = cur->next;
//    //         cur->next = del->next;
//    //         free(del);
//    //         del = NULL;
//    //     }
//    //     else
//    //     {
//    //          cur = cur->next;
//    //     }
//    // }
//    // cur = head;
//    // if(head != NULL && head->val == val)
//    // {
//    //     cur = head->next;
//    // }
//    // return cur;
//
//
//    //�ڶ��֣������ѵģ�  
//    struct ListNode* prev, * cur;
//    if (!head)
//    {
//        return NULL;
//    }
//    prev = head;
//    cur = prev->next;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            prev->next = cur->next;
//            free(cur);
//            cur = prev->next;
//        }
//        else
//        {
//            prev = prev->next;
//            cur = cur->next;
//        }
//    }
//    if (head && head->val == val)
//    {
//        struct ListNode* del = head;
//        head = head->next;
//        free(del);
//        del = NULL;
//    }
//    return head;
//}


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