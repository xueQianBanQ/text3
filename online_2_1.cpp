#define _CRT_SECURE_NO_WARNINGS 1

/////////////////////////////////////�̳�
////�ô������ٴ�������
////�﷨�� class ���� �� �̳з�ʽ  ����
//// ���� Ҳ��Ϊ  ������
//// ���� Ҳ��Ϊ  ����
////
//#include <iostream>
//using namespace std;
//class BasePage
//{
//public:
//	void Header()
//	{
//		cout << "��ҳ�������Ρ���½��ע��...������ͷ����" << endl;
//	}
//	void Footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//	}
//	void Left()
//	{
//		cout << "Java��Python��C++��...(���������б�)" << endl;
//	}
//};
//class Java : public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//};
//class Python: public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//}; class CPP : public BasePage
//{
//public:
//	void content()
//	{
//		cout << "C++ѧ����Ƶ" << endl;
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
//		m_a = 100;//����
//		m_b = 100;//���� ���Ǳ���Ȩ��
//		//m_c = 100;
//	}
//};
//class B : protected Base
//{
//public:
//	void func()
//	{
//		m_a = 100;//��   �Ǳ���Ȩ��
//		m_b = 100;//���� ���Ǳ���Ȩ��
//		//m_c = 100;
//	}
//};
//class C : private Base
//{
//public:
//	void func()
//	{
//		m_a = 100;//��   ��˽��Ȩ��
//		m_b = 100;//��   ��˽��Ȩ��
//		//m_c = 100;
//	}
//
//};
//int main()
//{
//	A temp1;
//	temp1.m_a = 200;
//	/*temp1.m_b = 200;
//	temp1.m_b = 200;*///˽��Ȩ��
//	B temp2;
//	///////////////////////
//	/*temp2.m_a = 200;//����Ȩ��
//	temp2.m_b = 200;// ����Ȩ��
//	temp2.m_b = 200;*/
//	C temp3;
//	/////////////////////////ȫ�����˽��Ȩ��
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