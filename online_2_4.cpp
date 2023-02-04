#define _CRT_SECURE_NO_WARNINGS 1

//
////���ö�̬ʵ�ּ����
//// 
////
//
//#include <iostream>
//using namespace std;
//class AbstractCalculator
//{
//public:
//	virtual int GetResult() = 0; // ���麯��
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
//	//��̬ʵ�ֳ����������
//	// ��̬�ŵ㣺 ������֯�ṹ������ �̶���ǿ�� ����ǰ�ںͺ��ڵ���չ�Լ�ά��
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
//		cout << "��п�Ȫˮ" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "�忧��" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//	virtual void PutSomething()
//	{
//		cout << "����ţ�̺���" << endl;
//	}
//};
//
//class Tea : public AbstractDrink
//{
//public:
//	virtual void Boil()
//	{
//		cout << "���ˮ" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "���Ҷ" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//	virtual void PutSomething()
//	{
//		cout << "�������" << endl;
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
//		cout << "Animal���캯��" << endl;
//	}
//	virtual void Speak() = 0;
//	//����ָ��ָ������ʱ�� �޷�ִ���������������
//	//������ǰ���һ��virtual 
//	/*virtual ~Animal()
//	{
//		cout << "Animal��������" << endl;
//	}*/
//	//����ʹ�ô�������
//	virtual ~Animal() = 0;
//};
//Animal::~Animal()//��Ҫ���� Ҳ��Ҫʵ��
//{
//	cout << "Animal �� ��������" << endl;
//}
//class Cat : public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat���캯��" << endl;
//		m_Name = new string (name);
//	}
//	virtual void Speak()
//	{
//		cout << *m_Name << "Сè�ڽ���" << endl;
//	}
//
//	virtual ~Cat()
//	{
//		cout << "Cat��������" << endl;
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
//	Animal* animal = new Cat("Tom");//����ָ��ָ������ʱ�� �޷�ִ���������������
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
		cout << "Inter��CPU��ʼ������" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Inter���Կ���ʼ��ʾ��" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Inter���ڴ濪ʼ�洢��" << endl;
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



