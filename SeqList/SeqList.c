#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SLInite(SL* ps)
{
	assert(ps);
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * INITE_CAPACITY);
	if (ps->a == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	ps->size = 0;
	ps->capacity = INITE_CAPACITY;
}


void SLDestroy(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}


void SLPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//检查capacity是否满了
void SLCapacityCheck(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc error!");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

//尾插
void SLPushBack(SL* ps, SLDateType x)
{
	assert(ps);
	SLCapacityCheck(ps);
	/*ps->a[ps->size] = x;
	ps->size++;*/
	ps->a[ps->size++] = x;
}


//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	//暴力的
	assert(ps->size > 0);
	////温柔的
	//if (ps->size == 0)
	//	return;
	ps->size--;
}



//头插
void SLPushFront(SL* ps, SLDateType x)
{
	assert(ps);
	SLCapacityCheck(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}



//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	for (int begin = 1; begin < ps->size; begin++)
	{
		ps->a[begin - 1] = ps->a[begin];
	}
	ps->size--;
}



//中间插入
void SLInsert(SL* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCapacityCheck(ps);
	for (int end = ps->size - 1; end >= pos; end--)
	{
		ps->a[end + 1] = ps->a[end];
	}
	ps->a[pos] = x;
	ps->size++;
}
//中间删除
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);
	assert(pos >= 0 && pos < ps->size);
	for (int begin = pos; begin < ps->size - 1; begin++)
	{
		ps->a[begin] = ps->a[begin + 1];
	}
	ps->size--;
}