#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

long str2int(string ip)
{
	regex re("\\.");
	vector<string> data(sregex_token_iterator(ip.begin(), ip.end(), re, -1), sregex_token_iterator());
	long ret = 0;
	for (const string& i:data) {
		ret = ret*256+stol(i);
	}
	return ret;
}
string int2str(long ip) {
	string ret;
	ret = to_string(ip%256);
	ip/=256;
	while(ip != 0) {
		ret.insert(0 ,1, '.');
		string tmp = to_string(ip%256);
		ret.insert(ret.begin(), tmp.begin(), tmp.end());
		ip/=256;
	}
	return ret;
}

int main()
{
	string ip_str;
	long ip_int;
	while (cin >> ip_str >> ip_int) {
		cout << str2int(ip_str) << endl;
		cout << int2str(ip_int) << endl;
	}
	return 0;
}
