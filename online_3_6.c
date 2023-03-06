#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        struct ListNode* lGuard, * gGuard, * ltail, * gtail;
        lGuard = ltail = (struct ListNode*)malloc(sizeof(struct ListNode));
        gGuard = gtail = (struct ListNode*)malloc(sizeof(struct ListNode));
        ltail->next = gtail->next = NULL;
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                ltail->next = cur;
                ltail = ltail->next;
            }
            else
            {
                gtail->next = cur;
                gtail = gtail->next;
            }
            cur = cur->next;
        }
        gtail->next = NULL;
        ltail->next = gGuard->next;
        pHead = lGuard->next;
        free(lGuard);
        free(gGuard);
        lGuard = NULL;
        gGuard = NULL;
        return pHead;
    }
};

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