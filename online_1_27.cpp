#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_A;
//	int m_B;//非静态成员变量， 属于类的对象上
//	char A;//静态成员变量 不属于类对象上
//	static int B;//非静态成员函数 不属于类对象上
//	void func()// 静态成员函数 不属于类的对象上
//	{
//		;
//	}
//	static void func2()
//	{
//		;
//	}
//};
//
//int main()
//{
//	Person P;// 空的
//	cout << "size of P = " << sizeof(P) << endl; 
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int age)
//	{
//		//解决名称冲突
//		this->age = age;
//	}
//	Person& AgeAdd(Person& P)
//	{
//		this->age += P.age;
//		return *this;
//	}
//	int age;
//};
//int main()
//{
//	Person P1(10);
//	cout << P1.age << endl;
//	Person P2(15);
//	P2.AgeAdd(P1).AgeAdd(P1);
//	cout << P2.age << endl; 
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	//this指针的本质是  指针常量 指针的指向是不可以修改的
//	// consr Person * const this;
//	// 在成员函数后面加const ， 修饰的是this 的指向， 让指针指向的值也不可以被修改
//	//
//	void showPerson() const
//	{
//		//this->m_A = 100;
//		//this = NULL;//this指针不可以修改指针的指向
//	}
//	int m_A;
//};
//int main()
//{
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//class Building
//{
//	//ShowBilding全局函数 是 Building的好朋友 ，可以访问building中的私有成员
//	friend void ShowBuilding(Building* building);
//public:
//	Building()
//	{
//		SittingRoom = "客厅";
//		BedRoom = "卧室"; 
//	}
//public:
//	string SittingRoom;
//private:
//	string BedRoom;
//};
//void ShowBuilding(Building* building)
//{
//	cout << building->SittingRoom << endl;
//	cout << building->BedRoom << endl;
//}
//int main()
//{
//	Building P;
//	ShowBuilding(&P);
//	return 0;
//}



//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_A;
//	int m_B;
//	//1.
//	/*Person operator+ (Person& P)
//	{
//		Person temp;
//		temp.m_A = this->m_A + P.m_A;
//		temp.m_B = this->m_B + P.m_B;
//		return temp;
//	}*/
//	
//};
////2.
//Person operator+ (Person& P1, Person& P2)
//{
//	Person temp;
//	temp.m_A = P1.m_A + P2.m_A;
//	temp.m_B = P1.m_B + P2.m_B;
//	return temp;
//}
//int main()
//{
//	Person P1;
//	P1.m_A = 10;
//	P1.m_B = 10;
//	Person P2;
//	P2.m_A = 10;
//	P2.m_B = 10;
//	//1.
//	//Person P3 = P1.operator+(P2);
//	//可以简化为
//	//Person P3 = P1 + P2;
//	//2.
//	//Person P3 = operator+(P1,P2);
//	//简化为
//	Person P3 = P1 + P2;
//	cout << P3.m_A << endl;
//	cout << P3.m_B << endl;
//	return 0;
//}



#include <iostream>
using namespace std;
class Person
{
	friend ostream& operator<< (ostream& cout, Person& P);
public:
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
private:
	//void operator<< (Person&P) // 发现不需要另一个Person  如果是void operator<<(ostream & cout)  p << cout  不对
	int m_A;
	int m_B;
};
//所以只能使用全局变量
ostream& operator<< (ostream& cout, Person& P)
{
	cout << "m_A = " << P.m_A << endl << "m_B = " << P.m_B;
	return cout;
}
int main()
{
	Person P(10, 20);
	/*P.m_A = 10;
	P.m_B = 10;*/
	cout << P << endl;
	return 0;
}