#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void Swap(HPDataType* x1, HPDataType* x2)
{
	HPDataType tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

void AdjustUp(HPDataType* a, int n)
{
	assert(a);
	assert(n >= 0);
	int child = n;
	int parent = (child - 1) / 2;
	//有些人会写成parent >= 0,虽然不会死循环，但还是严谨一些
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HPDataType* a, int n)
{
	n = n - 1;
	int parent = 0;
	int child = parent * 2 + 1;
	while (child <= n)
	{
		if (child < n && a[child] < a[child + 1])//child < n防止child + 1 的越界访问
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HPInit(Heap* php)
{
	assert(php);
	php->a = (HPDataType*)malloc(CAPACITY_INIT * sizeof(HPDataType));
	if (php->a == NULL)
	{
		perror("malloc error!");
		return;
	}
	php->size = 0;
	php->capacity = CAPACITY_INIT;
}

void HPDestory(Heap* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HPPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		Heap* tmp = (HPDataType*)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc error!");
			return;
		}
		php->capacity *= 2;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}
void HPPop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	//下翻
	AdjustDown(php->a, php->size);
}

HPDataType HpTop(Heap* php)
{
	assert(php);
	return php->a[0];
}
int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}
int HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}