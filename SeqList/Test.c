#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SLTest1()
{
	SL s;
	SLInite(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);
	SLPushBack(&s, 8);
	SLPrint(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);

	SLDestroy(&s);
}

void SLTest2()
{
	SL s;
	SLInite(&s);
	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPrint(&s);
	SLInsert(&s, 2, 10);
	SLPrint(&s);
	SLErase(&s, 1);
	SLPrint(&s);
	SLDestroy(&s);

}
int main()
{
	SLTest2();
	return 0;
}