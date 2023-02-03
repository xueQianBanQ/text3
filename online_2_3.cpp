#define _CRT_SECURE_NO_WARNINGS 1


/////动态多态满足条件
///// 1、有继承关系
///// 2、子类重写父类的虚函数
/////
///// //动态多态使用
///// //父类的指针或者引用  指向子类对象
//#include <iostream>
//using namespace std;
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//class Cat:public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//class Dog:public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
////执行说话的的函数
//// 地址早绑定 在编译阶段确定函数地址
//// 如果想执行让猫说话， 那么这个函数地址就不能提前绑定，需要在运行阶段
////
////动态多态满足条件
//// 1.有继承关系
//// 2.子类重写父类的虚函数
////
//void DoSpeak(Animal& animal)
//{							
//	animal.speak();
//}
//int main()
//{
//	Cat cat;
//	DoSpeak(cat);
//	return 0;
//}



//利用多态实现计算机
// 
//

#include <iostream>
using namespace std;
class AbstractCalculator
{
public:
	virtual int GetResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
class AddCalculator : public AbstractCalculator
{
public:
	int GetResult()
	{
		return m_Num1 + m_Num2;
	}
};
class SubCalculator : public AbstractCalculator
{
public:
	int GetResult()
	{
		return m_Num1 - m_Num2;
	}
};
class MulCalcutor : public AbstractCalculator
{
public:
	int GetResult()
	{
		return m_Num1 * m_Num2;
	}
};
class DivCalculator : public AbstractCalculator
{
public:
	int GetResult()
	{
		return m_Num1 / m_Num2;
	}
};
int main()
{
	//多态实现抽象计算器类
	// 多态优点： 代码组织结构清晰， 刻度性强， 利于前期和后期的扩展以及维护
	//
	AbstractCalculator* abc = new DivCalculator;
	abc->m_Num1 = 5;
	abc->m_Num2 = 2;
	cout << abc->GetResult() << endl;
	return 0;
}

















