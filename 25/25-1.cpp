/**
 * 运行时间：3ms
 * 占用内存：488k
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    /* data */
    int miniTime;

public:
    Solution(const vector<vector<int>>& map, const int& end);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<vector<int>>& map, const int& end)
    : miniTime(-1)
{

    int start = 0;
    stack<vector<int>> reachable;
    reachable.push(vector<int> { start, 0 });

    while (!reachable.empty()) {
        vector<int> tmp = reachable.top();
        reachable.pop();
        for (const vector<int>& i : map) {
            if (i[0] == tmp[0]) {
                /* 可达点 */
                int time = i[2] + tmp[1];
                if (i[1] == end && (time < this->miniTime || this->miniTime == -1)) {
                    // 可达点的下一个节点是终点,并且用时更短
                    this->miniTime = time;
                } else {
                    // 下一个节点不是终点
                    vector<int> point;
                    point.push_back(i[1]);
                    point.push_back(time);
                    reachable.push(point);
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
    os << s.miniTime;
    return os;
}

int main(int argc, char* argv[])
{
    int end, N;
    cin >> end >> N;
    vector<vector<int>> map(N, vector<int>(3, 0));
    for (size_t i = 0; i < N; i++) {
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    }

    Solution s(map, end);

    cout << s << endl;
    return 0;
}