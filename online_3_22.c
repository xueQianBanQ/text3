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


//
//#define INIT_CAPACITY 4
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST* ps);
//void STDestory(ST* ps);
//
//void STPush(ST* ps, STDataType x);
//void STPop(ST* ps);
//int STSize(ST* ps);
//bool STEmpty(ST* ps);
//STDataType STTop(ST* ps);
//
//
//
//void STInit(ST* ps)
//{
//	assert(ps);
//	ps->a = (STDataType*)malloc(INIT_CAPACITY * sizeof(STDataType));
//	if (ps == NULL)
//	{
//		perror("malloc error");
//		return;
//	}
//	ps->capacity = INIT_CAPACITY;
//	ps->top = -1;//是当前top顶栈元素
//	//ps->top = 0 //是top顶栈元素的下一个
//}
//void STDestory(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = 0;
//	ps->top = -1;
//
//
//}
//
//void STPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top + 1 == ps->capacity)
//	{
//		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity + (INIT_CAPACITY) * sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc error");
//			return;
//		}
//		ps->a = tmp;
//	}
//	ps->a[ps->top + 1] = x;
//	ps->top++;
//}
//void STPop(ST* ps)
//{
//	assert(ps);
//	assert(!STEmpty(ps));
//	ps->top--;
//}
//int STSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//bool STEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == -1;
//}
//STDataType STTop(ST* ps)
//{
//	assert(ps);
//	assert(!STEmpty(ps));
//	return ps->a[ps->top];
//}
//
//
//
//
//typedef struct {
//	ST STadd;
//	ST STsub;
//
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//	MyQueue* st = (MyQueue*)malloc(sizeof(MyQueue));
//	STInit(&st->STadd);
//	STInit(&st->STsub);
//	return st;
//
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//	int size = STSize(&obj->STsub);
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		STPush(&obj->STadd, obj->STsub.top);
//		STPop(&obj->STsub);
//	}
//	STPush(&obj->STadd, x);
//	for (i = 0; i < size; i++)
//	{
//		STPush(&obj->STsub, &obj->STadd.top);
//		STPop(&obj->STadd);
//	}
//}
//
//int myQueuePop(MyQueue* obj) {
//	assert(obj);
//	int a = STTop(&obj->STsub);
//	STPop(&obj->STsub);
//	return a;
//}
//
//int myQueuePeek(MyQueue* obj) {
//	return STTop(&obj->STsub);
//
//}
//bool myQueueEmpty(MyQueue* obj) {
//	return STEmpty(&obj->STsub);
//}
//
//void myQueueFree(MyQueue* obj) {
//	STDestory(&obj->STsub);
//}






#define INIT_CAPACITY 4
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* ps);
void STDestory(ST* ps);

void STPush(ST* ps, STDataType x);
void STPop(ST* ps);
int STSize(ST* ps);
bool STEmpty(ST* ps);
STDataType STTop(ST* ps);



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
	return ps->top + 1;
}
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == -1;
}
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	return ps->a[ps->top];
}




typedef struct {
	ST* STadd;
	ST* STsub;

} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* st = (MyQueue*)malloc(sizeof(MyQueue));
	st->STadd = (ST*)malloc(sizeof(ST));
	st->STsub = (ST*)malloc(sizeof(ST));
	STInit(st->STadd);
	STInit(st->STsub);
	return st;
}

void myQueuePush(MyQueue* obj, int x) {
	int size = STSize(obj->STsub);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		STPush(obj->STadd, obj->STsub->a[obj->STsub->top]);
		STPop(obj->STsub);
	}
	STPush(obj->STadd, x);
	for (i = 0; i < size + 1; i++)
	{
		STPush(obj->STsub, obj->STadd->a[obj->STadd->top]);
		STPop(obj->STadd);
	}
}

int myQueuePop(MyQueue* obj) {
	assert(obj);
	int a = STTop(obj->STsub);
	STPop(obj->STsub);
	return a;
}

int myQueuePeek(MyQueue* obj) {
	return STTop(obj->STsub);

}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(obj->STsub);
}

void myQueueFree(MyQueue* obj) {
	STDestory(obj->STsub);
}

int main()
{
	MyQueue* q = myQueueCreate();
	myQueuePush(q, 1);
	myQueuePush(q, 2);
	int a = myQueuePeek(q);
	printf("%d ", a);
	a = myQueuePop(q);
	printf("%d ", a);
	int b = myQueueEmpty(q);
	printf("\n%d\n", b);
	myQueueFree(q);
}