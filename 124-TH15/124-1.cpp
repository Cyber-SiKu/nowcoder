#include <iostream>
#include <vector>
#include <string>

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
	}
};

int main(int argc, char **argv) {
	vector<int> data { 5, 4, 3, 2, 1, 2, 3, 4, 5 };
	cout << Solution().solve(5, data) << endl;
	data = vector<int> { 9, 11, 1, 12, 5, 8, 9, 10, 6 };
	cout << Solution().solve(2, data) << endl;
	return 0;
}
