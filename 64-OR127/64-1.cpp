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

Solution::Solution(const vector<int>& data)
{
    for (size_t i = 0, e = data.size(); i < e; i++) {
        bool no_multiple = true;
        if (data[i] == 0) {
            continue;
        }
        for (size_t j = 0; j < e; j++) {
            if ((data[j] / data[i]) * data[i] == data[j]) {
                if (i == j) {
                    continue;
                }
                no_multiple = false;
                break;
            }
        }
        if (no_multiple == true) {
            outs.push_back(data[i]);
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.outs) {
        os << i << " ";
    }

    return os;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> data(n);
    for (size_t i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << Solution(data) << endl;
    return 0;
}