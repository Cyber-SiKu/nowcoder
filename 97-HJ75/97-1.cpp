#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string str1;
    string str2;
    int out;

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
    if (str1.size() < str2.size()) {
        string tmp = str2;
        str2 = str1;
        str1 = tmp;
    }
    for (out = str2.size(); out > 2; --out) {
        for (size_t i = 0; i + out <= str2.size(); i++) {
            string sub_str = str2.substr(i, out);
            if (str1.find(sub_str) != string::npos) {
                // 存在这个字串
                return;
            }
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
    getline(is, s.str1);
    getline(is, s.str2);
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s << endl;
    return 0;
}
