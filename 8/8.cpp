/**
 * 运行时间：123ms
 * 占用内存：10120k
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Point {
	int x;
	int y;
    Point(int x, int y): x(x), y(y) {}
};

class Solution {
public:
    /**
     * 能回到1号点返回 Yes，否则返回 No
     * @param param int整型vector param[0] 为 n，param[1] 为 m
     * @param edge Point类vector Point.x , Point.y 分别为一条边的两个点
     * @return string字符串
     */
    vector<vector<int>> adj;
    vector<bool> visit;
    int n, m;
    bool search(int cur, int pre)
    {
        if (cur == 0)
            return true;
        if (visit[cur])
            return false;
        visit[cur] = true;
        for (auto next : adj[cur])
        {
            if (next == pre)
                continue;
            if (search(next, cur))
                return true;
        }
          
        return false;
    }
      
    string solve(vector<int>& param, vector<Point>& edge) {
        n = param[0];
        m = param[1];
        adj = vector<vector<int>>(n);
        visit = vector<bool>(n, false);
        for (auto point : edge)
        {
            adj[point.x-1].push_back(point.y-1);
            adj[point.y-1].push_back(point.x-1);
        }
          
        for (auto next : adj[0])
        {
            if (search(next, 0))
                return "Yes";
        }
          
        return "No";
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    // vector<int> param = {4,4};
    // vector<Point> edge = {Point(1,2), Point(2, 3), Point(3,4), Point(4,1)};

    vector<int> param = {5,5};
    vector<Point> edge = {Point(1,2), Point(2,3),Point(3,4), Point(4,5), Point(5,2)};

    cout << s.solve(param, edge) << endl;
    return 0;
}