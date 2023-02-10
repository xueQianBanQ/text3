#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//template <class Nametype, class Agetype>
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
////��һ��
//void Show1(Person<string, int>& P)/////////////һ�������
//{
//	P.ShowPerson();
//}
////�ڶ���
//template <typename T1, typename T2>
//void Show2(Person<T1, T2>& P)
//{
//	P.ShowPerson();
//	cout << "T1 = " << typeid(T1).name() << endl;
//	cout << "T2 = " << typeid(T2).name() << endl;
//
//}
////������
//template <typename T>
//void Show3(T& P)
//{
//	P.ShowPerson();
//}
//int main()
//{
//	Person<string, int>P("����", 18);
//	Show1(P);
//	Show2(P);
//	Show3(P);
//}




//#include <iostream>
//using namespace std;
//
//template <class T>
//class Base
//{
//public:
//	T obj;
//};
//
//class Son1 : public Base<int>//////�����������ģ�壬��ô����Ҫָ����ģ��
//{
//	;
//};///////////////////////////////////��������Ҳ����ģ�壬�������
//
//
//template <class T1, class T2>
//class Son2 : public Base<T1>
//{
//public:
//	T2 obj1;
//};



///////////////////////////////////����ʵ����ģ��
//#include <iostream>
//#include <string>
//using namespace std;
//template <class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	/*{
//		this->m_Name = name;
//		this->m_Age = age;
//	}*/
//	void ShowPerson();
//	/*{
//		cout << "name:>" << this->m_Name << endl;
//		cout << "age;>" << this->m_Age << endl;
//	}*/
//	T1 m_Name;
//	T2 m_Age;
//};
//
//
////���⹹�캯��
//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//
////�����Ա����
//template <class T1, class T2>
//void Person<T1, T2>:: ShowPerson()
//{
//	cout << "name:>" << this->m_Name << endl;
//	cout << "age;>" << this->m_Age << endl;
//}




#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person;

template <typename T1, typename T2>
void ShowPerson2(Person <T1, T2>& P)
{
	cout << "name:>" << P.m_Name << endl;
	cout << "age:>" << P.m_Age << endl;
}


template <class T1, class T2>
class Person
{
	//����ʵ��ȫ�ֺ���
	friend void ShowPerson1(Person <T1, T2>& P)
	{
		cout << "name:>" << P.m_Name << endl;
		cout << "age:>" << P.m_Age << endl;
	}
	//ȫ�ֺ�������ʵ��
	//�ӿ�ģ������б�
	//���ȫ�ֺ��� ������ʵ�֣� ��Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void ShowPerson2<>(Person <T1, T2>& P);
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	T1 m_Name;
	T2 m_Age;
};

int main()
{
	Person<string, int> P("����", 18);
	ShowPerson1(P);
	ShowPerson2(P);
	return 0;
}