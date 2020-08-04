#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	 * 得到牛牛能够凑到的最大的数字
	 * @param n int整型 牛牛能够承受的价格
	 * @param a int整型vector 1-9这九个数字的价格数组
	 * @return string字符串
	 */
	string solve(int n, vector<int> &a) {
		// write code here
		int minIndex = 8;
		for (int i = 7; i >= 0; --i) {
			if (a[i] < a[minIndex]) {
				minIndex = i;
			}
		}

		if (n < a[minIndex])
			return "-1";

		int k = n / a[minIndex];
		char c = '1' + minIndex;
		string ans(k, c);

		int d = n % a[minIndex];
		if (d == 0)
			return ans;

		int j = 0;
		for (int i = 8; i > minIndex; --i) {
			while (a[i] <= a[minIndex] + d) {
				ans[j] = '1' + i;
				d -= a[i] - a[minIndex];
				++j;
			}
			if (d == 0)
				break;
		}

		return ans;
	}
};

int main(int argc, char **argv) {
	vector<int> data { 5, 4, 3, 2, 1, 2, 3, 4, 5 };
	cout << Solution().solve(5, data) << endl;
	data = vector<int> { 9, 11, 1, 12, 5, 8, 9, 10, 6 };
	cout << Solution().solve(2, data) << endl;
	return 0;
}
