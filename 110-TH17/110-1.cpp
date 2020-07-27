#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param a int整型vector 表示这棵完全二叉树的Bfs遍历序列的结点编号
     * @return long长整型
     */
    long long tree1(vector<int>& a)
    {
        // write code here
        long long ret = 0l;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            int left = pos * 2 + 1;
            if (left < a.size()) {
                q.push(left);
                ret += (a[pos] ^ a[left]);
            }
            int right = pos * 2 + 2;
            if (right < a.size()) {
                q.push(right);
                ret += (a[pos] ^ a[right]);
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> a { 1, 2, 3, 4, 5 };
    cout << s.tree1(a) << endl;
    return 0;
}
