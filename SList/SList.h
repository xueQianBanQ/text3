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

//��ӡ
void SLTPrint(SLTNode* phead);
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);
//���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//pos֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* poss, SLTDataType x);
//posλ��ɾ��
void SListErase(SLTNode** pphead, SLTNode* pos);
//pos�������
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//posλ�ú���ɾ��
void SListEraseAfter(SLTNode* pos);
//������Ĵݻ�
void SListDestory(SLTNode* plist);