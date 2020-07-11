#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    /* data */
public:
    Solution(const string& passwd);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const string& passwd)
{
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    return os;
}

int main(int argc, char* argv[])
{
    string passwd;
    cin >> passwd;
    Solution s(passwd);

    cout << s << endl;
    return 0;
}