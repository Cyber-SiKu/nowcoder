#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int out;

public:
    Solution(const string& str);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const string& str)
{
    int count = 0; // 可以约减的字符串
    int count_R = 0;
    for (size_t i = 0, e = str.size(); i < e; ++i) {
        if (count_R == 0 && str[i] == 'L') {
            continue;
        } else if (str[i] == 'R' && str[i + 1] == 'R') {
            ++count_R;
            continue;
        } else {
            // 指向R+L+
            ++count_R;
            int count_L = 0;
            for (i = i + 1; i < e; i++) {
                if (str[i] == 'R') {
                    break;
                }
                ++count_L;
            }
            // R+L+的字符都可以消消除剩下一个R
            count += (count_R + count_L - 1);
            count_R = 1;
            if (i == e) {
                break;
            }
            --i;
        }
    }
    out = str.size() - count;
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}

int main(int argc, char* argv[])
{
    string str;
    cin >> str;
    cout << Solution(str) << endl;
    return 0;
}