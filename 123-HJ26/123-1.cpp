#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <regex>

using namespace std;

string sort_str(string str) {
	// 冒泡算法改
	for (int i = 0; i < str.size(); ++i) {
		for (int j = 0; j < str.size(); ++j) {
			if (::isalpha(str[j]) != 0) {
				// 字母
				int next = j + 1;
				while (::isalpha(str[next]) == 0 && next != str.size()) {
					// 下一个字符不是字母,并且没到最后一个字符时
					++next;
				}
				if (next != str.size()
						&& ::tolower(str[j]) > ::tolower(str[next])) {
					// j 后面有字母， 并且小于当前字母,则交换
					swap(str[j], str[next]);
				}
			}
		}
	}
	return str;
}

int main(int argc, char **argv) {
	string input;
	while (getline(cin, input)) {
		string output;

		output = sort_str(input);

		cout << output << endl;
	}

	return 0;
}

