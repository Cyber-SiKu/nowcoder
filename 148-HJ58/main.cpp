#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getKMin(priority_queue<int, vector<int>, greater<int>> data, int k)
{
	vector<int> ret;
	for (int i = 0; i < k; ++i) {
		ret.push_back(data.top());
		data.pop();
	}
	return ret;
}

int main()
{
	int n, k;
	while (cin >> n >> k) {
		priority_queue<int, vector<int>, greater<int>> data;
		for (size_t i = 0; i < n; ++i) {
			int x;
			cin >> x;
			data.push(x);
		}
		vector<int> output = getKMin(data, k);
		for (size_t i = 0; i < output.size(); ++i) {
			cout << output[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
