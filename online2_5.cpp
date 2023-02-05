#define _CRT_SECURE_NO_WARNINGS 1

////////////////////////////////////////文件操作
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
//		cout << "打开文件失败" << endl;
//		return 0;
//	}
//	char buf[1024] = { 0 };
//	//第一种
//	while (ifs >> buf)
//	{
//		cout << buf << endl;;//这种遇到空格和换行符都换行
//	}
//	//第二种     
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;//这种是需要换行符才换行
//	//}
//	//第三种     个人感觉最好的
//	/*string buff;
//	while(getline(ifs, buff))
//	{
//		cout << buff << endl;
//	}*/
//	//第四种
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
	char name[64];//写入二进制时不要用string 类型 ， 会发生一些错误
	int age;
};
int main()
{
	//包括头文件
	// 创建流对象
	ofstream ofs;
	// 打开文件
	ofs.open("Person.txt", ios::out | ios::binary);
	// 写入文件
	Person P = { "Shenyan", 18 };
	ofs.write((const char*)&P, sizeof(P));
	// 关闭文件
	ofs.close();
	//
	ifstream ifs;
	ifs.open("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
	Person P2;
	ifs.read((char*)&P2, sizeof(Person));
	cout << P2.name << endl;
	cout << P2.age << endl;
	ifs.close();
	return 0;
}
