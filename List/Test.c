#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void LTest1()
{
	ListNode* head = ListCreate(-1);
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);
	ListPopBack(head);
	ListPrint(head);
	ListPopBack(head);
	ListPrint(head);
	ListPopBack(head);
	ListPrint(head);
}

void LTest2()
{
	ListNode* head = ListCreate(-1);
	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListNode* Find = ListFind(head, 3);
	ListInsert(Find, 10);
	ListPrint(head);
	ListErase(Find);
	ListPrint(head);
	ListDestory(head);
}

int main()
{
	LTest2();
	return 0;
}