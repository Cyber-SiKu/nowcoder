#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class compare{
public:
	bool operator()(const pair<char, int> &a,const pair<char, int> &b){
		return a.second < b.second;
	}
};

string removeLestStr(string str)
{
	unordered_map<char, int> charCount;
	for (const char &i:str) {
		if (charCount.find(i) != charCount.end()){
			charCount[i]++;
		} else{
			charCount.insert(make_pair(i, 1));
		}
	}
	int minValue = min_element(charCount.begin(), charCount.end(),compare())->second;
	for (auto i = charCount.begin();i!=charCount.end();++i) {
		if (i->second == minValue) {
			int pos = str.find(i->first);
			while (pos != str.npos){
				str.erase(str.begin()+pos);
				pos = str.find(i->first);
			}
		}
	}
	return str;
}

int main()
{
	string str;
	while (cin >> str) {
		cout << removeLestStr(str) << endl;
	}
	return 0;
}
