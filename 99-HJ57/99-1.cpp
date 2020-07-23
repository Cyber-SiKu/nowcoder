#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string number1;
    string number2;
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
    out = "";
    if (number1[0] != '-' && number2[0] != '-') {
        if (number1.size() > number2.size()) {
            // 保证number1
            string tmp = number2;
            number2 = number1;
            number1 = tmp;
        }

        int plus = 0; // 用来保存进位
        size_t i = 0;
        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());
        for (; i < number1.size(); i++) {
            int sum = number1[i] - '0' + number2[i] - '0' + plus;
            out.push_back(sum % 10 + '0');
            plus = sum / 10;
        }
        for (; i < number2.size(); i++) {
            int sum = number2[i] - '0' + plus;
            out.push_back(sum % 10 + '0');
            plus = sum / 10;
        }
        if (plus != 0) {
            out.push_back(plus + '0');
        }
    }

    reverse(out.begin(), out.end());
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.number1 >> s.number2;
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
