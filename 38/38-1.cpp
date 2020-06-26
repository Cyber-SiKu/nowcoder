/**
 * 运行时间：4ms
 * 占用内存：480k
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    long min;
    string path;

public:
    Solution(const vector<vector<long>>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<vector<long>>& data)
{
    min = 0;
    for (const vector<long>& i : data) {
        long min_step = i[0];
        long min_pos = 0;
        for (size_t j = 1; j < 4; j++) {
            if (min_step > i[j]) {
                min_step = i[j];
                min_pos = j;
            }
        }
        this->min += min_step;
        switch (min_pos) {
        case 0:
            this->path.append("E");
            break;
        case 1:
            this->path.append("S");
            break;
        case 2:
            this->path.append("W");
            break;
        case 3:
            this->path.append("N");
            break;
        default:
            break;
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.min << endl
       << s.path << endl;
    return os;
}

int main(int argc, char* argv[])
{
    int T, n;
    cin >> T;
    for (int z = 0; z < T; z++) {
        cin >> n;
        vector<vector<long>> data(n, vector<long>(4, 0));
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < n; j++) {
                cin >> data[j][i];
            }
        }

        Solution s(data);

        cout << s;
    }

    return 0;
}