#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SLTest1()
{
	SLTNode* pList = NULL;
	SLTPushBack(&pList, 1);
	SLTPushBack(&pList, 2);
	SLTPushBack(&pList, 3);
	SLTPushBack(&pList, 4);
	SLTPrint(pList);
	SLTPopFront(&pList);
	SLTPrint(pList);
	SLTPopFront(&pList);
	SLTPrint(pList);
	SLTPopFront(&pList);
	SLTPrint(pList);
	SLTPopFront(&pList);
	SLTPrint(pList);
}
void SLTest2()
{
	SLTNode* pList = NULL;
	SLTPushFront(&pList, 1);
	SLTPushFront(&pList, 2);
	SLTPushFront(&pList, 3);
	SLTPushFront(&pList, 4);
	SLTPrint(pList);
	SLTPopBack(&pList);
	SLTPrint(pList);
	SLTPopBack(&pList);
	SLTPrint(pList);
	SLTPopBack(&pList);
	SLTPrint(pList);
	SLTPopBack(&pList);
	SLTPrint(pList);
}
void SLTest3()
{
	SLTNode* pList = NULL;
	SLTPushFront(&pList, 1);
	SLTPushFront(&pList, 2);
	SLTPushFront(&pList, 3);
	SLTPushFront(&pList, 4);
	SLTPrint(pList);
	SLTNode* pos = SListFind(&pList, 2);
	SListInsert(&pList, pos, 9);
	SLTPrint(pList);
}
void SLTest4()
{
	SLTNode* pList = NULL;
	SLTPushFront(&pList, 7);
	SLTPushFront(&pList, 7);
	SLTPushFront(&pList, 7);
	SLTPushFront(&pList, 7);
	SLTPrint(pList);
	pList = removeElements(pList, 7);
	SLTPrint(pList);





}
int main()
{
	SLTest4();
	return 0;
}