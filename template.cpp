#include <iostream>

using namespace std;

class Solution {
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(/* args */)
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
    Solution s;

    return 0;
}