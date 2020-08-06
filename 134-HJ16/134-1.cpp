#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class good {
public:
    int v;
    int p;
    int q;
    good(int v, int p, int q)
        : v(v)
        , p(p)
        , q(q)
    {
    }
};

int maxValue(int n, const vector<good>& data, vector<int> position)
{
    vector<vector<int>> dp(position.size(), vector<int>(n / 10 + 1, 0));
    for (size_t i = 0; i < position.size(); ++i) {
        for (size_t j = data[position[i]].v / 10; j <= n / 10; j++) {
            /* 沿着上一个主件及附件寻找购买 i 后仍可以购买的方案 */
            vector<int> tmp;
            for (int k = i - 1; k >= 0; --k) {
                tmp.push_back(dp[k][j - data[position[i]].v / 10]);
                if (data[position[k]].q == -1) {
                    break;
                }
            }
            if (!tmp.empty()) {
                dp[i][j] = data[position[i]].v * data[position[i]].p;
                dp[i][j] += (*max_element(tmp.begin(), tmp.end()));
            } else if (data[position[i]].q == -1) {
                /* 当前位置位主件 */
                dp[i][j] = data[position[i]].v * data[position[i]].p;
            }
        }
    }

    return dp[position.size() - 1][n / 10];
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        vector<good> data;
        unordered_map<int, vector<int>> master_servent;
        for (size_t i = 0; i < m; i++) {
            int v, p, q;
            cin >> v >> p >> q;
            q--;
            data.push_back(good(v, p, q));
            if (q == -1 && master_servent.find(i) == master_servent.end()) {
                master_servent.insert(make_pair(i, vector<int>()));
            } else if (q != -1) {
                if (master_servent.find(q) == master_servent.end()) {
                    master_servent.insert(make_pair(q, vector<int>(1, i)));
                } else {
                    master_servent[q].push_back(i);
                }
            }
        }
        vector<int> position;
        for (const pair<int, vector<int>>& i : master_servent) {
            position.push_back(i.first);
            for (const int& j : i.second) {
                position.push_back(j);
            }
        }

        cout << maxValue(n, data, position) << endl;
    }

    return 0;
}