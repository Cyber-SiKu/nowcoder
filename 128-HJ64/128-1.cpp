#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, int> char_vlaue;

int getPosition(int pos, int n, string commands) {
	for (int i = 0, e = commands.size(); i < e; ++i) {
		pos = char_vlaue[commands[i]] + pos;
		if (pos == 0) {
			pos = n;
		}
		if (pos > n) {
			pos = 1;
		}
	}

	return pos;
}

pair<int, int> getList(pair<int, int> list, int pos, int n, string commands) {
	for (int i = 0, e = commands.size(); i < e; ++i) {
		pos = char_vlaue[commands[i]] + pos;
		if (pos == 0) {
			pos = n;
			list.second = n;
			list.first = max(1, n - 3);
		}
		if (pos > n) {
			pos = 1;
			list.first = 1;
			list.second = min(n, 4);
		}
		if (pos > list.second) {
			list.first++;
			list.second++;
		}
		if (pos < list.first) {
			list.first--;
			list.second--;
		}
	}

	return list;
}

void showList(int start, int end) {
	for (int i = start; i <= end; ++i) {
		cout << i << " ";
	}
}

int main() {
	int n;
	char_vlaue['U'] = -1;
	char_vlaue['D'] = 1;
	string commands;
	while (cin >> n) {
		cin >> commands;
		int pos = getPosition(1, n, commands);
		pair<int, int> list = getList(make_pair(1, min(4, n)), 1, n, commands);
		showList(list.first, list.second);
		cout << endl << pos << endl;
	}

	return 0;
}
