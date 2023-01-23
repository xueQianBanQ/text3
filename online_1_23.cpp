#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//int main()
//{
//    //单个变量
//	/*int* a = new int(8);
//	cout << *a << endl;
//	delete a;*/
//
//	//一维数组
//	/*int* a = new int[10];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(a + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		cout << a[i] << endl;
//	}*/
//
//	//二维数组
//	int** arr = new int* [10];
//	int i = 0;
//	int j = 0;
//	int z = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(arr + i) = new int[5];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			arr[i][j] = z;
//			z++;
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		delete[] arr[i];
//	}
//	delete[] arr;
//	return 0;
//}



//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person 默认函数的调用" << endl;
//	}
//	Person(int age, int height)
//	{
//		m_Age = age;
//		m_Height = new int(height);
//		cout << "person 有参构造函数的调用" << endl;
//	}
//	//默认地使用深拷贝是会错误的， （如果使用在堆区开辟一个新的空间时）
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		//m_Height = p.m_Height;//编译器默认的的就是这行代码 
//		//深拷贝
//		m_Height = new int(*p.m_Height);
//	}
//	~Person()
//	{
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;
//		}
//		cout << "Person 析构函数的调用" << endl;
//	}
//	int m_Age;
//	int* m_Height;
//};
//int main()
//{
//	Person p1(20, 180);
//	cout << p1.m_Age << " " << *p1.m_Height << endl;
//	Person p2(p1);
//	cout << p2.m_Age << " " << *p2.m_Height << endl;
//	return 0;
//}


////////////////////////////////////初始化
#include <iostream>
using namespace std;
class Person
{
public:
	Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
	{

	}
	int m_A;
	int m_B;
	int m_C;
};
int main()
{
	Person p(10, 20, 30);
	cout << p.m_A << endl;
	cout << p.m_B << endl;
	cout << p.m_C << endl;
	return 0;
}