#include <iostream>
#include <vector>

using namespace std;

int getOut(vector<int> data)
{
	vector<vector<int>> dp_1(data.size(), vector<int>(2, 0));// dp_1[i][0]:出去，dp_1[i][1]留下
	dp_1[0][0] = 1;
	dp_1[0][1] = 0;
	for (int i = 1, e = data.size(); i < e; ++i) {
		dp_1[i][0] = min(dp_1[i - 1][0], dp_1[i - 1][1]) + 1;
		int pre;
		for (pre = i - 1; pre >= 0; pre--) {
			if (data[pre] < data[i]) {
				break;
			}
		}
		if (pre >= 0) {
			dp_1[i][1] = dp_1[pre][1] + pre - i - 1;
		} else {
			dp_1[i][1] = 1;
		}
	}

	vector<vector<int>> dp_2(data.size(), vector<int>(2, 0));// dp_1[i][0]:出去，dp_1[i][1]留下
	dp_2[0][0] = 1;
	dp_2[0][1] = 0;
	for (int i = 1, e = data.size(); i < e; ++i) {
		dp_2[i][0] = min(dp_2[i - 1][0], dp_2[i - 1][1]) + 1;
		int pre;
		for (pre = i - 1; pre >= 0; pre--) {
			if (data[pre] > data[i]) {
				break;
			}
		}
		if (pre >= 0) {
			dp_2[i][1] = dp_2[pre][1] + pre - i - 1;
		} else {
			dp_2[i][1] = 1;
		}
	}

	int min_pos = 0;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> data(n);
		for (int i = 0; i < n; ++i) {
			cin >> data[i];
		}
		cout << getOut(data) << endl;
	}
	return 0;
}
