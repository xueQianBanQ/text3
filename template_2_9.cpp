#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//template <typename T>
//void MySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//
//	//利用函数模板交换
//	//1.自动类型交换
//	// 	MySwap(a, b);
//	//2.显示指定类型
//	MySwap<int>(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template <typename T>
//void MySort(T* Array, int sz)
//{
//	const int num = sz / sizeof(T);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num - 1; i++)//冒泡排序
//	{
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (Array[j] < Array[j + 1])
//			{
//				T temp = Array[j];
//				Array[j] = Array[j + 1];
//				Array[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	/*int Array[5] = { 0, 1, 2, 3 ,4 };
//	int i = 0;
//	MySort(Array, sizeof(Array));
//	for (i = 0; i < 5; i++)
//	{
//		cout << Array[i] << " ";
//	}
//	cout << endl;*/
//	char Array[6] = "abcde";
//	int i = 0;
//	MySort(Array, sizeof(Array));
//	for (i = 0; i < 5; i++)
//	{
//		cout << Array[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}






//网上学习的是普通函数可以隐式类型转换
//模板函数 自动类型推导不可以隐式类型转换
//         显示指定类型是可以隐式类型转换


//#include <iostream>
//using namespace std;
//int Add_1(int a, int b)
//{
//	return a + b;
//}
//
//template <typename T>
//T Add_2(T a, T b)
//{              
//	return a + b;                             
//   
//}
//
//int main()
//{
//	int a = 10; 
//	const int b = 20;
//	const int c = 'c';
//	//普通函数  可以隐士类型转换
//	cout << Add_1(a, c) << endl;
//	cout << Add_2(a, c) << endl;
//	return 0;
//}


////普通函数与模板函数重名时，首先先调用模板函数
//// 可以通过空模板列表参数来实现调用模板函数
//// 模板函数可以发生重载
//// 如果函数模板可以产生更好的匹配，优先调用函数模板
//
//#include <iostream>
//using namespace std;
//void MyPrint(int a)
//{
//	cout << "普通函数" << endl;
//}
//template <typename T>
//void MyPrint(T a)
//{
//	cout << "模板函数" << endl;
//}
//template <typename T>
//void MyPrint(T a, T b)
//{
//	cout << "模板函数2" << endl;
//}
//int main()
//{
//	//普通函数与模板函数重名时，首先先调用模板函数
//	int a = 10;
//	MyPrint(a);
//	// 可以通过空模板列表参数来实现调用模板函数
//	MyPrint<>(a);
//	// 模板函数可以发生重载
//	MyPrint(a, 100);
//	// 如果函数模板可以产生更好的匹配，优先调用函数模板
//	MyPrint('c');
//	return 0;
//}



////、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、模板函数中使用结构体
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//	int m_Age;
//	string m_Name;
//};
//template <class T>
//bool MyCompare(T& a, T& b)
//{
//	if (a == b)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//template<> bool MyCompare(Person& P1, Person& P2)
//{
//	if (P1.m_Name == P2.m_Name && P1.m_Age == P2.m_Age)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//int main()
//{
//	Person P1("Tom", 18);
//	Person P2("Tom", 18);
//	bool ret = MyCompare(P1, P2);
//	cout << ret << endl;
//	return 0;
//}




///////////////////////////////////////////////////////////////类使用template
//#include <iostream>
//#include <string>
//using namespace std;
//template <class Nametype, class Agetype = int>
//class Person
//{
//public:
//	Person(Nametype name, Agetype age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	void ShowPerson()
//	{
//		cout << "name:>" << this->m_Name << endl;
//		cout << "age;>" << this->m_Age << endl;
//	}
//private:
//	Nametype m_Name;
//	Agetype m_Age;
//};
//int main()
//{
//	Person<string, int> P1("沈焱", 18);//只能用显示指定类型
//	P1.ShowPerson();
//	Person<string>P2("沈焱", 19);
//	P2.ShowPerson(); //类模板可以在模板参数中有默认参数值 
//	return 0;
//}




////////////////////////////////////////////////////类模板中成员函数的创建时机
#include <iostream>
using namespace std;
class Person1
{
public:
	void show1()
	{
		cout << "1" << endl;
	}
};

class Person2
{
public:
	void show2()
	{
		cout << 2 << endl;
	}
};
template <class T>
class MyClass
{
public:
	T obj;
	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用是生成的
	void func1()
	{
		obj.show1();
	}
	void func2()
	{
		obj.show2();
	}
};
int main()
{
	MyClass<Person1> m;
	m.func1();
	//m.func2();//error, 说明函数调用才会去创建成员函数
	return 0;
}