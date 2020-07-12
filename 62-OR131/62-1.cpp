/**
 * 运行时间：2ms
 * 占用内存：504k
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string out;

public:
    Solution(const string& input);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const string& input)
    : out(input)
{
    for (size_t i = 0, j = input.size() - 1; i < j; i++, j--) {
        if (out[i] != out[j]) {
            out[j] = out[i];
        }
    }
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
    string input;
    cin >> input;
    cout << Solution(input) << endl;
    return 0;
}