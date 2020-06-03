/*
算法思想：
暴力算法：
挨个位置删除观察是否构成回文字符串
因为只有一个位置，所以当出现两个（对称分布）位置符合条件时，说明该串是回文串

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> strs;

public:
    Solution(const vector<string>& s);
    void slove();
    int position(const string& s); // 返回删掉字符的位置
    bool isPalindrome(const string& s); // 返回字符串是否是回文串

    ~Solution();
};

Solution::Solution(const vector<string>& s)
    : strs(s)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    for (string i : strs) {
        cout << position(i) << endl;
    }
}

int Solution::position(const string& s)
{
    int ret = -1;
    if (!this->isPalindrome(s)) {
        // 本身不是一个回文串
        for (size_t i = 0, count = s.length(); i < count; i++) {
            /* 按照位置依次h删减字串 */
            string tmp = s.substr(0, i) + s.substr(i + 1);
            if (isPalindrome(tmp)) {
                /* 删除该位置后是回文串 */
                ret = i;
                break;
            }
        }
    }
    return ret;
}

bool Solution::isPalindrome(const string& s)
{
    bool ret = true;
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        // 从两段向中间挤
        if (s[i] != s[j]) {
            ret = false;
        }
    }
    return ret;
}

int main(int argc, char* argv[])
{
    int T;
    cin >> T;
    vector<string> str(T);
    for (size_t i = 0; i < T; ++i) {
        cin >> str[i];
    }
    Solution s(str);
    s.slove();
    return 0;
}