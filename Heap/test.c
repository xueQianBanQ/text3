#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

int main()
{
	/*Heap hp;
	HPInit(&hp);
	HPPush(&hp, 12);
	HPPush(&hp, 10);
	HPPush(&hp, 15);
	HPPush(&hp, 19);
	HPPush(&hp, 3);
	HPPush(&hp, 4);
	HPPush(&hp, 1);

	int i = hp.size;
	while(--i >= 0)
	{
		HPDataType a = HpTop(&hp);
		printf("%d ", a);
		HPPop(&hp);
	}
	printf("\n");
	HPDestory(&hp);*/
	

	int a[8] = {1, 3, 12, 18, 2, 1, 9, 20};
	//升序建大堆，降序建小队
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		AdjustUp(a, i);
	}
	for (i = 1; i < 8; i++)
	{
		Swap(&a[0], &a[8 - i]);
		AdjustDown(a, 8 - i);
	}

}