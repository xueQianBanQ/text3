#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <tgmath.h>
using namespace std;
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap /= 2;
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
//void Sort(int* a, int left, int right)//排序最后一个
//{
//	for (int i = right - 1; i >= left; --i)
//	{
//		if (a[i] > a[i + 1])swap(a[i], a[i + 1]);
//		else break;
//	}
//}
//int main()
//{
//	int _case;
//	cin >> _case;
//	while (_case--)
//	{
//		int n, m;
//		cin >> n >> m;
//		int* a = new int[n] {0};
//		int* b = new int[m] {0};
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> a[i];
//		}
//		ShellSort(a, n);
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> b[i];
//		}
//		ShellSort(b, m);
//		int left_a = 0, right_a = n - 1, left_b = 0, right_b = m - 1;
//		while (left_a <= right_a && left_b <= right_b)
//		{
//			if (a[right_a] < b[right_b])
//			{
//				int i = 0;
//				for (i = left_a; i <= right_a; ++i)
//				{
//					if (a[i] >= b[left_b])
//					{
//						a[i] -= b[left_b];
//						++left_b;
//						break;
//					}
//				}
//				if (i > right_a)right_a = -1;
//				else
//				{
//					Sort(a, left_a, i);
//					if (a[left_a] == 0)++left_a;
//				}
//			}
//			else
//			{
//				a[right_a] -= b[right_b];
//				--right_b;
//				if (a[right_a] == 0)--right_a;
//				Sort(a, left_a, right_a);
//			}
//			if (left_a > right_a || left_b > right_b)break;
//			if (a[right_a] > b[right_b])
//			{
//				int i = 0;
//				for (i = left_b; i <= right_b; ++i)
//				{
//					if (b[i] >= a[left_a])
//					{
//						b[i] -= a[left_a];
//						++right_a;
//						break;
//					}
//				}
//				if (i > right_b)right_b = -1;
//				else
//				{
//					Sort(b, left_b, i);
//					if (a[left_b] == 0)++left_b;
//				}
//			}
//			else
//			{
//				b[right_b] -= a[right_a];
//				--right_a;
//				if (b[right_b] == 0)--right_b;
//				Sort(b, left_b, right_b);
//			}
//		}
//		if (left_a <= right_a)cout << "Tsondu" << endl;
//		else if (left_b <= right_b) cout << "Tenzing" << endl;
//		else cout << "Draw" << endl;
//		delete[]a;
//		delete[]b;
//	}
//	return 0;
//}

//int main()
//{
//	int _case;
//	cin >> _case;
//	while (_case--)
//	{
//		int n;
//		long long x;
//		cin >> n >> x;
//		int** a = new int*[3];
//		for (int i = 0; i < 3; ++i)
//		{
//			a[i] = new int[n];
//		}
//		for (int i = 0; i < 3; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				cin >> a[i][j];
//			}
//		}
//		long long target = 0;
//		for (int i = 0; i < 3; ++i)
//		{
//			if (target == x) break;
//			for (int j = 0; j < n; ++j)
//			{
//				int tmp = a[i][j];
//				if ((tmp | x) == x)
//				{
//					target |= tmp;
//				}
//				else break;
//				if (target == x) break;
//			}
//		}
//		if (target == x)cout << "Yes" << endl;
//		else cout << "No" << endl;
//		for (int i = 0; i < 3; ++i)
//		{
//			delete[]a[i];
//		}
//		delete[]a;
//	}
//	return 0;
//}
//

//int main()
//{
//	cin.tie(0);
//	cout.tie(0);
//	ios::sync_with_stdio(0);
//	int _case;
//	cin >> _case;
//	while (_case--)
//	{
//		int len;
//		cin >> len;
//		int* a = new int[len];
//		for (int i = 0; i < len; ++i)
//		{
//			cin >> a[i];
//		}
//		int count_right = 0;
//		for (int i = 0; i < len; ++i)
//		{
//			int find_i = len - 1;
//			while (find_i > i)
//			{
//				if (a[find_i] == a[i])
//				{
//					count_right += find_i - i + 1;
//					i = find_i;
//					break;
//				}
//				--find_i;
//			}
//		}
//		int count_left = 0;
//		for (int i = 0; i < len; ++i)
//		{
//			int find_i = i + 1;
//			while (find_i < len)
//			{
//				if (a[find_i] == a[i])
//				{
//					count_left += find_i - i + 1;
//					i = find_i;
//					break;
//				}
//				++find_i;
//			}
//		}
//		int count = max(count_left, count_right);
//		cout << count << endl;
//		delete[] a;
//	}
//	return 0;
//}
//int numDecodings(string s)
//{
//    int pre_1 = 1, pre_2 = 1, cur = 1;
//    for (int i = 1; i < s.size(); ++i)
//    {
//        
//    }
//}
//int main()
// {
//     string s("230");
//     cout << numDecodings(s) << endl;
//     return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int numDecodings(string s)
//{
//    int pre_1 = 1, pre_2 = 1, cur = 0;
//    pre_1 = s[0] != '0';
//    for (int i = 1; i < s.size(); ++i)
//    {
//        if (s[i] != '0')cur += pre_1;
//        int tmp = (s[i - 1] - '0') * 10 + s[i];
//        if (tmp >= 10 && tmp <= 26) cur += pre_2;
//        pre_2 = pre_1;
//        pre_1 = cur;
//    }
//    return cur;
//}
//int main()
//{
//    string s("226");
//    cout << numDecodings(s) << endl;
//    return 0;
//}
//#include <vector>
//int minPathSum(int* grid[3]) {
//    int row = 3, col = 3;
//    vector<int>dp(col + 1);
//    for (int i = 1; i < row + 1; ++i)
//    {
//        for (int j = 1; j < col + 1; ++j)
//        {
//            dp[j] = min(dp[j], dp[j - 1]) + grid[i - 1][j - 1];
//        }
//    }
//    return dp[col];
//}
//int main()
//{
//    
//    
//}
//#include <vector>
//
//bool dfs(vector<vector<int>>labyrinth, int i, int j)
//{
//	char tmp = labyrinth[i][j];
//	if (tmp == '.')
//	{
//		
//	}
//	else return false;
//}
//
//int main()
//{
//	int row, col;
//	cin >> row >> col;
//	vector<vector<int>>labyrinth(row + 2, vector<int>(col + 2));
//	for (int i = 1; i < row; ++i)
//	{
//		labyrinth[i][0] = '#';
//		for (int j = 1; j < col; ++j)
//		{
//			cin >> labyrinth[i][j];
//		}
//	}
//	for (int i = 0; i < col + 2; ++i)
//	{
//		labyrinth[0][i] = '#';
//		labyrinth[row + 1][i] = '#';
//	}
//	int flag = dfs(labyrinth, 1, 1);
//
//	return 0;
//}

int main()
{
	cout << "5\r6" << endl;
	return 0;
}