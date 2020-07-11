/**
 * 运行时间：2ms
 * 占用内存：504k
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string out;
    static string score2string(const int& score);
    static int passwd2score(const string& passwd);

public:
    Solution(const string& passwd);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const string& passwd)
{
    int score = Solution::passwd2score(passwd);
    out = Solution::score2string(score);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;

    return os;
}

string Solution::score2string(const int& score)
{
    string ret;
    switch (score / 10) {
    case 9:
        ret = "VERY_SECURE";
        break;
    case 8:
        ret = "SECURE";
        break;
    case 7:
        ret = "VERY_STRONG";
        break;
    case 6:
        ret = "STRONG";
        break;
    case 5:
        ret = "AVERAGE";
        break;
    case 4:
    case 3:
    case 2:
        ret = "WEAK";
        break;
    default:
        break;
    }
    if (score < 25) {
        ret = "VERY_WEAK";
    }
    return ret;
}

int Solution::passwd2score(const string& passwd)
{
    int ret = 0;

    // 密码长度
    int length = passwd.size();
    if (length <= 4) {
        ret += 5;
    } else if (length <= 7) {
        ret += 10;
    } else {
        ret += 25;
    }

    // 字母 数字 符号
    int low = 0; // 小写字母的数量
    int upper = 0; // 大写字母的数量
    int number = 0; // 数字的数量
    int other = 0; // 符号的数量
    // 统计
    for (size_t i = 0; i < length; ++i) {
        if (passwd[i] >= '0' && passwd[i] <= '9') {
            ++number;
        } else if (passwd[i] >= 'a' && passwd[i] <= 'z') {
            ++low;
        } else if (passwd[i] >= 'A' && passwd[i] <= 'Z') {
            ++upper;
        } else {
            ++other;
        }
    }

    // 字母得分
    if (low != 0 && upper != 0) {
        // 大小写都有
        ret += 20;
    } else if (low * upper == 0 && (low != 0 || upper != 0)) {
        // 都是大（小）写
        ret += 10;
    }

    // 数字得分
    if (number == 1) {
        ret += 10;
    } else if (number > 1) {
        ret += 20;
    }

    // 符号得分
    if (other == 1) {
        ret += 10;
    } else if (other > 1) {
        ret += 25;
    }

    // 奖励分
    if ((low + upper) * number != 0) {
        // 数字+字母
        ret += 2;
    }
    if ((low + upper) * number * other != 0) {
        // 数字+字母+符号
        ret += 1;
    }

    if (low * upper * number * other != 0) {
        // 数字+大小写字母+符号
        ret += 2;
    }

    return ret;
}

int main(int argc, char* argv[])
{
    string passwd;
    cin >> passwd;
    cout << Solution(passwd) << endl;
    return 0;
}