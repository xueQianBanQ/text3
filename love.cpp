#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <time.h>       /* ����ʱ��ؼ��ϸ�ͷ�ļ� */
using namespace std;
// �Զ����һ����ʱ����delay()
void delay(double seconds) //  ����Ϊ˫���ȸ����͡�������������޸ĵ������Ǹ�����������һ�¡�
{
	double start = clock();
	double lay = (double)seconds * CLOCKS_PER_SEC;
	while ((clock() - start) < lay);
}

int main()
{
	float x, y, a;
	for (y = 1.5; y > -1.5; y -= 0.1)
	{
		for (x = -1.5; x < 1.5; x += 0.05)
		{
			a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
		}
		system("color 0c");
		putchar('\n');
		delay(0.3);
	}
	return 0;
}

