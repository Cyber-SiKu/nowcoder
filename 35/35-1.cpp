/**
 * 运行时间：5ms
 * 占用内存：520k
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1005;

class Solution {
private:
    int max_length;

public:
    Solution(string str1, string str2);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(string str1, string str2)
{
    if (str1.length() < str2.length()) {
        // 保证str1最长
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    max_length = 0;

    vector<int> dp(MAX, 0);

    for (int i = 0, e_i = str1.size(); i < e_i; i++) {
        for (int j = str2.size() - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                dp[j + 1] = dp[j] + 1;
                max_length = max(max_length, dp[j + 1]);
            } else {
                dp[j + 1] = 0;
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.max_length;
    return os;
}

int main(int argc, char* argv[])
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    Solution s(str1, str2);

    cout << s << endl;
    return 0;
}