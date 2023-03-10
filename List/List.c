#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"


// 创建返回链表的头结点.
ListNode* ListCreate(LTDataType x)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_data = x;
	head->_next = head;
	head->_prev = head;
	return head;
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
	/*struct ListNode* newnode = ListCreate(x);
	newnode->_prev = pHead->_prev;
	newnode->_next = pHead;
	pHead->_prev->_next = newnode;
	pHead->_prev = newnode;*/
}


// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);
	printf("<=>NULL<=>");
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_prev);
	/*ListNode* del = pHead->_prev;
	del->_prev->_next = pHead;
	pHead->_prev = del->_prev;
	free(del);
	del = NULL;*/
}



// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
	/*ListNode* newcode = ListCreate(x);  
	newcode->_next = pHead->_next;
	newcode->_prev = pHead;
	pHead->_next->_prev = newcode;
	pHead->_next = newcode;*/
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);
	ListErase(pHead->_next);

	/*ListNode* del = pHead->_next;
	pHead->_next = del->_next;
	del->_next->_prev = pHead;
	free(del);
	del = NULL;*/
}



// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* Find = pHead->_next;
	while (Find != pHead)
	{
		if (Find->_data == x)return Find;
		Find = Find->_next;
	}
	return NULL;
}


// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* insert = ListCreate(x);
	insert->_prev = pos->_prev;
	pos->_prev->_next = insert;
	insert->_next = pos;
	pos->_prev = insert;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
	pos = NULL;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* del = pHead->_next;
	ListNode* next = del->_next;
	while (del != pHead)
	{
		free(del);
		del = next;
		if(next) next = next->_next;
	}
}