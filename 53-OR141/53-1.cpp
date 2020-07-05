/**
 * 1. 密码只能由大写字母，小写字母，数字构成；----------------------
 * 2. 密码不能以数字开头；---------------------------------------
 * 3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种； ------
 * 4. 密码长度至少为8---------------------
 * 
 * 运行时间：4ms
 * 占用内存：376k
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> outs;
    const int mini_size = 8;

public:
    Solution(const vector<string>& passwrds);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    bool isValidPassword(const string& password);
};

Solution::Solution(const vector<string>& passwrds)
{
    for (const string& i : passwrds) {
        if (this->isValidPassword(i) == true) {
            outs.push_back("YES");
        } else {
            outs.push_back("NO");
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const string& i : s.outs) {
        os << i << endl;
    }

    return os;
}

bool Solution::isValidPassword(const string& password)
{
    if (password.size() < this->mini_size) {
        // 密码长度至少为8
        return false;
    }

    if (password[0] >= '0' && password[0] <= '9') {
        // 密码以数字开头
        return false;
    }

    int count = 0; // 标记有几种数字类型
    bool num = false, low = false, upper = false; // 数字 小写 大写
    bool ret = false;
    for (const char& i : password) {
        if (!num && i >= '0' && i <= '9') {
            // 数字
            count++;
            num = true;
        } else if (!low && i >= 'a' && i <= 'z') {
            // 小写字母
            count++;
            low = true;
        } else if (!upper && i >= 'A' && i <= 'Z') {
            // 大写字母
            count++;
            upper = true;
        }

        if (count >= 2) {
            // 够数
            ret = true;
            break;
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<string> passwords;
    for (size_t i = 0; i < n; i++) {
        string password;
        cin >> password;
        passwords.push_back(password);
    }

    Solution s(passwords);

    cout << s;
    return 0;
}