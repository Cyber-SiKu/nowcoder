#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    static const double MIN;
    vector<int> data;
    int Target;

    string out;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    bool ableGetTaget(vector<int> data, const double target);

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

const double Solution::MIN = 0.000000001;

Solution::Solution(/* args */)
    : data(4, 0)
    , Target(24)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    if (this->ableGetTaget(this->data, double(this->Target)) == true) {
        out = "true";
    } else {
        out = "false";
    }
}

bool Solution::ableGetTaget(vector<int> data, const double target)
{
    if (data.size() == 0) {
        return target <= Solution::MIN && target >= -Solution::MIN;
    }

    bool ret = false;
    for (size_t i = 0; i < data.size(); i++) {
        vector<int> tmp(data.begin(), data.begin() + i);
        tmp.insert(tmp.end(), data.begin() + i + 1, data.end());

        // +
        if (ableGetTaget(tmp, target - double(data[i])) == true) {
            ret = true;
            break;
        }

        // -
        if (ableGetTaget(tmp, target + double(data[i])) == true) {
            ret = true;
            break;
        }

        // ×
        if (ableGetTaget(tmp, target / double(data[i])) == true) {
            ret = true;
            break;
        }

        // /
        if (ableGetTaget(tmp, target * double(data[i])) == true) {
            ret = true;
            break;
        }
    }
    return ret;
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    for (size_t i = 0; i < 4; i++) {
        is >> s.data[i];
    }
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s << endl;
    }
    return 0;
}
