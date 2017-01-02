/*
 * ProgramPage3.h
 *
 *  Created on: 2016年12月28日
 *      Author: tla001
 */

#ifndef INC_PROGRAMPAGE3_H_
#define INC_PROGRAMPAGE3_H_

#include "Common.h"

class Q41 {
public:
	static void test() {
		int n;
		long r, avg;
		while (cin >> n >> r >> avg) {
			long long sum = n * avg;
			cout << "sum " << sum << endl;
			multimap<long, long> m;
			long a, b;
			long long time = 0;
			for (int i = 0; i < n; i++) {
				cin >> a >> b;
				sum -= a;
				m.insert(make_pair(b, r - a));
			}
			int seq = 0;
			if (sum > 0)
				for (multimap<long, long>::iterator ite = m.begin();
						ite != m.end(); ite++) {
					cout << " sum " << sum << " second " << ite->second
							<< " first " << ite->first << endl;
					if (sum >= ite->second) {
						time += (ite->second) * (ite->first);
						sum -= ite->second;
					} else {
						time += sum * (ite->first);
						sum -= sum;
					}

					cout << "seq " << seq++ << " sum " << sum << " time "
							<< time << endl;
					if (sum == 0)
						break;
				}
			cout << time << endl;
		}
	}
};
class Q42 {
public:
	static void test() {
		int n, l;
		while (cin >> n >> l) {
			vector<int> v;
			int a;
			for (int i = 0; i < n; i++) {
				cin >> a;
				v.push_back(a);
			}
			int max = 0;
			stable_sort(v.begin(), v.end());
			for (int i = 1; i < v.size(); i++) {
				//cout << v[i] << "\t";
				max = max > (v[i] - v[i - 1]) ? max : (v[i] - v[i - 1]);
			}
			double half = (double) max / 2;
			cout << setiosflags(ios::fixed) << setprecision(2);
			int head = v[0] > (l - v[n - 1]) ? v[0] : (l - v[n - 1]);
			if (half < (double) head) {
				cout << (double) head << endl;
			} else {
				cout << (double) half << endl;
			}
		}
	}
};
class Q43 {
	/*
	 * 格雷码
	 */
public:
	static void test() {
		int n = 0;
		while (cin >> n) {
			vector < string > res = getGray(n);
			for (int i = 0; i < res.size(); i++) {
				cout << res[i] << "\t";
			}
			cout << endl;
		}
	}

	static vector<string> getGray(int n) {
		vector < string > res;
		if (n == 1) {
			res.push_back("0");
			res.push_back("1");
			return res;
		}
		vector < string > v = getGray(n - 1);
		int len = pow(2, n - 1);
		for (int i = 0; i < len; i++) {
			res.push_back("0" + v[i]);
		}
		for (int i = len - 1; i >= 0; i--) {
			res.push_back("1" + v[i]);
		}
		return res;
	}
};
class Q44 {
public:
	static void test() {
		vector<int> gifts = { 1, 2, 3, 2, 2, 3, 3 };
		int n = 7;
		cout << getValue(gifts, n) << endl;
	}
	static int getValue(vector<int> gifts, int n) {
		stable_sort(gifts.begin(), gifts.end());
		int pre, cur;
		pre = cur = gifts[0];
		int sum = 1;
		for (int i = 1; i < gifts.size(); i++) {
			cur = gifts[i];
			if (pre != cur) {
				sum = 0;
			}
			sum++;
			if (sum > n / 2)
				return cur;
			if ((n - i + sum) < (n / 2 + 1))
				break;
			pre = cur;
		}
		return 0;
	}
};
#endif /* INC_PROGRAMPAGE3_H_ */
