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
//	//���ú���ģ�彻��
//	//1.�Զ����ͽ���
//	// 	MySwap(a, b);
//	//2.��ʾָ������
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
//	for (i = 0; i < num - 1; i++)//ð������
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






//����ѧϰ������ͨ����������ʽ����ת��
//ģ�庯�� �Զ������Ƶ���������ʽ����ת��
//         ��ʾָ�������ǿ�����ʽ����ת��


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
//	//��ͨ����  ������ʿ����ת��
//	cout << Add_1(a, c) << endl;
//	cout << Add_2(a, c) << endl;
//	return 0;
//}


////��ͨ������ģ�庯������ʱ�������ȵ���ģ�庯��
//// ����ͨ����ģ���б������ʵ�ֵ���ģ�庯��
//// ģ�庯�����Է�������
//// �������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
//
//#include <iostream>
//using namespace std;
//void MyPrint(int a)
//{
//	cout << "��ͨ����" << endl;
//}
//template <typename T>
//void MyPrint(T a)
//{
//	cout << "ģ�庯��" << endl;
//}
//template <typename T>
//void MyPrint(T a, T b)
//{
//	cout << "ģ�庯��2" << endl;
//}
//int main()
//{
//	//��ͨ������ģ�庯������ʱ�������ȵ���ģ�庯��
//	int a = 10;
//	MyPrint(a);
//	// ����ͨ����ģ���б������ʵ�ֵ���ģ�庯��
//	MyPrint<>(a);
//	// ģ�庯�����Է�������
//	MyPrint(a, 100);
//	// �������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
//	MyPrint('c');
//	return 0;
//}



////����������������������������������������������������������������������ģ�庯����ʹ�ýṹ��
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




///////////////////////////////////////////////////////////////��ʹ��template
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
//	Person<string, int> P1("����", 18);//ֻ������ʾָ������
//	P1.ShowPerson();
//	Person<string>P2("����", 19);
//	P2.ShowPerson(); //��ģ�������ģ���������Ĭ�ϲ���ֵ 
//	return 0;
//}




////////////////////////////////////////////////////��ģ���г�Ա�����Ĵ���ʱ��
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
	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ����������ɵ�
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
	//m.func2();//error, ˵���������òŻ�ȥ������Ա����
	return 0;
}