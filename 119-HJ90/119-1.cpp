#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string IP;
    string out;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    out = "YES";
    regex re("\\.");
    vector<string> data(sregex_token_iterator(IP.begin(), IP.end(), re, -1), sregex_token_iterator());
    if (data.size() != 4) {
        out = "NO";
        return;
    }
    vector<int> number;
    for (const string& i : data) {
        number.push_back(stoi(i));
    }

    for (const int& i : number) {
        if (i < 0 || i > 255) {
            break;
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.IP;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s << endl;
    }
    return 0;
}
