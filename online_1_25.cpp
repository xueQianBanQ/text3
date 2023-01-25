#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <string>
//using namespace std;
////当其他类对象作为本类成员，构造时候先构造类对象，在构造自身，析构的顺序？
////析构的顺序相反
//class Phone
//{
//public:
//	Phone(string name)
//	{
//		cout << "Phone" << endl;
//		n_name = name;
//	}
//	~Phone()
//	{
//		cout << "Phone析构" << endl;
//	}
//	string n_name;
//
//};
//
//class Person
//{
//public:
//	//Phone m_Phone = pName  隐式转换法
//	Person(string name, string pName) :m_Name(name), m_Phone(pName)
//	{
//		cout << "Person" << endl;
//	}
//	~Person()
//	{
//		cout << "Person析构" << endl;
//	}
//	string m_Name;
//	Phone m_Phone;
//};
//int main()
//{
//	Person p1("shenyan", "iphone14 pro max");
//	cout << p1.m_Name << " " << p1.m_Phone.n_name << endl;
//	return 0;
//}


#include <iostream>
using namespace std;
class Person
{
public:
	//1.所有对象都共享同一份数据
	//2.编译阶段就分配内存
	//3.类内声明，类外初始化操作
	static int m_A;

};
int Person::m_A = 100;
int main()
{
	//静态成员变量  不属于某个对象上， 所有对象都共享同一份数据
	//因此静态成员有两种访问方式

	//1. 通过对象进行访问
	Person P;
	cout << P.m_A << endl;
	//2. 通过类名进行访问
	cout << Person::m_A << endl;
	return 0;
}