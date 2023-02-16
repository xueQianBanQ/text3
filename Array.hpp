#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person
{
public:
	Person() {};//�����д�Ļ��� ���ǵ��вι������ͻ�����������ˣ� ��������new  ��Ҫ�õ�Ĭ�Ϲ��캯����������Щ�ն���
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
		//cout << "MyArray���вι��캯��" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray�Ĺ��캯��" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[arr.m_Capacity];
		//����ԭ��������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}


	//β�巨
	void Push_Back(const T& val)
	{
		//�ж������Ƿ���ڴ�С
		{
			if (this->m_Capacity == this->m_Size)
			{
				cout << "��������" << endl;
				return;
			}
			this->pAddress[m_Size++] = val;
			//this->m_Size++;
		}
	}
	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		//���ж�
		if (this->m_Size == 0)
		{
			cout << "����������û������" << endl;
			return;  
		}
		this->pAddress[this->m_Size - 1] = { 0 };
		this->m_Size--;
	}
	MyArray& operator= (const MyArray& arr)
	{
		//cout << "MyArray��operator=����" << endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[arr.m_Capacity];
		//����ԭ��������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return* this;
	}

	//ͨ���±귽ʽ���������е�Ԫ��
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int GetCapacity()
	{
		return this->m_Capacity;
	}

	//���������С
	int GetSize()
	{
		return this->m_Size;
	}

	~MyArray()
	{
		//cout << "MyArray���������캯��" << endl;
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
private:
	T* pAddress;//����
	int m_Capacity;//�������
	int m_Size;//��С
};