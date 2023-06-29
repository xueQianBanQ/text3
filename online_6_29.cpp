#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//class Bag
//{
//public:
//	Bag(int num, int capacity)
//		:_num(num)
//		,_capacity(capacity)
//	{
//		 _c = new int[num + 1]{0};
//		 _w = new int[num + 1]{0};
//	}
//	void Store(int cap, int price, int i)
//	{
//		_c[i] = cap;
//		_w[i] = price;
//	}
//	int Bag_max(void)
//	{
//		int** f = new int*[_num + 1];
//		for (int i = 0; i < _num + 1; i++)
//		{
//			f[i] = new int[_capacity + 1] {0};
//		}
//		for (int i = 1; i < _num + 1; i++)
//		{
//			for (int j = 1; j < _capacity + 1; j++)
//			{
//				if (j < _c[i])f[i][j] = f[i - 1][j];
//				else {
//					f[i][j] = max(f[i - 1][j], f[i - 1][j - _c[i]] + _w[i]);
//				}
//			}
//		}
//		int _max = f[_num][_capacity];
//		//释放
//		for (int i = 0; i < _num + 1; i++)
//		{
//			delete[]f[i];
//		}
//		delete[]f;
//		return _max;
//	}
//	~Bag()
//	{
//		delete[]_c;
//		delete[]_w;
//	}
//private:
//	int _num;
//	int _capacity;
//	int* _c;//存放每个值得数组//第一个是体积，
//	int* _w;
//};
//
//int main()
//{
//	int num, capacity;
//	cin >> num >> capacity;
//	Bag b(num, capacity);
//	for (int i = 1; i <= num; i++)
//	{
//		int cap, price;
//		cin >> cap >> price;
//		b.Store(cap, price, i);
//	}
//	const int max_price = b.Bag_max();
//	cout << max_price << endl;
//	return 0;
//}

//                                                 01背包问题
//#define MAX 1001
//int dp[MAX];
//int c[MAX], w[MAX];
//int main()
//{
//	int num, capacity;
//	cin >> num >> capacity;
//	for (int i = 1; i < num + 1; i++)
//	{
//		cin >> c[i] >> w[i];
//		for (int j = capacity; j >= 1; j--)
//		{
//			if(j >= c[i]) dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
//		}
//	}
//	cout << dp[capacity] << endl;;
//	return 0;
//}

//                                                  通天之分组背包
//int main()
//{
//	int bag_capacity;
//	int num;
//	cin >> bag_capacity >> num;
//	int* dp = new int[bag_capacity + 1] {0};
//	int** f = new int* [num + 1]{0};
//	int max_group = 0;
//	for (int i = 1; i < num + 1; i++)
//	{
//		int weight, worth, group;
//		cin >> weight >> worth >> group;
//		f[i] = new int[3]{weight, worth, group};
//		if (group > max_group) max_group = group;
//	}
//	for (int k = 1; k <= max_group; k++)
//	{
//		for (int j = bag_capacity; j >= 0; j--)
//		{
//			int max_dp = 0;
//			for (int i = 1; i < num + 1; i++)
//			{
//				if (j >= f[i][0] && k == f[i][2])
//				{
//					int _dp = max(dp[j], dp[j - f[i][0]] + f[i][1]);
//					if (_dp > max_dp)max_dp = _dp;
//				}
//				if(max_dp > dp[j])dp[j] = max_dp;
//			}
//		}
//	}
//	int max_worth = dp[bag_capacity];
//	delete[]dp;
//	for (int i = 0; i < num + 1; i++)
//	{
//		delete[]f[i];
//	}
//	delete[]f;
//	cout << max_worth << endl;
//	return 0;
//}



//                                            完全背包问题
//int main()
//{
//	int num, capacity;
//	cin >> num >> capacity;
//	int* dp = new int[capacity + 1]{0};
//	int* c = new int[num + 1]{0};
//	int* w = new int[num + 1]{0};
//	for (int i = 1; i < num + 1; i++)
//	{
//		cin >> c[i] >> w[i];
//		for (int j = capacity; j >= c[i]; j--)
//		{
//			int max_dp = 0;
//			for (int k = 1; k * c[i] <= j; k++)
//			{
//				int _dp = max(dp[j], dp[j - k * c[i]] + k*w[i]);
//				if (_dp > max_dp) max_dp = _dp;
//			}
//			dp[j] = max_dp;
//		}
//	}
//	cout << dp[capacity] << endl;
//	delete[] dp;
//	delete[] c;
//	delete[] w;
//	return 0;
//}
//            有问题
//int main()
//{
//	int num, capacity;
//	cin >> num >> capacity;
//	int* dp = new int[capacity + 1] {0};
//	int* c = new int[num + 1] {0};
//	int* w = new int[num + 1] {0};
//	for (int i = 1; i < num + 1; i++)
//	{
//		cin >> c[i] >> w[i];
//		for (int j = capacity; j >= c[i]; j--)
//		{
//			int k = j / c[i];// ****************************************  k不一定取最大值
//			dp[j] = max(dp[j], dp[j - k * c[i]] + k * w[i]);
//		}
//	}
//	cout << dp[capacity] << endl;
//	delete[] dp;
//	delete[] c;
//	delete[] w;
//	return 0;
//}

//int _max(int* a, int n)
//{
//	int _p = 0;
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i] > a[_p])_p = i;
//	}
//	return _p;
//}
//int _min(int* a, int n)
//{
//	int _p = 0;
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i] < a[_p])_p = i;
//	}
//	return _p;
//}
//
//int main()
//{
//	int case_;
//	cin >> case_;
//	while (case_--)
//	{
//		int num;
//		cin >> num;
//		int* a = new int[num];
//		for (int i = 0; i < num; i++)
//		{
//			cin >> a[i];
//		}
//		int sum = 0;
//		while (num > 1)
//		{
//			int max_p = _max(a, num);
//			if (max_p != num - 1) swap(a[num - 1], a[max_p]);
//			--num;
//			int min_p =  _min(a, num);
//			if (min_p != num - 1) swap(a[num - 1], a[min_p]);
//			--num;
//			sum += (a[num + 1] - a[num]);
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}





//int Check(int* a, int pos, int n)//[ )
//{
//	int count = 0;
//	int flag = 1;
//	for (int i = 0; i < n; i++){
//		if (a[i] > 0 && flag == 1);
//		else if(a[i] < 0 && flag == -1);
//		else
//		{
//			flag = -flag;
//			if(flag == -1)++count;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int case_;
//	cin >> case_;
//	while (case_--)
//	{
//		int num;
//		cin >> num;
//		int* a = new int[num];
//		unsigned long long sum = 0;
//		int posi = 0;
//		while (num--)
//		{
//			int z;
//			cin >> z;
//			if (z == 0)continue;
//			a[posi++] = z;
//			sum += abs(z);
//		}
//		num = posi;
//		int count = Check(a, 0, num);
//		cout << sum << " " << count << endl;
//		delete[] a;
//	}
//	return 0;
//}


//int main()
//{
//	int case_;
//	cin >> case_;
//	while (case_--)
//	{
//		unsigned long long ver;
//		cin >> ver;
//		unsigned long long sum = ver;
//		while (ver != 1)
//		{
//			ver /= 2;
//			sum += ver;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}


//                               多重背包问题
//int main()
//{
//	int capacity, num;
//	cin >> num >> capacity;
//	int* dp = new int[capacity + 1] {0};
//	while(num--)
//	{
//		int c[10], w[10], n;
//		cin >> c[0] >> w[0] >> n;
//		int i = 0;
//		for (int j = 1; j <= n; j <<= 1)
//		{
//			c[i] = c[0] * j;
//			w[i] = w[0] * j;
//			n -= j;
//			++i;
//		}
//		if (n != 0)
//		{
//			c[i] = c[0] * n;
//			w[i] = w[0] * n;
//			++i;
//		}
//		--i;
//		while (i >= 0)
//		{
//			for (int j = capacity; j >= c[i]; --j)
//			{
//				dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
//			}
//			--i;
//		}
//	}
//	cout << dp[capacity] << endl;
//	delete[] dp;
//	return 0;
//}

//const int N = 20010;
//int n, m;
//int f[N], g[N], q[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		int c, w, s;
//		cin >> c >> w >> s;
//		memcpy(g, f, sizeof(f));
//		for (int j = 0; j < c; j++)
//		{
//			int hh = 0, tt = -1;
//			for (int k = j; k <= m; k += c)
//			{
//				f[k] = g[k];
//				if (hh <= tt && k - s * c > q[hh])++hh;
//				if (hh <= tt)f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / c * w);
//				while (hh <= tt && g[q[tt]] - (q[tt] - j) / c * w <= g[k] - (k - j) / c * w)tt--;
//				q[++tt] = k;
//			}
//		}
//	}
//	cout << f[m] << endl;
//	return 0;
//}


//int main()
//{
//	int case_;
//	cin >> case_;
//	while (case_--)
//	{
//		int n;
//		cin >> n;
//		int* a = new int[n];
//		int count_n = 0;
//		int count_p = 0;
//		int count = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> a[i];
//			if (a[i] == 1)++count_p;
//			else ++count_n;
//		}
//		if (count_p >= count_n)
//		{
//			if (count_n % 2 != 0)
//			{
//				++count;
//			}
//		}
//		else
//		{
//			count = (count_n - count_p)/2 + (count_n - count_p) % 2;
//			count_n -= count;
//			if (count_n % 2 != 0)
//			{
//				++count;
//			}
//		}
//		cout << count << endl;
//		delete[]a;
//	}
//	return 0;
//}


//int main()
//{
//	int case_;
//	cin >> case_;
//	while (case_--)
//	{
//		int n;
//		cin >> n;
//		string a;
//		string b;
//		cin >> a >> b;
//		string::iterator it_a = a.begin();
//		string::iterator it_b = b.begin();
//		string::reverse_iterator rit_b = b.rbegin();
//		int count = 0, r_count = 0;
//		while (it_a != a.end())
//		{
//			if (*it_a != *it_b)++count;
//			if (*it_a != *rit_b)++r_count;
//			++it_a;
//			++it_b;
//			++rit_b;
//		}
//
//			if (count % 2 == 0)count = count * 2;
//			else count = count * 2 - 1;
//
//		if (r_count != 0)
//		{
//			if (r_count % 2 == 0) r_count = r_count * 2 - 1;
//			else r_count = r_count * 2;
//		}
//		else
//		{
//			r_count = 2;
//		}
//
//		cout << min(count, r_count) << endl;
//	}
//	return 0;
//}


int main()
{
	int case_;
	cin >> case_;
	while (case_--)
	{
		string a, b;
		cin >> a >> b;
		int max_ = 0;
		if (a == b)max_ = 0;
		else if (a.size() < b.size())
		{
			max_ = (b[0] - '0') + (b.size() - 1) * 9;
		}
		else if (a[0] < b[0])
		{
			max_ = (b[0] - a[0]) + (b.size() - 1) * 9;
		}
		else
		{
			int i;
			for (i = 0; i < a.size(); i++)
			{
				if (a[i] < b[i])break;
				max_ += (b[i] - a[i]);
			}
			if (i != a.size())
			{
				max_ += ((b[i] - a[i]) + (a.size() - i - 1) * 9);
			}
		}
		cout << max_ << endl;
	}
	return 0;
}
