#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

class Compare {
public:
	virtual bool operator()(int a, int b) = 0;
};

class Compare_less: public Compare{
public:
	bool operator() (int a, int b) {
		return a < b;
	}
};

class Compare_greater: public Compare{
public:
	bool operator() (int a, int b) {
		return a > b;
	}
};

int main()
{
	int n;
	map<int, function<bool(int,int)>> function;
	function[0] = Compare_less();
	function[1] = Compare_greater();
	while (cin >> n) {
		vector<int> data(n);
		for (int i = 0; i < n; ++i) {
			cin >> data[i];
		}
		int sortFlag = 0;
		cin >> sortFlag;
		sort(data.begin(), data.end(), function[sortFlag]);
//		if (sortFlag == 0) {
//			sort(data.begin(), data.end(), less<int>());
//		} else {
//			sort(data.begin(), data.end(), greater<int>());
//		}
		for (int i = 0; i < data.size(); ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
