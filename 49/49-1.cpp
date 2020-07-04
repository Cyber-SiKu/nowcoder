/**
 * 运行时间：4ms
 * 占用内存：376k
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string outs;

public:
    Solution(const string& str);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    // 返回 str 是否对称
    bool symmetry(const string& str);
};

Solution::Solution(const string& str)
{
    int length = str.size();
    while (length > 1) {
        for (size_t i = 0, e_i = str.size(); i + length <= e_i; i++) {
            string substr = str.substr(i, length);
            if (this->symmetry(substr)) {
                outs = substr;
                return;
            }
        }
        length--;
    }
    outs.push_back(str[0]);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

bool Solution::symmetry(const string& str)
{
    bool ret = true;
    for (size_t i = 0, j = str.size() - 1; i <= j; i++, j--) {
        if (str[i] != str[j]) {
            ret = false;
            break;
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    string str;
    cin >> str;
    Solution s(str);

    cout << s << endl;
    return 0;
}