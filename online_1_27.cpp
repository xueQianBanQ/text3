#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_A;
//	int m_B;//�Ǿ�̬��Ա������ ������Ķ�����
//	char A;//��̬��Ա���� �������������
//	static int B;//�Ǿ�̬��Ա���� �������������
//	void func()// ��̬��Ա���� ��������Ķ�����
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
//	Person P;// �յ�
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
//		//������Ƴ�ͻ
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
//	//thisָ��ı�����  ָ�볣�� ָ���ָ���ǲ������޸ĵ�
//	// consr Person * const this;
//	// �ڳ�Ա���������const �� ���ε���this ��ָ�� ��ָ��ָ���ֵҲ�����Ա��޸�
//	//
//	void showPerson() const
//	{
//		//this->m_A = 100;
//		//this = NULL;//thisָ�벻�����޸�ָ���ָ��
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
//	//ShowBildingȫ�ֺ��� �� Building�ĺ����� �����Է���building�е�˽�г�Ա
//	friend void ShowBuilding(Building* building);
//public:
//	Building()
//	{
//		SittingRoom = "����";
//		BedRoom = "����"; 
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
//	//���Լ�Ϊ
//	//Person P3 = P1 + P2;
//	//2.
//	//Person P3 = operator+(P1,P2);
//	//��Ϊ
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
	//void operator<< (Person&P) // ���ֲ���Ҫ��һ��Person  �����void operator<<(ostream & cout)  p << cout  ����
	int m_A;
	int m_B;
};
//����ֻ��ʹ��ȫ�ֱ���
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