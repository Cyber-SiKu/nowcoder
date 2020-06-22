#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> outs;

public:
    Solution(const vector<int>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

struct {
    bool operator()(int a, int b)
    {
        return a > b;
    }
} compare;

Solution::Solution(const vector<int>& data)
    : outs(data)
{
    for (size_t i = 0, e_i = outs.size(); i < e_i; i++) {
        for (size_t j = i, e_j = outs.size(); j < e_j; j++) {
            if (outs[i] < outs[j]) {
                int tmp = outs[i];
                outs[i] = outs[j];
                outs[j] = tmp;
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.outs) {
        os << i << endl;
    }
    return os;
}

int main(int argc, char* argv[])
{
    // srand(unsigned(time(NULL)));
    const int MAX = 10;
    vector<int> data(MAX, 0);
    for (size_t i = 0; i < MAX; i++) {
        data[i] = rand();
    }

    Solution s(data);

    cout << s;
    return 0;
}