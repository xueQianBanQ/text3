#define _CRT_SECURE_NO_WARNINGS 1

////////////////////////////////////////�ļ�����
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//int main()
//{
//	ofstream ofs;
//	ofs.open("test.txt", ios::out);
//	ofs << "I love u" << endl;
//	ofs << "shenyan" << endl;
//	ofs.close();
//	ifstream ifs;
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "���ļ�ʧ��" << endl;
//		return 0;
//	}
//	char buf[1024] = { 0 };
//	//��һ��
//	while (ifs >> buf)
//	{
//		cout << buf << endl;;//���������ո�ͻ��з�������
//	}
//	//�ڶ���     
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;//��������Ҫ���з��Ż���
//	//}
//	//������     ���˸о���õ�
//	/*string buff;
//	while(getline(ifs, buff))
//	{
//		cout << buff << endl;
//	}*/
//	//������
//	//char c;
//	//while ((c = ifs.get()) != EOF)// EOF   end of file
//	//{
//	//	cout << c ;
//	//}
//	ifs.close();
//	return 0;
//}


#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Person
{
public:
	//string name;
	char name[64];//д�������ʱ��Ҫ��string ���� �� �ᷢ��һЩ����
	int age;
};
int main()
{
	//����ͷ�ļ�
	// ����������
	ofstream ofs;
	// ���ļ�
	ofs.open("Person.txt", ios::out | ios::binary);
	// д���ļ�
	Person P = { "Shenyan", 18 };
	ofs.write((const char*)&P, sizeof(P));
	// �ر��ļ�
	ofs.close();
	//
	ifstream ifs;
	ifs.open("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return 0;
	}
	Person P2;
	ifs.read((char*)&P2, sizeof(Person));
	cout << P2.name << endl;
	cout << P2.age << endl;
	ifs.close();
	return 0;
}
