#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//#define PI 3.14
//class Circle
//{
//	//权限访问
//	//公共权限
//public:
//	//属性
//	//半径
//	int radius;
//	//行为
//	//获取圆的周长
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
//	//属性和行为共称成员
//	//属性  成员属性 成员变量 
//	//行为  成员函数 成员方法 
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
//		cout << "学生姓名:>" << Stu_name << endl;
//		cout << "学生学号:>" << Stu_id << endl;
//	}
//public:
//	string Stu_name;
//	string Stu_id;
//};
//int main()
//{
//	Stu s1;
//	s1.SetName("沈焱");
//	s1.SetId("2212110458");
//	s1.ShowStu();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//class Person
//{
//public://公共部分， 类内可以访问  类外可以访问
//	string Name;
//protected://保护部分， 类内可以访问 类外不可以访问        儿子可以访问
//	string Car; 
//private:// 私有部分，  类内可以访问 类外不可以访问         儿子不可以访问
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
//	//设置x
//	void SetX(int x)
//	{
//		m_X = x;
//	}
//	//设置y
//	void SetY(int y)
//	{
//		m_Y = y;
//	}
//	//获取x
//	int GetX(void)
//	{
//		return m_X;
//	}
//	//获取y
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
//	void SetR(int r)//设置半径
//	{
//		m_R = r;
//	}
//	void SetPoint(Point center)//设置圆心
//	{
//		m_Center = center;
//	}
//	//获取半径
//	int GetR(void)
//	{
//		return m_R;
//	}
//	//获取圆心
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
//		cout << "点在圆上" << endl;
//	}
//	else if (distance > radius)
//	{
//		cout << "点在圆外" << endl;
//	}
//	else
//	{
//		cout << "点在圆内" << endl;
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
//	//构造函数
//	//1. 没有返回值 不用写void
//	//2. 函数名与类名相同
//	//3. 可以有参数， 可以发生重载
//	//4. 创建对象的时候， 构造函数会自动调用，而且只调用一次
//	Person()
//	{
//		cout << "Person 构造函数的调用" << endl;
//    }
//	// 析构函数
//	// 1.没有返回值 不用写void
//	// 2. 函数名与类名相同 在前面加~
//	// 3.择构函数不可以有参数， 显然不可以发生重载
//	// 4.对象在销毁前， 会自动调用析构函数， 而且只会调用一次
//	~Person()
//	{
//		cout << "Person 析构函数的调用" << endl;
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
//	//构造函数
//	Person()
//	{
//		cout << "Person 无参构造函数的调用" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "Person 有参函数的调用" << endl;
//	}
//	Person(const Person& p)
//	{
//		age = p.age;
//		cout << "Person 拷贝构造函数的调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person 析构函数的调用" << endl;
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
	//构造函数
	/*Person()
	{
		cout << "Person 无参构造函数的调用" << endl;
	}*/
	Person(int a)
	{
		age = a;
		cout << "Person 有参函数的调用" << endl;
	}
	Person(const Person& p)
	{
		age = p.age;
		cout << "Person 拷贝构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person 析构函数的调用" << endl;
	}
private:
	int age;
};
int main()
{
	//Person p1;//错误，     因为我们写了有参构造函数，编译系统就不会提供默认构造函数了（无参构造函数）

	return 0;
}


