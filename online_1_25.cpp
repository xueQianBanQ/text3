#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <string>
//using namespace std;
////�������������Ϊ�����Ա������ʱ���ȹ���������ڹ�������������˳��
////������˳���෴
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
//		cout << "Phone����" << endl;
//	}
//	string n_name;
//
//};
//
//class Person
//{
//public:
//	//Phone m_Phone = pName  ��ʽת����
//	Person(string name, string pName) :m_Name(name), m_Phone(pName)
//	{
//		cout << "Person" << endl;
//	}
//	~Person()
//	{
//		cout << "Person����" << endl;
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
	//1.���ж��󶼹���ͬһ������
	//2.����׶ξͷ����ڴ�
	//3.���������������ʼ������
	static int m_A;

};
int Person::m_A = 100;
int main()
{
	//��̬��Ա����  ������ĳ�������ϣ� ���ж��󶼹���ͬһ������
	//��˾�̬��Ա�����ַ��ʷ�ʽ

	//1. ͨ��������з���
	Person P;
	cout << P.m_A << endl;
	//2. ͨ���������з���
	cout << Person::m_A << endl;
	return 0;
}