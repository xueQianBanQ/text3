#define _CRT_SECURE_NO_WARNINGS 1


///////////////////////////////////////////时间复杂度///////////////////////
//#include <iostream>
//using namespace std; 

//算法的时间复杂度:0（n）
//真实时间复杂度:0(n + 3)
//int main()
//{
//	int n, ans = 0;
//	cout << "请输入n的值" << endl;
//	cin >> n;
//	for (int i = 0; i <= n; i++)
//	{
//		ans++;
//	}
//	ans++;
//	ans++;
//	ans++;
//	cout << ans << endl << "你好";
//	return 0;
//}



//int main()
//{
//	//算法的时间复杂度: 0(n^2);
//	// 真实时间复杂度: 0(n^2 + n);
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
//	//冒泡排序
//	//算法的时间复杂度0(n^2)
//	//真实时间复杂度0（((n^2 - n) / 2 )+ 2n）
//	int a[101];
//	int n;
//	cin >> n;
//	//int* arr = new int[n];空间复杂度0（n）
//	// 空间复杂度的表现 -- 内存
//	// 空间复杂度的实质是 -- 额外产生的空间
//	// 时间和空间往往是相对的
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
//				//即 (n^2 - n) / 2;
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

/////////////////////串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s ;
//	//cin >> s;//遇到空格或则回车结束
//	getline(cin, s);//遇到回车结束
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
	//s1 = s2;//字符串拷贝
	//s1 += s2;//字符串拼接
    //cout << s1 << endl;
	//cout << (s1 == s2 ? 0 : (s1 > s2 ? 1 : -1));//字符串比较

	//string s1 = "hello";
	//string s2 = "elt";
	//在字符s1中查找是否存s2 --> s1.finf(s2);
	//如果有则返回在s1中首次出现的下标
	// 如果没有则返回 string::npos
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