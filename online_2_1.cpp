#define _CRT_SECURE_NO_WARNINGS 1

/////////////////////////////////////继承
////好处：减少代码冗余
////语法： class 子类 ： 继承方式  父类
//// 子类 也称为  派生类
//// 父类 也称为  基类
////
//#include <iostream>
//using namespace std;
//class BasePage
//{
//public:
//	void Header()
//	{
//		cout << "首页、公开课、登陆、注册...（公共头部）" << endl;
//	}
//	void Footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void Left()
//	{
//		cout << "Java、Python、C++、...(公开分类列表)" << endl;
//	}
//};
//class Java : public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//class Python: public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//}; class CPP : public BasePage
//{
//public:
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};
//int main()
//{
//	Python P;
//	P.Footer();
//	return 0;
//}



//
//#include <iostream>
//using namespace std;
//class Base
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//
//class A : public Base
//{
//public:
//	void func()
//	{
//		m_a = 100;//不变
//		m_b = 100;//不变 还是保护权限
//		//m_c = 100;
//	}
//};
//class B : protected Base
//{
//public:
//	void func()
//	{
//		m_a = 100;//变   是保护权限
//		m_b = 100;//不变 还是保护权限
//		//m_c = 100;
//	}
//};
//class C : private Base
//{
//public:
//	void func()
//	{
//		m_a = 100;//变   是私有权限
//		m_b = 100;//变   是私有权限
//		//m_c = 100;
//	}
//
//};
//int main()
//{
//	A temp1;
//	temp1.m_a = 200;
//	/*temp1.m_b = 200;
//	temp1.m_b = 200;*///私有权限
//	B temp2;
//	///////////////////////
//	/*temp2.m_a = 200;//保护权限
//	temp2.m_b = 200;// 保护权限
//	temp2.m_b = 200;*/
//	C temp3;
//	/////////////////////////全变成了私有权限
//	/*temp3.m_a = 200;
//	temp3.m_b = 200;
//	temp3.m_c = 200;*/
//	return 0;
//}

#include <iostream>
using namespace std;
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son : public Base
{
public:
	int m_D;
};
int main()
{
	cout << "sizeof(Son) = " << sizeof(Son) << endl;
	return 0;
}