/**
 * 暴力解法:挨个试探
 * bug:题目理解错误
 * 20%
*/
#include <iostream>
#include <iterator>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

using map_i_v = unordered_map<int, vector<int>>;
using map_i_v_iter = unordered_map<int, vector<int>>::const_iterator;
using set_i = set<int>;

class Solution {
private:
    /* data */
    unsigned int paths;

public:
    Solution(const map_i_v& map, const map_i_v& re_map, set_i points);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const map_i_v& map, const map_i_v& re_map, set_i points)
    : paths(0)
{
    stack<vector<int>> stack_next; // 保存下一步可走的节点
    for (const int& point : points) {
        if (re_map.find(point) == re_map.end()) {
            // point 是一个起点城市
            vector<int> reachable = map.at(point);
            if (reachable.empty()) {
                /* 当前城市没有下一个可达城市 */
                // this->paths++;
                continue;
            }
            /* 当前城市有下一个可达城市 */
            stack_next.push(reachable);
            while (!stack_next.empty()) {
                reachable = stack_next.top();
                stack_next.pop();

                int next = *reachable.rbegin();
                reachable.pop_back();
                if (!reachable.empty()) {
                    stack_next.push(reachable);
                }

                // reachable = map.at(next);
                if (map.find(next) == map.end()) {
                    /* 下城市没有下一个可达城市 */
                    this->paths++;
                    continue;
                }
                reachable = map.at(next);
                stack_next.push(reachable);
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.paths;
    return os;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    map_i_v map; // map[i] 表示i能够到达的城市
    map_i_v re_map; // re_map[i] 表示能够到达i的城市
    set_i points;
    for (size_t i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        map[y].push_back(x);
        points.insert(x);
        re_map[x].push_back(y);
        points.insert(y);
    }

    Solution s(map, re_map, points);

    cout << s << endl;
    return 0;
}