/**
 * 暴力解法
 * 运行时间：4ms
 * 占用内存：488k
*/

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

using llong = long long;

class Solution {
private:
    // vector<char> ans_;

public:
    Solution(const vector<llong>& data);
    ~Solution();

    // 将 n 按位拆分 判断数字的快乐值并返回
    char judge(const llong& n);
    // friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<llong>& data)
{
    for (llong i : data) {
        // ans_.push_back(this->judge(i));
        cout << this->judge(i) << endl;
    }
}

Solution::~Solution()
{
}

char Solution::judge(const llong& n)
{
    char ret = 'G';
    llong copy = n;
    bool flag = false; // j记录是否有匹配的位
    while (copy != 0) {
        int one_pace = copy % 10;
        if (one_pace != 0) {
            /* 当前位不为0 */
            if (n % one_pace != 0) {
                // n 不可以整除当前位
                ret = 'H';
                if (flag == true) {
                    // 已有匹配的位置
                    break;
                }
            } else {
                // n 可以整除当前位
                flag = true;
                if (ret == 'H') {
                    // 已有不匹配的位置
                    break;
                }
            }
        } else {
            // 当前位置为0
            flag = true;
        }
        copy /= 10;
    }
    if (flag == false && ret == 'H') {
        // 一个匹配的位置都没有
        ret = 'S';
    }
    return ret;
}

// ostream& operator<<(ostream& os, const Solution& s)
// {
//     for (const char& i : s.ans_) {
//         os << i << endl;
//     }
//     return os;
// }

int main(int argc, char* argv[])
{
    int T;
    cin >> T;
    vector<llong> data;
    for (size_t i = 0; i < T; i++) {
        llong n;
        cin >> n;
        data.push_back(n);
    }

    Solution s(data);

    // cout << s;

    return 0;
}