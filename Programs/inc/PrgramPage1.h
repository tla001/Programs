/*
 * PrgramPage1.h
 *
 *  Created on: 2016年11月25日
 *      Author: tla001
 */

#ifndef PRGRAMPAGE1_H_
#define PRGRAMPAGE1_H_
#include "Common.h"

class Q2 {
	/*
	 * 世界上有10种人，一种懂二进制，一种不懂。
	 * 那么你知道两个int32整数m和n的二进制表达，有多少个位(bit)不同么？
	 */
public:
	/**
	 * 获得两个整形二进制表达位数不同的数量
	 * 
	 * @param m 整数m
	 * @param n 整数n
	 * @return 整型
	 */
	static int countBitDiff(int m, int n) {
		int bits = sizeof(int) * 8;
		int tem = 1;
		int num = 0;
		while (bits) {
			if ((m & tem) != (n & tem))
				num++;
			tem = tem << 1;
			bits--;
		}
		return num;
	}
	static void test() {
		int m = 1999;
		int n = 2999;
		cout << countBitDiff(m, n) << endl;
	}
};
class Q3 {
	/*
	 * 假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，
	 * 并且买入前一定要先保证手上没有股票。若两次交易机会都放弃，收益为0。
	 * 设计算法，计算你能获得的最大收益。 输入数值范围：2<=n<=100,0<=prices[i]<=100
	 */
public:
	/**
	 * 计算你能获得的最大收益
	 * 
	 * @param prices Prices[i]即第i天的股价
	 * @return 整型
	 */
	int calculateMax(vector<int> prices) {
		vector<int> v(prices.size(), 0);
		int min_prices = prices[0];
		int max_prices = prices[prices.size() - 1];
		int max_profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			v[i] = max_profit = max(max_profit, prices[i] - min_prices);
			min_prices = min(prices[i], min_prices);
		}
		max_profit = 0;
		for (int i = prices.size() - 2; i >= 0; --i) {
			max_profit = max(max_profit, max_prices - prices[i]);
			v[i] += max_profit;
			max_prices = max(max_prices, prices[i]);
		}
		int profit = v[0];
		for (int i = 1; i < prices.size() - 1; ++i) {
			profit = max(profit, v[i]);
		}
		return profit;
	}
};
class Q4 {
	/*
	 * A string s is LUCKY if and only if the number of different characters
	 *  in s is a fibonacci number. Given a string consisting of only lower
	 *  case letters , output all its lucky non-empty substrings in
	 *  lexicographical order. Same substrings should be printed once.
	 *  (lucky字符串的特征是字符串中字符种类数是斐波拉契数列中的数字，例如：aa，字符种类是1；
	 *   abc 字符种类是3）
	 */
public:
	vector<int> fib;
	bool isFib(int n) {
		if (fib.size() < 2) {
			fib.push_back(1);
			fib.push_back(2);
		}
		while (n > fib.size()) {
			fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
		}
		if (find(fib.begin(), fib.end(), n) == fib.end())
			return false;
		return true;
	}
	int count(string str) {
		int p[26] = { 0 }, res = 0;
		for (int i = 0; i < str.length(); i++) {
			if (p[str[i] - 'a'] == 0) {
				res++;
				p[str[i] - 'a'] = 1;
			}
		}
		return res;
	}
	void luckString() {
		string str;
		set < string > result;
		int fib[] = { 1, 2, 3, 5, 8, 13, 21, 34 };
		vector<int> Fib(fib, fib + sizeof(fib) / sizeof(int));
		cin >> str;
		for (int n = 1; n < str.length(); n++) {
			for (int i = 0; i < str.length(); i++) {
				string ss = str.substr(i, n);
				if (find(Fib.begin(), Fib.end(), count(ss)) != Fib.end())
					result.insert(ss);
			}
		}
		for (set<string>::iterator ite = result.begin(); ite != result.end();
				ite++) {
			cout << *ite << endl;
		}
	}
};
class Q5 {
	/*
	 * numberic keypad
	 */
//	int pad[10][10] = { { 0 }, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 0, 2, 3, 5,
//			6, 8, 9 }, { 3, 6, 9 }, { 0, 4, 5, 6, 7, 8, 9 }, { 0, 5, 6, 8, 9 },
//			{ 6, 9 }, { 0, 7, 8, 9 }, { 0, 8, 9 }, { 9, } };
//	int last[10] = { 0, 9, 6, 2, 6, 4, 1, 3, 2, 0 };
//	string num;
//	int n;
//	bool st;
//	bool test(int index, int n) {
//		for (int i = index; i < num.size(); i++) {
//			int ts = num[i] - '0';
//
//			if (n == ts) {
//				n = pad[n][0];
//				continue;
//			} else if (n < ts) {
//				return true;
//			} else {
//				return false;
//			}
//		}
//		return true;
//	}
//	int main() {
//		//如果非st就尽量大
//		//如果st就看后面最小的能不能满足
//		int t;
//		cin >> t;
//		while (t--) {
//			cin >> num;
//			int n = num.size();
//			st = true;
//			string ans;
//			int now = 1;
//			for (int i = 0; i < num.size(); i++) {
//				int ts = num[i] - '0';
//				if (st) {
//					for (int j = last[now]; j >= 0; j--) {
//						if (pad[now][j] > ts) {
//							continue;
//						} else if (pad[now][j] == ts) {
//							if (test(i, pad[now][j])) {
//								now = pad[now][j];
//							} else {
//								st = false;
//								now = pad[now][j - 1];
//							}
//						} else {
//							st = false;
//							now = pad[now][j];
//						}
//						ans += '0' + now;
//						break;
//					}
//				} else {
//					ans += (char) ('0' + pad[now][last[now]]);
//					now = pad[now][last[now]];
//				}
//			}
//			cout << ans << endl;
//		}
//
//	}
};
class Q6 {

};
class Q7 {

};
class Q8 {
	/*
	 * 最高分
	 */
public:
	static void test() {
		int n, m;
		char flag;
		int manu[2];
		//cout << "input n m:" << endl;
		while (cin >> n >> m) {
			//cout << "n= " << n << "\t" << "m= " << m << endl;
			int *score = new int[n];
			//cout << "input scores:" << endl;
			for (int i = 0; i < n; i++)
				cin >> score[i];

			for (int i = 0; i < m; i++) {
				//cout << "flag :" << endl;
				cin >> flag >> manu[0] >> manu[1];
				if (flag == 'Q') {
					int low = manu[0] > manu[1] ? manu[1] : manu[0];
					int high = manu[0] > manu[1] ? manu[0] : manu[1];
					int max = -1;
					for (int j = low - 1; j < high; j++) {
						if (score[j] > max)
							max = score[j];
					}
					cout << max << endl;
				} else if (flag == 'U') {
					score[manu[0] - 1] = manu[1];
				}
			}
			delete[] score;
		}
	}
};
class Q9 {
public:
	static void test() {
		string input;
		int line;
		map<pair<string, int>, int> errors;
		for (int i = 0; i < 8; i++) {
			cin >> input >> line;
			size_t pos;
			string filename;

			pos = input.find_last_of("\\");
			if (pos != string::npos)
				filename = input.substr(input.find_last_of("\\") + 1);
			else
				filename = input;
			cout << "filename: " << filename << "\tline: " << line << endl;
			pair<string, int> keys = pair<string, int>(filename, line);
			if (errors.find(keys) == errors.end()) {
				errors.insert(make_pair(keys, 1));
			} else {
				errors[keys]++;
			}
//			if (filename.size() > 16) {
//				filename = filename.substr(filename.size() - 16);
//			}
//			cout << "filename: " << filename << "\tline: " << line << endl;
		}
		for (map<pair<string, int>, int>::iterator ite = errors.begin();
				ite != errors.end(); ite++) {
			cout << "filename: " << ite->first.first << "\tline: "
					<< ite->first.second << "\tnums: " << ite->second << endl;
		}
	}
	static bool compare(pair<string, int> a, pair<string, int> b) {
		return a.second > b.second;
	}
	static void test1() {
		string input;
		string filename;
		vector<pair<string, int>> errors;
		while (getline(cin, input)) {
			if (input.size() == 0)
				break;
			size_t pos;

			pos = input.find_last_of("\\");
			if (pos != string::npos)
				filename = input.substr(pos + 1);
			else
				filename = input;
			//cout << "filename: " << filename << endl;
			errors.push_back(make_pair(filename, 1));
			for (int i = 0; i < errors.size() - 1; i++) {
				if (errors[i].first == filename) {
					errors[i].second++;
					errors.pop_back();
					break;
				}
			}
		}
		stable_sort(errors.begin(), errors.end(), compare);
		int idx = 0;
		while (idx < 8 && idx < errors.size()) {
			string check = errors[idx].first;
			int t = check.find(' ');
			if (t > 16)
				errors[idx].first.erase(0, t - 16);
			cout << errors[idx].first << ' ' << errors[idx].second << endl;
			idx++;
		}
	}
};
class Q10 {
	/*
	 * POKER
	 */
#define PrintS1 {cout<<s1<<endl;return ;}
#define PrintS2 {cout<<s2<<endl;return ;}

public:
	int count(string &str) {
		int n = 0;
		string::size_type i = 0, k = 0;
		while ((k = str.find(' ', i)) != string::npos) {
			n++;
			i = k + 1;
		}
		return n;
	}
	void test() {
		string input;
		getline(cin, input);
		int t = input.find('-');
		string s1 = input.substr(0, t);
		string s2 = input.substr(t + 1);
		int n1 = count(s1);
		int n2 = count(s2);
		string POKER = "345678910JQKA2jokerJOKER";
		vector<string>MAX= {"joker JOKER", "JOKER joker"};
		if (s1 == MAX[0] || s1 == MAX[1])
			PrintS1
		if (s2 == MAX[0] || s2 == MAX[1])
			PrintS2
		if (n1 == n2) {
			string f1, f2;
			string::size_type k = s1.find(' ');
			f1 = s1.substr(0, k);
			k = s2.find(' ');
			f2 = s2.substr(0, k);
			if (POKER.find(f1) > POKER.find(f2))
				PrintS1
			PrintS2
		}
		if (n1 == 3 && n2 != 3)
			PrintS1
		if (n2 == 3 && n1 != 3)
			PrintS2
	}
};
class Q11 {
	/*
	 * 二分查找
	 */
	int getPos(vector<int> A, int n, int val) {
		int low = 0;
		int high = n - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (val < A[mid]) {
				high = mid - 1;
			} else if (val > A[mid]) {
				low = mid + 1;
			} else {
				if (mid > 0 && A[mid] == A[mid - 1])
					high = mid - 1;
				else
					return mid;
			}
		}
		return -1;
	}
};
class Q12 {
public:
	static char findFirstRepeat(string A, int n) {
		// write code here
		map<char, int> m;
		for (int i = 0; i < n; i++) {
			if (m.find(A[i]) == m.end()) {
				m.insert(make_pair(A[i], 1));
			} else {
				return A[i];
			}
		}
		return NULL;
	}

};
class Q13 {

public:
	static bool compare(pair<string, int> a, pair<string, int> b) {
		return a.second > b.second;
	}
	static int count(string str) {
		int n = 0;
//		string::size_type i = 0, k = 0;
//		while ((k = str.find("coder", i)) != string::npos) {
//			n++;
//			i = k + 5;
//		}
//		return n;
		for (int i = 0; i < str.length() && (i + 4) < str.length();) {
			// 转换成大写方便比较
			if (toupper(str[i]) == 'C' && toupper(str[i + 1]) == 'O'
					&& toupper(str[i + 2]) == 'D' && toupper(str[i + 3]) == 'E'
					&& toupper(str[i + 4]) == 'R') {
				n++;
				// 匹配到i+5
				i += 5;
			} else {
				// 未匹配i+1
				i += 1;
			}
		}
		return n;
	}
	static vector<string> findCoder(vector<string> A, int n) {
		// write code here
		vector < string > res;
		if (n < 1)
			return res;
		string str;
		int nums = 0;
		vector<pair<string, int>> v;
		for (int i = 0; i < n; i++) {
			str = A[i];
			nums = count(str);
			if (nums > 0)
				v.push_back(make_pair(str, nums));
		}
		stable_sort(v.begin(), v.end(), compare);
		for (int i = 0; i < v.size(); i++) {
			res.push_back(v[i].first);
		}
		return res;
	}
	static void test() {
		vector<string> A= {"i am a coder","Coder Coder","Code"};
		vector<string> B=findCoder(A,3);
		for(int i=0;i<B.size();i++) {
			cout<<B[i]<<endl;
		}
	}
};
class Q14 {
	/*
	 * 最大差值
	 */
public:
	//暴力求解
	static int getDis(vector<int> A, int n) {
		vector<int> v;
		int tem = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				tem = A[i] - A[j];
				if (tem < 0)
					tem = 0;
				v.push_back(tem);
			}
		}
		stable_sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << "\t";
		cout << endl;
		return v[v.size() - 1];
	}
	//动态规划
	static int getDis1(vector<int> A, int n) {
		int dis = 0;
		if (n > 1) {
			int min = A[0];
			for (int i = 1; i < n; i++) {
				if (min > A[i]) {
					min = A[i];
				}
				if (A[i] - min > dis) {
					dis = A[i] - min;
				}
			}
		}
		return dis;
	}
	static void test() {
		vector<int> A = { 10, 5, 3, 15 };
		cout << getDis1(A, A.size()) << endl;
	}
};
class Q15 {
	/*
	 * 棋子翻转
	 */
public:
	static vector<vector<int> > flipChess(vector<vector<int> > A,
			vector<vector<int> > f) {
		// write code here
		int x, y, pos;
		map<int, int> m;
		for (int i = 0; i < f.size(); i++) {
			x = f[i].at(0);
			y = f[i].at(1);
			if (x > 1) { //左
				x--;
				pos = 10 * x + y;
				if (m.find(pos) == m.end()) {
					m.insert(make_pair(pos, 1));
				} else {
					m[pos]++;
				}
				x++;
			}
			if (y > 1) { //上
				y--;
				pos = 10 * x + y;
				if (m.find(pos) == m.end()) {
					m.insert(make_pair(pos, 1));
				} else {
					m[pos]++;
				}
				y++;
			}
			if (x < 4) { //右
				x++;
				pos = 10 * x + y;
				if (m.find(pos) == m.end()) {
					m.insert(make_pair(pos, 1));
				} else {
					m[pos]++;
				}
				x--;
			}
			if (y < 4) { //下
				y++;
				pos = 10 * x + y;
				if (m.find(pos) == m.end()) {
					m.insert(make_pair(pos, 1));
				} else {
					m[pos]++;
				}
				y--;
			}
		}
		for (map<int, int>::iterator ite = m.begin(); ite != m.end(); ite++) {
			//cout << "pos: " << ite->first << "\tnusm: " << ite->second << endl;
			if (ite->second % 2 == 1) {
//				cout << "pos: " << ite->first << "\tnusm: " << ite->second
//						<< endl;
				pos = ite->first;
				x = pos / 10 - 1;
				y = pos % 10 - 1;
//				cout << "x:" << x << "\ty:" << y << endl;
//				cout << "raw:" << A[x].at(y) << endl;
				if (A[x].at(y) == 0)
					A[x].at(y) = 1;
				else if (A[x].at(y) == 1)
					A[x].at(y) = 0;
//				cout << "after:" << A[x].at(y) << endl;
			}
		}
		return A;
	}
	static void test() {
		vector<vector<int> >
		A= { {	0,0,1,1}, {1,0,1,0}, {0,1,1,0}, {0,0,1,0}};
		vector<vector<int> > f= { {2,2}, {3,3}, {4,4}};

		vector<vector<int>>B=flipChess(A,f);
		vector<int>a;
		for(int i=0;i<B.size();i++) {
			a=B[i];
			for(int j=0;j<a.size();j++) {
				cout<<a[j]<<"\t";
			}
			cout<<endl;
		}
	}
};
class Q16 {
	/*
	 * 直方图最大面积
	 */
public:
	static int countArea(vector<int> A, int n) {
		// write code here
		int maxarea = 0;
		int min;
		for (int i = 0; i < n; i++) {
			min = 655535;
			for (int j = i; j >= 0; j--) {
				min = min > A[j] ? A[j] : min;
				maxarea =
						maxarea > (i - j + 1) * min ?
								maxarea : (i - j + 1) * min;
			}
		}
		return maxarea;
	}

	static void test() {
		vector<int> A = { 2, 7, 9, 4, 1 };
		int n = A.size();
		cout << countArea(A, n) << endl;
	}
};
class Q17 {
public:
	static int test() {
		//根据题中给出的例子，这个字符串只包含小写字母，不然答案就不应该是56了
		string s1, s2;
		int len1, len2;
		while (cin >> s1 >> s2 >> len1 >> len2) {
			//只包含小写字母的字符串可以看成26进制的数制
			//将s1和s2补长到len2长度
			s1.append(len2 - s1.size(), 'a');
			s2.append(len2 - s2.size(), (char) ('z' + 1));
			vector<int> array;
			for (int i = 0; i < len2; i++) {
				array.push_back(s2[i] - s1[i]);
			}
			int result = 0;
			for (int i = len1; i <= len2; i++) {
				for (int k = 0; k < i; k++) {
					result += array[k] * pow(26, i - 1 - k);
				}
			}
			//所有字符串最后都不包含是s2自身，所以最后要减1；
			cout << result << endl;
		}
		return 0;
	}
};
class Q18 {
#include <math.h>
public:
	static double aveAge(int Y, double x, int N) {
		if (N == 1) {
			return (Y + 1) * (1 - x) + 21 * x;
		} else {
			//cout << (aveAge(Y, x, N - 1) + 1) * (1 - x) + 21 * x << endl;
			return (aveAge(Y, x, N - 1) + 1) * (1 - x) + 21 * x;
		}
		return -1;
	}
	static void test() {
		int W, Y, N;
		double x;
		int ave = 0;
		while (cin >> W >> Y >> x >> N) {
			ave = ceil(aveAge(Y, x, N));
			cout << "ave= " << ave << endl;
		}
	}
};
class Q19 {
public:
	static void test() {
		int n, t, c;
		while (cin >> n >> t >> c) {
			//cout << n << " " << t << " " << c << endl;
			int *a = new int[n];
			int num = n - 1;
			int sum = 0;
			int count = 0;
			while (num >= 0) {
				cin >> a[num--];
			}
			for (int i = 0; i < c; i++) {
				sum += a[i];
			}
			if (sum <= t)
				count++;
			for (int i = c; i < n; i++) {
				sum = sum + a[i] - a[i - c];
				if (sum <= t)
					count++;
			}
			cout << count << endl;
			delete[] a;
		}
	}
};
class Q20 {
public:
//	struct Point {
//		int x;
//		int y;
////		Point(int a, int b) :
////				x(x), y(b) {
////		}
//	};
	static void test() {
		int n = 0;
		int x, y;
		long long minX, maxX, minY, maxY;
		while (cin >> n) {
			//Point *ps = new Point[n];
			for (int i = 0; i < n; i++) {
				cin >> x >> y;
				if (i == 0) {
					minX = x;
					minY = y;
					maxX = x;
					maxY = y;
				} else {
					if (x > maxX)
						maxX = x;
					if (x < minX)
						minX = x;
					if (y > maxY)
						maxY = y;
					if (y < minY)
						minY = y;
				}
			}
			int lenx = maxX - minX;
			int leny = maxY - minY;
			int len = lenx > leny ? lenx : leny;
			cout << len * len << endl;
			//delete[] ps;
		}
	}
};

class Q21 {

public:

	static void test() {
		int n, m, x, y, t;
		double pcc = 0.0, pss = 0.0, p = 0.0;
		while (cin >> n >> m >> x >> y >> t) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					cin >> p;
					pss += p;
					if (x == i && y == j)
						pcc = p;
				}
			}
			pss /= n * m;
			pcc = 1 - pow(1 - pcc, t);
			pss = 1 - pow(1 - pss, t);
			cout << setiosflags(ios::fixed) << setprecision(2);
//			cout.scientific;
//			cout.precision(2);
			if (pcc == pss) {
				cout << "equal\n" << pcc << endl;
			}
			if (pcc > pss) {
				cout << "cc\n" << pcc << endl;
			}
			if (pcc < pss) {
				cout << "ss\n" << pss << endl;
			}
		}
	}
};
class Q22 {
public:
	static void test() {
		int n, m, k;
		while (cin >> n >> m >> k) {
			vector < vector<double> > p((n + 1), vector<double>(m + 1));
			int x, y;
			for (int i = 0; i < k; i++) {
				cin >> x >> y;
				p[x][y] = -1.0;
			}
			p[1][1] = 1.0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (!(i == 1 && j == 1)) {
						if (p[i][j] == -1.0) {
							p[i][j] = 0;
						} else {
							p[i][j] = p[i - 1][j] * (j == m ? 1 : 0.5)
									+ p[i][j - 1] * (i == n ? 1 : 0.5);
						}
					}
				}
			}
			cout << setiosflags(ios::fixed) << setprecision(2);
			cout << p[n][m] << endl;
		}
	}
};
class Q23 {
	/*
	 * 无论圆桌如何移动，都必须在圆桌边缘找一个点旋转。
	 * 这就表明旋转后的圆心与最初的圆心连线肯定是2r的倍数
	 * （两圆心，向x轴或y轴做垂线，能得到一个直角三角形），几倍就表示最终移动了几步。
	 *
	 */
public:
	static void test() {
		int r, x, y, x1, y1;
		while (cin >> r >> x >> y >> x1 >> y1) {
			float dis = sqrt(
					(float) (x - x1) * (x - x1) + (float) (y - y1) * (y - y1));
			cout << (int) ceil(dis / r / 2) << endl;
		}
	}
};
#endif /* PRGRAMPAGE1_H_ */
