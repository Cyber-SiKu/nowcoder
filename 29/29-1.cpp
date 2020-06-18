/**
 * 算法思想：dfs
 * 
 * 时间复杂度过大
 * case通过率为45.45%
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
    double youyou;
    double mate;

public:
    Solution(const vector<int>& cost_time,
        const vector<int>& youyou_happiness,
        const vector<int>& mate_happiness,
        // const vector<vector<int>>& map,
        const unordered_map<int, vector<pair<int, int>>>& map,
        const int& k);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    double getHappiness(const vector<int>& cost_time,
        const vector<int>& happiness,
        // const vector<vector<int>>& map,
        const unordered_map<int, vector<pair<int, int>>>& map,
        const int& k);
};

Solution::Solution(const vector<int>& cost_time,
    const vector<int>& youyou_happiness,
    const vector<int>& mate_happiness,
    // const vector<vector<int>>& map,
    const unordered_map<int, vector<pair<int, int>>>& map,
    const int& k)
    : youyou(0.0)
    , mate(0.0)
{
    this->youyou = this->getHappiness(cost_time, youyou_happiness, map, k);
    this->mate = this->getHappiness(cost_time, mate_happiness, map, k);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << setiosflags(ios::fixed) << setprecision(5) << s.youyou << " " << s.mate;
    return os;
}

double Solution::getHappiness(const vector<int>& cost_time,
    const vector<int>& happiness,
    // const vector<vector<int>>& map,
    const unordered_map<int, vector<pair<int, int>>>& map,
    const int& k)
{
    stack<int> stack_point; // 保存下一步可达景点
    stack<int> stack_time; // 保存到下一个景点并游玩所需的时间
    stack<double> stack_able; // 保存下一步可达景点的概率
    double ret = 0.0;

    // vector<int> reachable;
    // for (size_t i = 1, e_i = cost_time.size(); i < e_i; i++) {
    //     if (cost_time[i] <= k) {
    //         reachable.push_back(i);
    //     }
    // }

    // int length = reachable.size();
    // double able = double(1.0) / double(length);
    // for (const int& i : reachable) {
    //     // 开始可以游玩的景点
    //     stack_point.push(i);
    //     stack_time.push(cost_time[i]);
    //     stack_able.push(able);
    //     ret += (able * double(happiness[i]));
    // }

    int length = cost_time.size() - 1;
    double able = 1.0 / double(length);
    for (size_t i = 1, e_i = cost_time.size(); i < e_i; i++) {
        // 开始可以游玩的景点
        stack_point.push(i);
        stack_time.push(cost_time[i]);
        stack_able.push(able);
        ret += (able * double(happiness[i]));
    }

    while (!stack_point.empty()) {
        // 有可以游玩的景点
        int point = stack_point.top();
        stack_point.pop();
        int time = stack_time.top();
        stack_time.pop();
        double able = stack_able.top();
        stack_able.pop();

        // 查找point 可达节点
        vector<pair<int, int>> reachable;
        for (const pair<int, int>& i : map.at(point)) {
            if (i.second + time + cost_time[i.first] <= k) {
                // 到达下一个景点可以接受
                reachable.push_back(i);
            }
        }

        int length = reachable.size();
        able *= (1.0 / double(length));
        for (const pair<int, int>& i : reachable) {
            stack_point.push(i.first);
            stack_time.push(i.second + time + cost_time[i.first]);
            stack_able.push(able);
            ret += able * double(happiness[i.first]);
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    int m, n, k;
    cin >> n >> m >> k;
    vector<int> cost_time(n + 1, 0);
    vector<int> youyou_happiness(n + 1, 0);
    vector<int> mate_happiness(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        cin >> cost_time[i] >> youyou_happiness[i] >> mate_happiness[i];
    }
    // vector<vector<int>> map(n, vector<int>(n, 0)); // 保存i可达点以及花费的时间
    unordered_map<int, vector<pair<int, int>>> map;
    for (size_t i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        // map[x][y] = t;
        // map[y][x] = t;
        map[x].push_back(pair<int, int>(y, t));
        map[y].push_back(pair<int, int>(x, t));
    }

    Solution s(cost_time, youyou_happiness, mate_happiness, map, k);

    cout << s << endl;
    return 0;
}