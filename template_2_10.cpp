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
////第一种
//void Show1(Person<string, int>& P)/////////////一般用这个
//{
//	P.ShowPerson();
//}
////第二种
//template <typename T1, typename T2>
//void Show2(Person<T1, T2>& P)
//{
//	P.ShowPerson();
//	cout << "T1 = " << typeid(T1).name() << endl;
//	cout << "T2 = " << typeid(T2).name() << endl;
//
//}
////第三种
//template <typename T>
//void Show3(T& P)
//{
//	P.ShowPerson();
//}
//int main()
//{
//	Person<string, int>P("沈焱", 18);
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
//class Son1 : public Base<int>//////如果父类是类模板，那么子类要指出类模板
//{
//	;
//};///////////////////////////////////除非子类也是类模板，可以灵活
//
//
//template <class T1, class T2>
//class Son2 : public Base<T1>
//{
//public:
//	T2 obj1;
//};



///////////////////////////////////类外实现类模板
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
////类外构造函数
//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//
////类外成员函数
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
	//类内实现全局函数
	friend void ShowPerson1(Person <T1, T2>& P)
	{
		cout << "name:>" << P.m_Name << endl;
		cout << "age:>" << P.m_Age << endl;
	}
	//全局函数类外实现
	//加空模板参数列表
	//如果全局函数 是类外实现， 需要让编译器提前知道这个函数的存在
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
	Person<string, int> P("沈焱", 18);
	ShowPerson1(P);
	ShowPerson2(P);
	return 0;
}