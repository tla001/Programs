/*
 * ProgramPage2.h
 *
 *  Created on: 2016年12月23日
 *      Author: tla001
 */

#ifndef INC_PROGRAMPAGE2_H_
#define INC_PROGRAMPAGE2_H_

#include "Common.h"

class Q31 {
public:
	static void test() {
		string str = "[a+b*(5-4)]*{x+b+b*(({1+2)}}";
		cout << chkLegal(str) << endl;
	}
	static bool chkLegal(string A) {
		// write code here
		int num = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] == '(' || A[i] == '[' || A[i] == '{') {
				num++;
			}
			if (A[i] == ')' || A[i] == ']' || A[i] == '}') {
				num--;
			}
		}
		//cout << "num " << num << endl;
		return (num == 0) ? true : false;
	}
};
class Q32 {
public:
	static void test() {
		vector<int> stops = { 27, 10, 17, 4 };
		vector<int> period = { 1, 3, 1, 3 };
		vector<int> interval = { 4, 2, 4, 3 };
		int n = 4;
		int s = 25;
		cout << chooseLine(stops, period, interval, n, s) << endl;
	}
	static int chooseLine(vector<int> stops, vector<int> period,
			vector<int> interval, int n, int s) {
		// write code here
		int waitTime = 0;
		int minTime = 65535;
		int time = 0;
		for (int i = 0; i < n; i++) {
			waitTime =
					(s % interval[i] == 0) ?
							0 : (interval[i] - s % interval[i]);
			time = waitTime + stops[i] * period[i] + (stops[i] + 1) * 5;
			minTime = minTime < time ? minTime : time;
		}
		return minTime + s;
	}
};
class Q33 {
public:
	static void test() {
		string A = "A%sC%sE";
		int n = 7;
		vector<char> arg = { 'B', 'D', 'F' };
		int m = 0;
		formatString(A, n, arg, m);
	}
	static string formatString(string A, int n, vector<char> arg, int m) {
		// write code here
		int pos = -1;
		int i = 0;
		while ((pos = A.find("%s", pos + 1)) != string::npos) {
//			cout << "1pos " << pos << " A " << i << " " << A << endl;
			A.replace(pos, 2, &arg[i], 1);
//			cout << "pos " << pos << " A " << i << " " << A << endl;
			i++;
		}
		while (i < arg.size()) {
			A.append(&arg[i], 1);
			i++;
		}
		cout << A << endl;
		return A;
	}
};

class Q34 {
public:
	static void test() {
		vector<string> A= {"nowcoder","hello","now"};
		int n=3;
		vector<string> keys= {"coder","now"};
		int m=2;
		vector<int> res=containKeyword(A, n, keys,m);
		for(vector<int>::iterator ite=res.begin();ite!=res.end();ite++) {
			cout<<*ite<<"\t";
		}
		cout<<endl;
	}
	static vector<int> containKeyword(vector<string> A, int n, vector<string> keys,
			int m) {
		// write code here
		vector<int> res;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < keys.size(); j++) {
				if (A[i].find(keys[j], 0) != string::npos) {
					res.push_back(i);
					break;
				}
			}
		}
		if (res.empty())
		res.push_back(-1);
		return res;
	}
};
class Q35 {
public:
	static void test() {

	}
	static vector<string> chkBlood(string father, string mother) {
		// write code here
		vector < string > res;
		string temp = father + mother;
		if (temp.find("A") != string::npos) {
			res.push_back("A");
		}
		if (temp.find("A") != string::npos && temp.find("B") != string::npos
				&& temp.find("O") == string::npos) {
			res.push_back("AB");
		}
		if (temp.find("B") != string::npos) {
			res.push_back("B");
		}
		if (father != "AB" && mother != "AB") {
			res.push_back("O");
		}
		return res;
	}
};
class Q36 {
public:
	static void test() {
		int x, n;
		char holes[21] = { 0 };
		while (cin >> x >> n) {
			memset(holes, 0, sizeof(holes));
			for (int i = 1; i <= n; i++) {
				x = (x + (i - 1) % 20) % 20;
				if (i > 1)
					x++;
				cout << " i " << i << " x " << x << endl;
				holes[x] = 1;
			}
			int nums = 0;
			for (int i = 1; i <= 20; i++) {
				if (holes[i] == 0) {
					nums++;
					cout << i << " ";
				}
			}
			if (nums == 0)
				cout << "-1";
			cout << endl;
		}
	}
};
class Q37 {
	/*
	 * 小东所在公司要发年终奖
	 */
public:
	static void test() {
//		vector<vector<int> >board= { {426,306,641,372,477,409}, {223,172,327,586,363,553}, {292,645,248,316,711,295}, {127,192,495,208,547,175}, {131,448,178,264,207,676}, {655,407,309,358,246,714}};
		vector<vector<int> >board= { {138,457,411,440,433,149}, {203,288,318,597,246,686}, {442,105,424,544,406,532}, {172,592,626,410,511,636}, {394,596,644,454,343,389}, {573,460,307,221,325,104}};
		cout<<getMost(board)<<endl;
	}
	static int getMost(vector<vector<int> > board) {
		// write code here
		const int m = board.size();
		const int n = board[0].size();
		int dp[m][n];
		dp[0][0]=board[0][0];
//		int sum = board[0][0];
//		int i = 0,j=0;
//		for (;; ) {
//			if((i<m-1)&&(j<n-1)) {
//				sum = (sum + board[i + 1][j]) > (sum + board[i][j + 1]) ?
//				(sum + board[++i][j]) : (sum + board[i][++j]);
//				//cout<<"[ "<<i<<" , "<<j<<" ] sum= "<<sum<<endl;
//			}
//			else if(i==m-1) {
//				sum = sum + board[i][++j];
//				//cout<<"[ "<<i<<" , "<<j<<" ] sum= "<<sum<<endl;
//			}
//			else if(j==n-1) {
//				sum =sum + board[++i][j];
//				//cout<<"[ "<<i<<" , "<<j<<" ] sum= "<<sum<<endl;
//			}
//			if((i==m-1)&&(j==n-1))
//			break;
//		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(!(i==0&&j==0)) {
					dp[i][j]=(((j==0)?0:dp[i][j-1])>((i==0)?0:dp[i-1][j])?((j==0)?0:dp[i][j-1]):((i==0)?0:dp[i-1][j]))+board[i][j];
				}
			}
		}
		return dp[5][5];
	}
};
class Q38 {
	//计算精度
	/*
	 * 小东和三个朋友一起在楼上抛小球
	 */
public:
	static void test() {
		int A = 100;
		int B = 90;
		int C = 80;
		int D = 70;
		cout << calcDistance(A, B, C, D) << endl;
	}
	static int calcDistance(int A, int B, int C, int D) {
		// write code here
		return (int) distance(A) + distance(B) + distance(C) + distance(D);
	}
	static double distance(double dis) {
		if (dis == 0)
			return 0;
		else
			return dis / 2 * 3 + distance(dis / 2);
	}
};
class Q40 {
public:
	/*
	 设苹果总数x, 由题意知（x+n-1） 可被n 整除，
	 第一只熊分到 （x+n-1)/n只苹果（分到的+扔掉的）。
	 此时还剩下（n-1)(x+n-1)/n 只苹果。
	 第二只熊分得 （n-1)(x+n-1)/n^2 只苹果(分到的+扔掉的），
	 依次类推   ……    最后一只熊（分到+扔掉）K= (n-1)^(n-1)(x+n-1)/n^n  只苹果。
	 K 为自然数，故分子必须是n^n的倍数。  由于(n-1)^(n-1) 与 n^n 互质，
	 则必有 (x+n-1) = t * n^n 。显然 t 取 1 时x 最小， x= n^n -n+1。
	 */
	static void test() {
		int n = 2;
		while (cin >> n)
			cout << ave(n) << endl;
	}
	static int ave(int n) {
		return pow(n, n) - n + 1;
	}
};
#endif /* INC_PROGRAMPAGE2_H_ */
