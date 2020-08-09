#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> merge(vector<int> data_1, vector<int> data_2)
{
	data_1.insert(data_1.end(), data_2.begin(), data_2.end());
	sort(data_1.begin(), data_1.end());
	vector<int>::iterator end_un = unique(data_1.begin(), data_1.end());
	data_1.erase(end_un, data_1.end());
	return data_1;
}

int main()
{
	// data_1
	int n;
	while (cin >> n) {

		vector<int> data_1(n);
		for (size_t i = 0; i < n; ++i) {
			cin >> data_1[i];
		}

		// data_2
		int m;
		cin >> m;
		vector<int> data_2(m);
		for (size_t i = 0; i < m; ++i) {
			cin >> data_2[i];
		}

		vector<int> data_3 = merge(data_1, data_2);
		for (const int& i:data_3) {
			cout << i;
		}
		cout << endl;
	}

	return 0;
}
