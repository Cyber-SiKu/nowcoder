#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     *
     * @param a int整型vector
     * @param b int整型vector
     * @return long长整型vector
     */
    vector<long> solve(vector<int>& a, vector<int>& b) {  
        sort(a.begin(), a.end());
        int n(a.size()), m(b.size());
        vector<long> ans(m);
        long s = 0;
        for (int i = 0, j = 0; i < m; i++) {
            s += b[i];
            ans[i] = long(n - j) * b[i];
            while (j < n && a[j] < s) 
                ans[i] -= s - a[j++];
        }
        
      return ans;
    }
};