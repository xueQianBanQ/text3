//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int RemoveElement(int* a, int NumsSize, int val)
//{
//	int src = 0, dst = 0;
//	while (src < NumsSize)
//	{
//		if (a[src] != val)
//		{
//			a[dst++] = a[src++];
//		}
//		else
//		{
//			src++;
//		}
//	}
//	return dst;
//}
//int main()
//{
//	int a[] = { 1, 2, 3, 2, 5, 3, 8, 2 };
//	int ret = RemoveElement(a, 8, 2);
//	printf("%d\n", ret);
//	return 0;
//}



//#include <stdio.h>
//
//int removeDuplicates(int* nums, int numsSize)
//{
//	int dst = 1, scr = 1;
//	while (scr < numsSize)
//	{
//		if (nums[scr] == nums[scr - 1])
//		{
//			scr++;
//		}
//		else
//		{
//			nums[dst++] = nums[scr++];
//		}
//	}
//	return dst;
//}
//int main()
//{
//	int a[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//	int ret = removeDuplicates(a, 10);
//	printf("%d\n", ret);
//	return 0;
// }


#include <stdio.h>
void merge(int* num1, int num1Size, int m, int* num2,int n)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int dst = num1Size - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (num1[end1] <= num2[end2])
		{
			num1[dst--] = num2[end2--];
		}
		else
		{
			num1[dst--] = num1[end1--];
		}
	}
		while (end2 > 0)
		{
			num1[dst--] = num2[end2--];
		}
}
int main()
{
	int nums1[] = { 1, 2, 3, 0,0,0 };
	int nums2[] = { 2, 5, 6 };
	merge(nums1, 6, 3, nums2, 3);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");
}