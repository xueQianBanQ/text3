#define _CRT_SECURE_NO_WARNINGS 1

//
////利用多态实现计算机
//// 
////
//
//#include <iostream>
//using namespace std;
//class AbstractCalculator
//{
//public:
//	virtual int GetResult() = 0; // 纯虚函数
//	int m_Num1;
//	int m_Num2;
//};
//class AddCalculator : public AbstractCalculator
//{
//public:
//	int GetResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//class SubCalculator : public AbstractCalculator
//{
//public:
//	int GetResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//class MulCalcutor : public AbstractCalculator
//{
//public:
//	int GetResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//class DivCalculator : public AbstractCalculator
//{
//public:
//	int GetResult()
//	{
//		return m_Num1 / m_Num2;
//	}
//};
//int main()
//{
//	//多态实现抽象计算器类
//	// 多态优点： 代码组织结构清晰， 刻度性强， 利于前期和后期的扩展以及维护
//	//
//	AbstractCalculator* abc = new DivCalculator;
//	abc->m_Num1 = 5;
//	abc->m_Num2 = 2;
//	cout << abc->GetResult() << endl;
//	return 0;
//}
//


//#include <iostream>
//using namespace std;
//class AbstractDrink
//{
//public:
//	virtual void Boil() = 0;
//	virtual void Brew() = 0;
//	virtual void PourInCup() = 0;
//	virtual void PutSomething() = 0;
//	void MakeDrink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//class Coffee:public AbstractDrink
//{
//public:
//	virtual void Boil()
//	{
//		cout << "煮沸矿泉水" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "冲咖啡" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	virtual void PutSomething()
//	{
//		cout << "加入牛奶和糖" << endl;
//	}
//};
//
//class Tea : public AbstractDrink
//{
//public:
//	virtual void Boil()
//	{
//		cout << "煮沸水" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "冲茶叶" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	virtual void PutSomething()
//	{
//		cout << "加入枸杞" << endl;
//	}
//};
//
//void DoWork(AbstractDrink* drink)
//{
//	drink->MakeDrink();
//	delete drink;
//}
//int main()
//{
//	DoWork(new Coffee);
//	cout << "--------------------" << endl;
//	DoWork(new Tea);
//	return 0;
//}



//#include <iostream>
//#include <string>
//using namespace std;
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造函数" << endl;
//	}
//	virtual void Speak() = 0;
//	//父类指针指向子类时， 无法执行子类的析构函数
//	//所以在前面加一下virtual 
//	/*virtual ~Animal()
//	{
//		cout << "Animal析构函数" << endl;
//	}*/
//	//或者使用纯虚析构
//	virtual ~Animal() = 0;
//};
//Animal::~Animal()//需要声明 也需要实现
//{
//	cout << "Animal 的 纯虚析构" << endl;
//}
//class Cat : public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat构造函数" << endl;
//		m_Name = new string (name);
//	}
//	virtual void Speak()
//	{
//		cout << *m_Name << "小猫在讲话" << endl;
//	}
//
//	virtual ~Cat()
//	{
//		cout << "Cat析构函数" << endl;
//		if (m_Name != NULL)
//		{
//			delete m_Name;
//			m_Name = NULL;
//		}
//	}
//	string* m_Name;
//};
//int main()
//{
//	Animal* animal = new Cat("Tom");//父类指针指向子类时， 无法执行子类的析构函数
//	animal->Speak();
//	delete animal;
//	animal = NULL;
//	return 0;
//}
//


#include <iostream>
using namespace std;
class CPU
{
public:
	virtual void calculator() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void Work()
	{
		m_cpu->calculator();
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
class IntelCPU :public CPU
{
public:
	virtual void calculator()
	{
		cout << "Inter的CPU开始计算了" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Inter的显卡开始显示了" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Inter的内存开始存储了" << endl;
	}
};
int main()
{
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelvc = new IntelVideoCard;
	Memory* intelmem = new IntelMemory;
	Computer* computer = new Computer(intelCPU, intelvc, intelmem);
	computer->Work();
	delete computer; computer = NULL;
	return 0;
}



