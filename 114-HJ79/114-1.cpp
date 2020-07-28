#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string A, B;
    while (cin >> A >> B) {
        string out = "1/";
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (size_t i = 1; i <= m; ++i) {
            dp[0][i] = i;
        }
        for (size_t i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                vector<int> tmp;
                tmp.push_back(dp[i - 1][j] + 1);
                tmp.push_back(dp[i][j - 1] + 1);
                if (A[i] == B[j]) {
                    tmp.push_back(dp[i - 1][j - 1]);
                } else {
                    tmp.push_back(dp[i - 1][j - 1] + 1);
                }
                dp[i][j] = *min_element(tmp.begin(), tmp.end());
            }
        }
        out += to_string(dp[n][m] + 1);
        cout << out << endl;
    }
    return 0;
}