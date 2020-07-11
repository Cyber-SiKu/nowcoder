/**
 * 运行时间：9ms
 * 占用内存：476k
*/

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> outs;
    // forbidden[i] 周i限行尾号
    vector<vector<int>> forbidden {
        {},
        { 1, 9 }, // 1
        { 2, 8 }, // 2
        { 3, 7 }, // 3
        { 4, 6 }, // 4
        { 5, 0 }, // 5
        {}, {} // 6,7 不限
    };

    bool isForbidden(const string& license, const int& week) const;

public:
    Solution(const vector<string>& licenses, const int& week);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<string>& licenses, const int& week)
{
    for (const string& i : licenses) {
        if (i.size() != 5 || !regex_search(i, regex("\\d"))) {
            // 当长度不为5或者没有数字时
            outs.clear();
            outs.push_back("error");
            break;
        }

        if (Solution::isForbidden(i, week)) {
            outs.push_back(i);
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

bool Solution::isForbidden(const string& license, const int& week) const
{
    bool ret = true;
    vector<int> forbid = this->forbidden[week];
    int number;
    for (size_t i = license.size() - 1; i >= 0; i--) {
        if (license[i] >= '0' && license[i] <= '9') {
            number = license[i] - '0';
            break;
        }
    }

    if (find(forbid.begin(), forbid.end(), number) == forbid.end()) {
        /* 不限行 */
        ret = false;
    }

    return ret;
}

int main(int argc, char* argv[])
{
    string str;
    getline(cin, str);
    regex re(",");
    vector<string> license(sregex_token_iterator(str.begin(), str.end(), re, -1), sregex_token_iterator());
    int week;
    cin >> week;
    cout << Solution(license, week);
    return 0;
}