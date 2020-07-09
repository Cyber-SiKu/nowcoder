/**
 * 运行时间：2ms
 * 占用内存：520k
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> outs;
    const int MINI = 10;

public:
    Solution(const vector<string>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<string>& data)
{
    for (const string& i : data) {
        if (i.size() < this->MINI) {
            outs.push_back(i);
        } else {
            string tmp;
            tmp.push_back(*i.begin());
            string num = to_string(i.size() - 2);
            tmp.insert(tmp.end(), num.begin(), num.end());
            tmp.push_back(*i.rbegin());
            this->outs.push_back(tmp);
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

int main(int argc, char* argv[])
{
    vector<string> data;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        string str;
        cin >> str;
        data.push_back(str);
    }

    Solution s(data);

    cout << s;
    return 0;
}