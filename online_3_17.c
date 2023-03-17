#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//void func(char* s)
//{
//	int len = strlen(s);
//	printf("%d\n", len);
//}


//bool isValid(char* s) {
//    int len = strlen(s);
//    if (len % 2 != 0)
//    {
//        return false;
//    }
//    int i = 0;
//    for (i = 0; i < len; i += 2)
//    {
//        if (s[i] != s[i + 1])return false;
//    }
//    return true;
//}
//
//int main()
//{
//    char* s = "{}()[]";
//    bool jubge =  isValid(s);
//    printf("%d\n", jubge);
//	return 0;
//}

//int main()
//{
//    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
//    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
//    struct Node* temp3 = (struct Node*)malloc(sizeof(struct Node));
//    struct Node* temp4 = (struct Node*)malloc(sizeof(struct Node));
//    struct Node* temp5 = (struct Node*)malloc(sizeof(struct Node));
//    temp1->val = 7;
//    temp2->val = 13;
//    temp3->val = 11;
//    temp4->val = 10;
//    temp5->val = 1;
//
//    
//
//    temp1->next = temp2;
//    temp2->next = temp3;
//    temp3->next = temp4;
//    temp4->next = temp5; 
//    temp5->next = NULL;
//
//    temp1->random = NULL;
//    temp2->random = temp1;
//    temp3->random = temp5;
//    temp4->random = temp3;
//    temp5->random = temp1;
//    struct Node* head = copyRandomList(temp1);
//    return 0;
//}





#define INIT_CAPACITY 4
typedef char STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

bool STEmpty(ST* ps)
{
    assert(ps);
    return ps->top == -1;
}

void STInit(ST* ps)
{
    assert(ps);
    ps->a = (STDataType*)malloc(INIT_CAPACITY * sizeof(STDataType));
    if (ps == NULL)
    {
        perror("malloc error");
        return;
    }
    ps->capacity = INIT_CAPACITY;
    ps->top = -1;//是当前top顶栈元素
    //ps->top = 0 //是top顶栈元素的下一个
}
void STDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = -1;


}

void STPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top + 1 == ps->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity + (INIT_CAPACITY) * sizeof(STDataType));
        if (tmp == NULL)
        {
            perror("realloc error");
            return;
        }
        ps->a = tmp;
    }
    ps->a[ps->top + 1] = x;
    ps->top++;
}
void STPop(ST* ps)
{
    assert(ps);
    assert(!STEmpty(ps));
    ps->top--;
}
int STSize(ST* ps)
{
    assert(ps);
    return ps->top;
}

STDataType STTop(ST* ps)
{
    assert(ps);
    assert(!STEmpty(ps));
    return ps->a[ps->top];
}


bool isValid(char* s) {
    ST a;
    STInit(&a);
    int len = strlen(s);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            STPush(&a, s[i]);
        }
        else
        {
            if (STEmpty(&a))return false;
            char tmp = STTop(&a);
            if (s[i] == '}' && tmp != '{')return false;
            else if(s[i]==')' && tmp != '(')return false;
            else if(s[i]==']' && tmp != '[')return false;
            STPop(&a);
        }
    }
    if (!STEmpty(&a))return false;
    STDestory(&a);
    return true;
}
int main()
{
    char* s = "((";
    bool tmp = isValid(s);
    printf("%d\n", tmp);
    return 0;
}