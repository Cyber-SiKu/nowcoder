#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Stones {
public:
    vector<int> result(int A, int B, int n, vector<int> e, vector<int> a)
    {
        // write code here

        const long long inf = 0x3f3f3f3f3f3f3f3f;
        vector<vector<long long>> dp(n + 1, vector<long long>(200, inf));
        int sum = 0, ans;
        dp[n][0] = -inf;
        for (int i = n - 1; i >= 0; i--) {
            sum += a[i];
            for (int j = 0; j <= sum; j++) {
                long long Achoose = -(dp[i + 1][sum - j + 1] - 1) - e[i];
                long long Apass = max(1ll, dp[i + 1][j] + (e[i] + 1));
                dp[i][j] = min(Achoose, Apass);
                if (i == 0 && dp[i][j] <= A - B)
                    ans = j;
            }
        }
        return vector<int> { ans, sum - ans };
    }
};

int main(int argc, char* argv[])
{
    int A = 9, B = 0, n = 7;
    vector<vector<int>> data { { 66, 2, 6, 2, 8, 4, 3 }, { 7, 12, 65, 7, 4, 40, 15 } };

    vector<int> outs = Stones().result(A, B, n, data[0], data[1]);

    for (const int& i : outs) {
        cout << i << endl;
    }

    return 0;
}
