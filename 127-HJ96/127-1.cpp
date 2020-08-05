#include <iostream>
#include <string>

using namespace std;

string MarkNum(string pInStr) {
	bool numberContinue = false; // 记录是否是连续的数字
	for (int i = 0; i < pInStr.size(); ++i) {
		if (isdigit(pInStr[i]) == true && numberContinue == false) {
			// 当前字符为数字
			pInStr.insert(pInStr.begin() + i, '*');
			i++;
			numberContinue = true;
		} else if (isdigit(pInStr[i]) == false && numberContinue == true) {
			pInStr.insert(pInStr.begin() + i, '*');
			i++;
			numberContinue = false;
		}
	}
	if (numberContinue == true) {
		// 最后仍是数字
		pInStr.push_back('*');
	}
	return pInStr;
}

int main(int argc, char **argv) {
	string pInStr;
	while (cin >> pInStr) {
		cout << MarkNum(pInStr) << endl;
	}
	return 0;
}
