#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//#define PI 3.14
//class Circle
//{
//	//Ȩ�޷���
//	//����Ȩ��
//public:
//	//����
//	//�뾶
//	int radius;
//	//��Ϊ
//	//��ȡԲ���ܳ�
//	double Circumference(void)
//	{
//		return radius * PI * 2;
//	}
//
//};
//int main()
//{
//	Circle c1;
//	c1.radius = 10;
//	cout << c1.Circumference() << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//class Stu
//{
//	//���Ժ���Ϊ���Ƴ�Ա
//	//����  ��Ա���� ��Ա���� 
//	//��Ϊ  ��Ա���� ��Ա���� 
//public:
//	void SetName(string name)
//	{
//		Stu_name = name;
//	}
//	void SetId(string id)
//	{
//		Stu_id = id;
//	}
//	void ShowStu(void)
//	{
//		cout << "ѧ������:>" << Stu_name << endl;
//		cout << "ѧ��ѧ��:>" << Stu_id << endl;
//	}
//public:
//	string Stu_name;
//	string Stu_id;
//};
//int main()
//{
//	Stu s1;
//	s1.SetName("����");
//	s1.SetId("2212110458");
//	s1.ShowStu();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//class Person
//{
//public://�������֣� ���ڿ��Է���  ������Է���
//	string Name;
//protected://�������֣� ���ڿ��Է��� ���ⲻ���Է���        ���ӿ��Է���
//	string Car; 
//private:// ˽�в��֣�  ���ڿ��Է��� ���ⲻ���Է���         ���Ӳ����Է���
//	int Password;
//};
//int main()
//{
//	
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Cube
//{
//public:
//	void SetCube(int a, int b, int c)
//	{
//		Length = a;
//		Width = b;
//		Height = c;
//	}
//	int VolumeCube(void)
//	{
//		return Length * Width * Height;
//	}
//	int circumference(void)
//	{
//		return (Length + Width + Height) * 4;
//	}
//private:
//	int Length;
//	int Width;
//	int Height;
//};
//int main()
//{
//	Cube c1;
//	c1.SetCube(1, 2, 3);
//	cout << c1.VolumeCube() << endl;
//	cout << c1.circumference() << endl;
//	return 0;
//}
//
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//#include <iostream>
//using namespace std;
//class Point
//{
//private:
//	int m_X;
//	int m_Y;
//public:
//	//����x
//	void SetX(int x)
//	{
//		m_X = x;
//	}
//	//����y
//	void SetY(int y)
//	{
//		m_Y = y;
//	}
//	//��ȡx
//	int GetX(void)
//	{
//		return m_X;
//	}
//	//��ȡy
//	int GetY(void)
//	{
//		return m_Y;
//	}
//};
//class Circle
//{
//private:
//	int m_R;
//	Point m_Center;
//public:
//	void SetR(int r)//���ð뾶
//	{
//		m_R = r;
//	}
//	void SetPoint(Point center)//����Բ��
//	{
//		m_Center = center;
//	}
//	//��ȡ�뾶
//	int GetR(void)
//	{
//		return m_R;
//	}
//	//��ȡԲ��
//	Point GetPoint(void)
//	{
//		return m_Center;
//	}
//};
//void IsInCircle(Circle& c, Point& p)
//{
//	int distance = (c.GetPoint().GetX() - p.GetX()) * (c.GetPoint().GetX() - p.GetX())
//		+ (c.GetPoint().GetY() - p.GetY()) * (c.GetPoint().GetY() - p.GetY());
//	int radius = c.GetR() * c.GetR();
//	if (distance == radius)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else if (distance > radius)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else
//	{
//		cout << "����Բ��" << endl;
//	}
//}
//int main()
//{
//	Circle c1;
//	Point center;
//	center.SetX(10);
//	center.SetY(0);
//	c1.SetPoint(center);
//	c1.SetR(10);
//	Point A;
//	A.SetX(10);
//	A.SetY(11);
//	IsInCircle(c1, A);
//	return 0;
//}



//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	//���캯��
//	//1. û�з���ֵ ����дvoid
//	//2. ��������������ͬ
//	//3. �����в����� ���Է�������
//	//4. ���������ʱ�� ���캯�����Զ����ã�����ֻ����һ��
//	Person()
//	{
//		cout << "Person ���캯���ĵ���" << endl;
//    }
//	// ��������
//	// 1.û�з���ֵ ����дvoid
//	// 2. ��������������ͬ ��ǰ���~
//	// 3.�񹹺����������в����� ��Ȼ�����Է�������
//	// 4.����������ǰ�� ���Զ��������������� ����ֻ�����һ��
//	~Person()
//	{
//		cout << "Person ���������ĵ���" << endl;
//	}
//};
//int main()
//{
//	Person a;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int F(int x)
//{
//	return x * x;
//}
//int main()
//{
//	cout << F(2) << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	//���캯��
//	Person()
//	{
//		cout << "Person �޲ι��캯���ĵ���" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "Person �вκ����ĵ���" << endl;
//	}
//	Person(const Person& p)
//	{
//		age = p.age;
//		cout << "Person �������캯���ĵ���" << endl;
//	}
//	~Person()
//	{
//		cout << "Person ���������ĵ���" << endl;
//	}
//private:
//	int age;
//};
//int main()
//{
//	Person p1;
//	Person p2(10);
//	Person p3(p2);
//	return 0;
//}
//

#include <iostream>
using namespace std;
class Person
{
public:
	//���캯��
	/*Person()
	{
		cout << "Person �޲ι��캯���ĵ���" << endl;
	}*/
	Person(int a)
	{
		age = a;
		cout << "Person �вκ����ĵ���" << endl;
	}
	Person(const Person& p)
	{
		age = p.age;
		cout << "Person �������캯���ĵ���" << endl;
	}
	~Person()
	{
		cout << "Person ���������ĵ���" << endl;
	}
private:
	int age;
};
int main()
{
	//Person p1;//����     ��Ϊ����д���вι��캯��������ϵͳ�Ͳ����ṩĬ�Ϲ��캯���ˣ��޲ι��캯����

	return 0;
}


