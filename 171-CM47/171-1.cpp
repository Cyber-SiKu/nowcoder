#include <bits/stdc++.h>

using namespace std;

class Flood
{
public:
    int floodFill(vector<vector<int>> map, int n, int m)
    {
        // write code here
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = 0;
        for (size_t i = 1; i < m; i++)
        {
            if (map[0][i] == 0)
            {
                time[0][i] = i;
            }
            else
            {
                break;
            }
        }

        for (size_t i = 1; i < n; i++)
        {
            if (map[i][0] == 0)
            {
                time[i][0] = i;
            }
            else
            {
                break;
            }
        }

        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 1; j < m; j++)
            {
                time[i][j] = min(time[i - 1][j], time[i][j - 1]) + 1;
            }
        }
        return time[n - 1][m - 1];
    }
};

int main()
{
    return 0;
}