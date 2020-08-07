#include <iostream>
#include <regex>
#include <string>

using namespace std;

string Reverse(string sentence)
{
    regex re(" ");
    vector<string> data(sregex_token_iterator(sentence.begin(), sentence.end(), re, -1), sregex_token_iterator());
    string ret;

    for (string i : data) {
        i.push_back(' ');
        ret.insert(ret.begin(), i.begin(), i.end());
    }
    ret.pop_back();

    return ret;
}

int main()
{
    string str;
    while (getline(cin, str)) {
        cout << Reverse(str) << endl;
    }

    return 0;
}