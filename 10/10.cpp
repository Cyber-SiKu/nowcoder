#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
    typedef long long int64;
    struct cmp {
        vector<int> const& a;
        cmp(vector<int> const& A): a(A) {}
        bool operator()(int x, int y) const { return a[x] < a[y];}
    };
public:
    /**
     * 
     * @param n int整型 
     * @param k int整型 
     * @param a int整型vector 
     * @param b int整型vector 
     * @return long长整型
     */
    int64 solve(int n, int k, vector<int> const& a, vector<int>const& b) {
        // write code here
        vector<int> goods(n);
        for (int i = 0; i < n; i++) goods[i] = i;
        sort(goods.begin(), goods.end(), cmp(a));
        priority_queue<int64, vector<int64>, greater<int64> > h;
        for (int i = 0; i < n; i++) {
            while (h.size() && a[goods[i]] >= h.top()) 
                h.pop();
            if (h.size() < k) 
                h.push(b[goods[i]] + a[goods[i]]);
            else 
                h.push(b[goods[i]] + h.top()), h.pop();
        }
        while (h.size() > 1) h.pop();
        return h.top();
    }
};