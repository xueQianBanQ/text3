#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SLTPrint(SLTNode* phead)
{
	//����Ҫ���ԣ� ��Ϊ����phead����ָ��գ�NULL��   ���ǣ��ǽṹ���ڴ�����Ĳ�������NULL,���൱�ڽṹ�岻�ܻ�գ������������Ϊ��
	SLTNode* cur = phead;//���ܸı�phead����Ҫһֱ�洢�ⵥ���Ŀ�ͷ��,����Ҫ��һ������
	//while (cur != NULL)//���ﲻ��д��tail->next != NULL; ��Ϊ������ǵĻ�����ô���һ��tail->next�ǿգ������һ��tail�Ͳ��ᱻ��ӡ��
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

//β��
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


//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}


//βɾ
void SLTPopBack(SLTNode** pphead)
{
	//������
	assert(*pphead != NULL);
	//�����
	if (*pphead == NULL)return;
	//���Զ����ţ���Ϊassert��release�汾���ǲ�����ʹ�õ�
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

//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	//������
	assert(*pphead != NULL);
	//�����
	if (*pphead == NULL)return;
	//���Զ����ţ���Ϊassert��release�汾���ǲ�����ʹ�õ�
	SLTNode* frist = *pphead;
	*pphead = (*pphead)->next;
	free(frist);
	frist = NULL;
}

//���������
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

//��pos֮ǰ����
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

//posλ��ɾ��
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


//pos�������
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos != NULL);
	SLTNode* newnode = BuyNode(x);
	SLTNode* temp = pos->next;
	pos->next = newnode;
	newnode->next = temp;
}

//posλ�ú���ɾ��
void SListEraseAfter(SLTNode* pos)
{
	assert(pos != NULL);
	assert(pos->next != NULL);
	SLTNode* temp = pos->next;
	pos->next = pos->next->next;
	free(temp);
	temp = NULL;
}
//������Ĵݻ�
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