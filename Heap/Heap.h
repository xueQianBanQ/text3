#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define CAPACITY_INIT 4

typedef int HPDataType;
//´ó¶Ñ´æ´¢
typedef struct Head
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HPInit(Heap* php);

void HPDestory(Heap* php);

void HPPush(Heap* php, HPDataType x);
void HPPop(Heap* php);

HPDataType HpTop(Heap* php);
int HeapSize(Heap* php);
int HeapEmpty(Heap* php);


void AdjustUp(HPDataType* a, int n);
void AdjustDown(HPDataType* a, int n);
void Swap(HPDataType* x1, HPDataType* x2);