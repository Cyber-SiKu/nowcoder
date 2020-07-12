/**
 * 运行时间：3ms
 * 占用内存：376k
*/
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
    const int MAXDAY = 5;
    const int MAXCOURSE = 10;
    vector<pair<string, vector<string>>> outs;

public:
    Solution(const map<string, vector<string>>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const map<string, vector<string>>& data)
{
    for (size_t i = 0; i < MAXDAY; i++) {
        for (size_t j = 0; j < MAXCOURSE; j++) {
            string tmp;
            tmp.push_back(i + '0');
            tmp.push_back(j + '0');
            if (data.find(tmp) != data.end()) {
                if (data.at(tmp).size() > 1) {
                    /* 课程有冲突 */
                    outs.push_back(make_pair(tmp, data.at(tmp)));
                }
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    if (s.outs.size() == 0) {
        os << "YES";
    } else {
        for (const pair<string, vector<string>>& i : s.outs) {
            os << i.first;
            for (const string& j : i.second) {
                os << " " << j;
            }
            os << endl;
        }
    }

    return os;
}

int main(int argc, char* argv[])
{
    map<string, vector<string>> data;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        string day, course;
        cin >> day >> course;
        data[day].push_back(course);
    }

    cout << Solution(data);
    return 0;
}