#define _CRT_SECURE_NO_WARNINGS 1


///////////////////////////////////////////ʱ�临�Ӷ�///////////////////////
//#include <iostream>
//using namespace std; 

//�㷨��ʱ�临�Ӷ�:0��n��
//��ʵʱ�临�Ӷ�:0(n + 3)
//int main()
//{
//	int n, ans = 0;
//	cout << "������n��ֵ" << endl;
//	cin >> n;
//	for (int i = 0; i <= n; i++)
//	{
//		ans++;
//	}
//	ans++;
//	ans++;
//	ans++;
//	cout << ans << endl << "���";
//	return 0;
//}



//int main()
//{
//	//�㷨��ʱ�临�Ӷ�: 0(n^2);
//	// ��ʵʱ�临�Ӷ�: 0(n^2 + n);
//	//
//	int n, ans = 0;
//	int i, j;
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			ans++;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}
//
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	//ð������
//	//�㷨��ʱ�临�Ӷ�0(n^2)
//	//��ʵʱ�临�Ӷ�0��((n^2 - n) / 2 )+ 2n��
//	int a[101];
//	int n;
//	cin >> n;
//	//int* arr = new int[n];�ռ临�Ӷ�0��n��
//	// �ռ临�Ӷȵı��� -- �ڴ�
//	// �ռ临�Ӷȵ�ʵ���� -- ��������Ŀռ�
//	// ʱ��Ϳռ���������Ե�
//	//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];//n
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				swap(a[j], a[j + 1]);//(n-1) + (n-2) + .......+ 1;
//				//�� (n^2 - n) / 2;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";//n
//	}
//	cout << endl;
//	//delete[]arr;
//	return 0;
//}
//

/////////////////////��
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s ;
//	//cin >> s;//�����ո����س�����
//	getline(cin, s);//�����س�����
//	cout << s << endl;
//	//int i = s.size();
//	int len = s.length();
//	//cout << i << endl << len << endl;
//	char A, B;
//	cin >> A >> B;
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == A) s[i] = B;
//	}
//	cout << s;
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
int main()
{
	/*string s1 = "hello";
	string s2 = "world";*/
	//s1 = s2;//�ַ�������
	//s1 += s2;//�ַ���ƴ��
    //cout << s1 << endl;
	//cout << (s1 == s2 ? 0 : (s1 > s2 ? 1 : -1));//�ַ����Ƚ�

	//string s1 = "hello";
	//string s2 = "elt";
	//���ַ�s1�в����Ƿ��s2 --> s1.finf(s2);
	//������򷵻���s1���״γ��ֵ��±�
	// ���û���򷵻� string::npos
	//
	/*cout << s1.find(s2) << endl;
	cout << string::npos << endl;*/

	//s1.find(s2, pos)
	string s1;
	string s2;
	int pos = 0;
	int ans = 0;
	getline(cin, s1);
	getline(cin, s2);
	int len2 = s2.length();
	while ((pos = s1.find(s2, pos)) != string::npos)
	{
		pos+=len2;
		ans++;
	}
	cout << ans;
	return 0;
}