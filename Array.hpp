#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person
{
public:
	Person() {};//如果不写的话， 我们的有参构函数就会把他给覆盖了， 但下面有new  需要用到默认构造函数来创建这些空对象
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

template <class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		//cout << "MyArray的有参构造函数" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray的构造函数" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//拷贝原来的数据
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}


	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否等于大小
		{
			if (this->m_Capacity == this->m_Size)
			{
				cout << "容量已满" << endl;
				return;
			}
			this->pAddress[m_Size++] = val;
			//this->m_Size++;
		}
	}
	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		//先判断
		if (this->m_Size == 0)
		{
			cout << "此数组里面没有数据" << endl;
			return;  
		}
		this->pAddress[this->m_Size - 1] = { 0 };
		this->m_Size--;
	}
	MyArray& operator= (const MyArray& arr)
	{
		//cout << "MyArray的operator=函数" << endl;
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//拷贝原来的数据
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return* this;
	}

	//通过下标方式访问数组中的元素
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int GetCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int GetSize()
	{
		return this->m_Size;
	}

	~MyArray()
	{
		//cout << "MyArray的析构构造函数" << endl;
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
private:
	T* pAddress;//数组
	int m_Capacity;//最大容量
	int m_Size;//大小
};