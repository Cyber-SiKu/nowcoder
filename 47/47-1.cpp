/**
 * 运行时间：3ms
 * 占用内存：360k
*/

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

using namespace std;

class Solution {
private:
    string outs;

public:
    Solution(const string& str);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const string& str)
{
    string::const_iterator start = str.cbegin();
    for (string::const_iterator i = start + 1, e_i = str.cend(); i != e_i; i++) {
        if (*i == *start) {
            continue;
        } else {
            // 出现不相同字符
            int length = i - start;
            if (length > 1) {
                // 连续相同字符数量大于1
                char c = *start;
                stringstream ss;
                ss << length - 1 << c;
                string tmp = ss.str();
                this->outs.insert(this->outs.end(), tmp.begin(), tmp.end());
                start = i;
            } else {
                this->outs.push_back(*start);
                start = i;
            }
        }
    }

    int length = str.end() - start;
    if (length > 1) {
        // 连续相同字符数量大于1
        char c = *start;
        stringstream ss;
        ss << length - 1 << c;
        string tmp = ss.str();
        this->outs.insert(this->outs.end(), tmp.begin(), tmp.end());
    } else {
        this->outs.push_back(*start);
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

int main(int argc, char* argv[])
{
    string str;
    // cin >> str;
    getline(cin, str);
    Solution s(str);

    cout << s << endl;
    return 0;
}