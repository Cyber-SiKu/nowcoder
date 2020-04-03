/*
暴力算法：求出每个边的通信质量输出最大值
以每个顶点作为起点求到其他顶点的路径，每经过一个边通信质量加权值

BUG: 改成深度优先遍历
*/
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <utility>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::map;
using std::iterator;
using std::pair;

class Solution;

class Solution {
public:
    /**
     * 
     * @param n int整型 城市个数
     * @param u int整型vector 
     * @param v int整型vector 
     * @param w int整型vector 
     * @return long长整型
     */
    long long solve(int n, vector<int>& u, vector<int>& v, vector<int>& w);
    void convert(int n, vector<int>& u, vector<int>& v, vector<int>& w, \
           vector<vector<int>>& matrix);
    long long find_max(const  map<pair<int, int>, long long>& quality);
};


int main(int args, char* argv[]) {
    // 150
    int n = 5;
    vector<int> u = {1,4,5,4};
    vector<int> v = {5,1,2,3};
    vector<int> w = {9,25,30,8};

    // // 216
    // int n = 7;
    // vector<int> u = {7,1,4,6,5,3};
    // vector<int> v = {6,6,6,3,7,2};
    // vector<int> w = {8,15,36,9,30,3};

    Solution s;
    cout << s.solve(n, u, v, w) << endl;

    return 0;
}

void Solution::convert(int n, vector<int>& u, vector<int>& v, vector<int>& w, vector<vector<int>>& matrix) {
    for(int i = 0; i < n-1; ++i) {
        matrix[u[i]-1][v[i]-1] = matrix[v[i]-1][u[i]-1] = w[i];
    }
}

long long Solution::solve(int n, vector<int>& u, vector<int>& v, \
    vector<int>& w) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    map<pair<int, int>, long long> quality; // 记录每个边的通信质量

    convert(n,u,v,w,matrix);
        
    // 针对每一个顶点寻找其他节点的路径
    for(int i = 0; i < n; ++i) {
        // vector<vector<int>> temp = matrix;
        vector<bool> visited(n, false); // 记录顶点是否访问过
        queue<int> queue_point; // 保存访问的点
        queue<vector<int>> queue_path; // 保存路径
        vector<int> path = {i};

        queue_point.push(i);
        queue_path.push(path);
        visited[i] = true;
        // 遍历以i为起点可达的点
        while (!queue_point.empty()) {
            int pre = queue_point.front();
            queue_point.pop();

            // 广度优先遍历
            for(int j = 0; j < n; ++j) {
                // 寻找当前 i一步可达且未访问的点
                if (visited[j] == false && matrix[pre][j] != 0) {
                    // 入栈, 将顶点记录为已访问，更新边的通信质量
                    path = queue_path.front(); // 已经走过的路径
                    queue_point.push(j);
                    path.push_back(j);
                    queue_path.push(path);
                    visited[j] = true;
                }
            }

            path = queue_path.front(); // 已经走过的
            queue_path.pop();

            for (int k = 0, e = path.size()-1; k < e; k++) {
                // 更新每个边的通信质量
                map<pair<int, int>, long long>::iterator iter \
                    = quality.find(pair<int, int>(path[k], path[k+1]));
                if (iter != quality.end()) {
                    // 边访问过
                    iter->second += matrix[path[k]][path[k+1]];
                } else {
                   iter = quality.find(pair<int, int>(path[k+1], path[k]));
                   if (iter != quality.end()) {
                       // 边访问过
                        iter->second += matrix[path[k]][path[k+1]];
                   } else {
                       // 该边未访问
                       quality.insert\
                        (pair<pair<int, int>, long long>(pair<int, int>(path[k], path[k+1]), matrix[path[k]][path[k+1]]));
                   }
                }
            }
        }
        
    }

    return find_max(quality)/2;
}


long long Solution::find_max(const  map<pair<int, int>, long long>& quality) {
    int max = 0;
    for (pair<pair<int, int>, long long> i : quality) {
        max = max < i.second ? i.second:max; // max 取max和i.second最大值
    }
    
    return max;
}
