#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SLTPrint(SLTNode* phead)
{
	//不需要断言， 因为这里phead可以指向空（NULL）   但是，是结构体内存数组的不可以是NULL,就相当于结构体不能会空，但是数组可以为空
	SLTNode* cur = phead;//不能改变phead（它要一直存储这单链的开头）,所以要找一个变量
	//while (cur != NULL)//这里不能写成tail->next != NULL; 因为，如果是的话，那么最后一个tail->next是空，但最后一个tail就不会被打印了
	while(cur)   
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}



SLTNode* BuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc error!");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	
}


//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}


//尾删
void SLTPopBack(SLTNode** pphead)
{
	//暴力的
	assert(*pphead != NULL);
	//温柔的
	if (*pphead == NULL)return;
	//可以都留着，因为assert在release版本下是不可以使用的
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

//头删
void SLTPopFront(SLTNode** pphead)
{
	//暴力的
	assert(*pphead != NULL);
	//温柔的
	if (*pphead == NULL)return;
	//可以都留着，因为assert在release版本下是不可以使用的
	SLTNode* frist = *pphead;
	*pphead = (*pphead)->next;
	free(frist);
	frist = NULL;
}

//单链表查找
SLTNode* SListFind(SLTNode** phead, SLTDataType x)
{
	SLTNode* cur = *phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(*pphead != NULL);
	assert(pos != NULL);
	SLTNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	SLTNode* newnode = BuyNode(x);
	cur->next = newnode;
	newnode->next = pos;
}

//pos位置删除
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead != NULL);
	assert(pos != NULL);
	SLTNode* cur = *pphead;
	while (cur->next == pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}


//pos后面插入
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos != NULL);
	SLTNode* newnode = BuyNode(x);
	SLTNode* temp = pos->next;
	pos->next = newnode;
	newnode->next = temp;
}

//pos位置后面删除
void SListEraseAfter(SLTNode* pos)
{
	assert(pos != NULL);
	assert(pos->next != NULL);
	SLTNode* temp = pos->next;
	pos->next = pos->next->next;
	free(temp);
	temp = NULL;
}
//单链表的摧毁
void SListDestory(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		SLTNode* temp = cur;
		free(cur);
		cur = NULL;
		temp = temp->next;
	}
}