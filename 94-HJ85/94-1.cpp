#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string in;
    int out;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    bool isSymmetric(string str);

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
    for (int i = in.size(); i >= 0; i--) {
        for (size_t j = 0; j + i <= in.size(); j++) {
            string sub_str = in.substr(j, i);
            if (isSymmetric(sub_str)) {
                out = sub_str.size();
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
    is >> s.in;
    return is;
}

bool Solution::isSymmetric(string str)
{
    bool ret = true;
    for (size_t i = 0, j = str.size() - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            ret = false;
            break;
        }
    }
    return ret;
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
