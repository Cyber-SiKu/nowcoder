#include <bits/stdc++.h>
#include <regex>

using namespace std;

class Replacement {
public:
    string replaceSpace(string iniString, int length)
    {
        // write code here
        regex re(" ");
        string r("%20");
        string ret = regex_replace(iniString, re, r);
        return ret;
    }
};

int main()
{
    string str("1 2 3");
    cout << Replacement().replaceSpace(str, str.size()) << endl;
    return 0;
}