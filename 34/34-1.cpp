/**
 * 运行时间：3ms
 * 占用内存：480k
*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Solution {
private:
    string out;
    regex pattern;

public:
    Solution(const string& str);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const string& str)
    // : pattern("([a,z]|[A,Z]|[|\\|]|^|_)*\d([a,z]|[A,Z]|[|\\|]|^|_)*")
    : pattern("\\d")
{
    this->out = regex_replace(str, this->pattern, "");
    this->pattern = regex("\\$");
    this->out = regex_replace(out, this->pattern, "^");
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
    Solution s(str);

    cout << s << endl;
    return 0;
}