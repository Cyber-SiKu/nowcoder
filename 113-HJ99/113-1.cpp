#include <iostream>
#include <vector>

using namespace std;

bool isAutomorphicNumber(int number)
{
    bool ret = true;
    long ans = number * number;

    while (number != 0) {
        if (number % 10 != ans % 10) {
            ret = false;
            break;
        }
        number /= 10;
        ans /= 10;
    }

    return ret;
}

int main()
{
    int n;
    vector<int> dp;
    while (cin >> n) {
        if (n >= dp.size()) {
            int start = dp.size();
            dp.resize(n + 1, 0);
            for (size_t i = start; i <= n; ++i) {
                dp[i] = dp[i - 1];
                if (isAutomorphicNumber(i)) {
                    ++dp[i];
                }
            }
        }
        cout << dp[n];
    }
    return 0;
}