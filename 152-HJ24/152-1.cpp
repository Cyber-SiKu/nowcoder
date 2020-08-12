#include <iostream>
#include <vector>

using namespace std;

int getOut(vector<int> data)
{
	// 计算向前最少出列的人数
	vector<int> dp_1(data.size(), 0);
	for (int i = 1; i < data.size(); ++i) {
		dp_1[i] = i; // 若前面的数都比当前的数大，则全部抛弃
		for (int j = i-1; j >= 0 ; --j) {
			if (data[j] < data[i]) {
				dp_1[i] = min(dp_1[j] + i-j-1, dp_1[i]);
			}
		}
	}

	vector<int> dp_2(data.size(), 0);
	for (int i = data.size()-2; i >= 0; --i) {
		dp_2[i] = data.size() - 1 - i; // 若后面的数都比当前的数大，则全部抛弃
		for (int j = i+1; j < data.size() ; ++j) {
			if (data[j] < data[i]) {
				dp_2[i] = min(dp_2[j] + j - i - 1, dp_2[i]);
			}
		}
	}

	int ret = data.size();
	for (int i = 0; i < data.size(); ++i) {
		ret = min(ret, dp_1[i]+dp_2[i]);
	}

	return ret;
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
