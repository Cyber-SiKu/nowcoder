#include <iostream>
#include <regex>

using namespace std;

int main() {
	string str;
	regex re(" ");
	while(getline(cin, str)) {
		vector<string> data(sregex_token_iterator(str.begin(), str.end(),re,-1),sregex_token_iterator());
		cout << data.rbegin()->size() << endl;
	}

	return 0;
}
