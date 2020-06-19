#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    /* data */
    vector<string> outs;

public:
    Solution(const vector<vector<int>>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    string AorB(int a, int b, int n);
};

Solution::Solution(const vector<vector<int>>& data)
{
    for (const vector<int>& i : data) {
        long result = pow(long(i[0]), long(i[1]));
        if (result < i[2]) {
            outs.push_back("A&B");
            continue;
        }
        outs.push_back(this->AorB(i[0], i[1], i[2]));
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

string Solution::AorB(int a, int b, int n)
{
    if (a >= n) {
    }
}

int main(int argc, char* argv[])
{
    int T;
    cin >> T;
    vector<vector<int>> data(T, vector<int>(3, 0));
    for (size_t i = 0; i < T; i++) {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    Solution s(data);

    cout << s << endl;
    return 0;
}