#define _CRT_SECURE_NO_WARNINGS 1


/////��̬��̬��������
///// 1���м̳й�ϵ
///// 2��������д������麯��
/////
///// //��̬��̬ʹ��
///// //�����ָ���������  ָ���������
//#include <iostream>
//using namespace std;
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//class Cat:public Animal
//{
//public:
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//class Dog:public Animal
//{
//public:
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
////ִ��˵���ĵĺ���
//// ��ַ��� �ڱ���׶�ȷ��������ַ
//// �����ִ����è˵���� ��ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶�
////
////��̬��̬��������
//// 1.�м̳й�ϵ
//// 2.������д������麯��
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



//���ö�̬ʵ�ּ����
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
	//��̬ʵ�ֳ����������
	// ��̬�ŵ㣺 ������֯�ṹ������ �̶���ǿ�� ����ǰ�ںͺ��ڵ���չ�Լ�ά��
	//
	AbstractCalculator* abc = new DivCalculator;
	abc->m_Num1 = 5;
	abc->m_Num2 = 2;
	cout << abc->GetResult() << endl;
	return 0;
}

















