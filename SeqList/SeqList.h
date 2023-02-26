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


//��ʼ��
void SLInite(SL* ps);
//����ͷ�
void SLDestroy(SL* ps);
//���capacity�Ƿ�����
void SLCapacityCheck(SL* ps);
//β��
void SLPushBack(SL* ps, SLDateType x);
//βɾ
void SLPopBack(SL* ps);
//ͷ��
void SLPushFront(SL* ps, SLDateType x);
//ͷɾ
void SLPopFront(SL* ps);
//�м����
void SLInsert(SL* ps, int pos, SLDateType x);
//�м�ɾ��
void SLErase(SL* ps, int pos);