#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param n int整型
     * @param a int整型vector
     * @return int整型
     */
    static const int N = 1000001;
    int solve(int n, vector<int>& a)
    {
        // write code here
        const int MOD = 1000000007;
        int len = a.size();
        int count[N] = { 0 };
        int ans = 1;
        for (auto& k : a)
            count[k]++;
        if (n % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1 && count[i] != 2)
                    return 0;
                if (i % 2 == 0 && count[i] != 0)
                    return 0;
                if (i % 2 == 0)
                    ans = ans * 2 % MOD;
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    if (count[0] != 1)
                        return 0;
                } else {
                    if (i % 2 == 1 && count[i] != 0)
                        return 0;
                    if (i % 2 == 0 && count[i] != 2)
                        return 0;
                    if (i % 2 == 0)
                        ans = ans * 2 % MOD;
                }
            }
        }
        return ans;
    }
};