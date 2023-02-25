#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = 3, b = 5;
//	a = a + b; // 相当于创建第三个变量（a + b）  a = 8
//	b = a - b; // b = 3
//	a = a - b;// a = 5;
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{  
//	int a = 4, b = 6;// a = 0000 0000 0000 0100 
//	                 // b = 0000 0000 0000 0110
//	a = a ^ b;       // a = 0000 0000 0000 0010   a = 2;
//	b = a ^ b;       // b = 0000 0000 0000 0100   b = 4;
//	a = a ^ b;       // a = 0000 0000 0000 0110   a = 6;
//	printf("%d\n", a);
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//	int a = 10, b = 20;
//	int temp = a;
//	a = b;
//	b = temp;
//	return 0;
//}



//#include <stdio.h>
//#include <assert.h>
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	assert(a > 10);
//	printf("%d\n", a);
//	return 0;
//}




#include <stdio.h>
//寻找丢失的数 0 - n
//[0 , 1, 3]
int MissingNum(int* arr, int n)
{
	int i = 0;
	int val = 0;
	for (i = 0; i < n; i++)// 一共 n + 1 个， 少了一个 即 n 个，
	{
		val ^= arr[i];
	}
	for (i = 0; i <= n; i++)
	{
		val ^= i;
	}
	return val;
}
int main()
{
	int a[4] = {2, 3, 4, 0};
	int ret = MissingNum(a, 4);
	printf("%d\n", ret);
	return 0;
}


//
//#include <stdio.h>
//void func()
//{
//	int a = 0;//float 也可以    只要是同一个字节都可以
//	printf("%p\n", &a);
//}
//void func2()
//{
//	int b = 0;
//	printf("%p\n", &b);
//}
//int main()
//{
//	func();
//	func2();
//	return 0;
//}



//
//#include <stdio.h>
//void Reverse(int* arr, int begin, int end)
//{
//	while (begin < end)
//	{
//		int temp = arr[begin];
//		arr[begin] = arr[end];
//		arr[end] = temp;
//		begin++;
//		end--;
//	}
//}
//void Rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	Reverse(nums, 0, numsSize - k - 1);
//	Reverse(nums, numsSize - k, numsSize - 1);
//	Reverse(nums, 0, numsSize - 1);
//}
//int main()
//{
//	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
//	Rotate(nums, 7, 3);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%2d", nums[i]);
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//void Rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	int* temp = (int*)malloc(numsSize * sizeof(int));
//	拷贝后 k 个
//	memcpy(temp, nums + numsSize - k, k * sizeof(int));
//	memmove(temp + k, nums, sizeof(int) * (numsSize - k));
//	memmove(nums, temp, sizeof(int) * numsSize);
//	free(temp);
//	temp = NULL;
//}
//int main()
//{
//	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
//	Rotate(nums, 7, 3);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%2d", nums[i]);
//	}
//	return 0;
//}