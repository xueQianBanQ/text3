#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base - func()" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Base - func(int a)" << endl;
//	}
//	int m_A;
//};
//class Son : public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	void func()
//	{
//		cout << "Son - func()" << endl;
//	}
//	int m_A;
//};
//int main()
//{
//	Son s;
//	/*cout << " Son  m_A " << s.m_A << endl 
//	cout << " Base m_A " << s.Base::m_A << endl;*/
//	//s.func();
//	//s.Base::func();
//	////error//s.func(100);//�����������븸��ͬ���ĺ�����������������и����ͬ������ 
//	//s.Base:: func(100);
//	cout << Son::m_A << endl;// �Ǿ�̬��Ա���ñ������ض��������
//	return 0;
//}



//// ʵ�ʿ����в�����ʹ�ö�̳��﷨
//#include <iostream>
//using namespace std;
//class Base1
//{
//public:
//	Base1()
//	{
//		m_A = 1;
//	}
//	int m_A;
//};
//class Base2
//{
//public:
//	Base2()
//	{
//		m_B = 1;
//	}
//	int m_B;
//};
//class Son : public Base1, public Base2
//{
//public:
//	Son()
//	{
//		m_C = 3;
//		m_D = 4;
//	}
//	int m_C;
//	int m_D;
//};
//int main()
//{
//	Son s;
//	cout << "sizeof(s) = " << sizeof(s) << endl;
//	return 0;
//}



//
////////���μ̳�
//#include <iostream>
//using namespace std;
//class Animal
//{
//public:
//	int m_Age;
//};
//class Sheep :virtual public Animal
//{
//
//};
//class Tuo :virtual public Animal
//{
//
//};
//class SheepTuo : public Sheep, public Tuo
//{
//
//};
//int main()
//{
//	SheepTuo s;
//	s.Sheep::m_Age = 18;
//	s.Tuo::m_Age = 28;
//	return 0;
//}

