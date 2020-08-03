#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isMean(long n){
	if (n <= 3){
		return true;
	}
	bool ret = true;
	for (long i = 2; i <= sqrt(n);++i) {
		if(n % i != 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

vector<long> getMeanFactor(long n){
	vector<long> ret;
	while (n != 1) {
		long i = 2;
		while(n %i != 0) {
			++i;
		}
		ret.push_back(i);
		n /= i;
	}

	return ret;
}

int main(int argc, char **argv) {
	long n;
	while (cin >> n) {
		vector<long> data = getMeanFactor(n);
		for(const long i:data) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
