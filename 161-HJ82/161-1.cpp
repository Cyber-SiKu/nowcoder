#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    while (cin >> str) {
        regex split("/");
        vector<string> number(sregex_token_iterator(str.begin(), str.end(), split, -1), sregex_token_iterator());
        int count = stoi(number[0]);
        vector<string> output;
        for (size_t i = 0; i < count; i++) {
            output.push_back("1/" + number[1]);
        }
        cout << output[0];
        for (size_t i = 1, e = output.size(); i < e; i++) {
            cout << "+" << output[i];
        }
        cout << endl;
    }

    return 0;
}
