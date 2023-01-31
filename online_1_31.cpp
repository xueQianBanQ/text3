#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, const MyInteger& P);
//public:
//	MyInteger()
//	{
//		m_Num = 0;
//	}
//	MyInteger& operator++()
//	{
//		++m_Num;
//		return* this;
//	}
//	MyInteger operator++(int)
//	{
//		static MyInteger temp = *this;
//		this->m_Num++;
//		return temp;
//	}
//private:
//	int m_Num;
//};
//ostream& operator<<(ostream& cout,const MyInteger& P)
//{
//	cout << P.m_Num;
//	return cout;
//}
//int main()
//{
//	MyInteger Num;
//	//cout << ++Num << endl;
//	//cout << (Num++)++ << endl;
//	cout << Num << endl;
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//class Student {
//	const int f;
//public:
//	Student(int a = 10) noexcept :f(a) {} //书上说只能用这种参数列表来对常数据成员初始化
//	void re();
//
//};
//
//void Student::re()
//{
//	cout << "f " << f;
//}
//
//int main()
//{
//	Student s;
//	s.re();
//	return 0;
//}



//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int Height)
//	{
//		m_Height = new int(Height);
//	}
//	~Person()
//	{
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;
//		}
//	}
//	Person& operator=(Person& P)
//	{
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;
//		}
//		this->m_Height = new int(*P.m_Height);
//		return *this;
//	}
//	int* m_Height;
//};
//int main()
//{
//	Person P1(18);
//	Person P2(20);
//	Person P3(30);
//	P3 = P2 = P1;
//	cout << *P1.m_Height << endl;
//	cout << *P2.m_Height << endl;
//	cout << *P3.m_Height << endl;
//	return 0;
//}



#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(Person P)
	{
		if (P.m_Age == m_Age && P.m_Name == m_Name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	string m_Name;
	int m_Age;
};
int main()
{
	Person P1("Tom", 18);
	Person P2("Tom", 18);
	if (P1 == P2)
	{
		cout << "都一个人" << endl;
	}
	return 0;
}