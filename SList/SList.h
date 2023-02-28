#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;


SLTNode* BuyNode(SLTDataType x);

//打印
void SLTPrint(SLTNode* phead);
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);
//单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//pos之前插入
void SListInsert(SLTNode** pphead, SLTNode* poss, SLTDataType x);
//pos位置删除
void SListErase(SLTNode** pphead, SLTNode* pos);
//pos后面插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//pos位置后面删除
void SListEraseAfter(SLTNode* pos);
//单链表的摧毁
void SListDestory(SLTNode* plist);