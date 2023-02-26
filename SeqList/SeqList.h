#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define INITE_CAPACITY 4

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SL;

void SLPrint(SL* ps);


//初始化
void SLInite(SL* ps);
//最后释放
void SLDestroy(SL* ps);
//检查capacity是否满了
void SLCapacityCheck(SL* ps);
//尾插
void SLPushBack(SL* ps, SLDateType x);
//尾删
void SLPopBack(SL* ps);
//头插
void SLPushFront(SL* ps, SLDateType x);
//头删
void SLPopFront(SL* ps);
//中间插入
void SLInsert(SL* ps, int pos, SLDateType x);
//中间删除
void SLErase(SL* ps, int pos);