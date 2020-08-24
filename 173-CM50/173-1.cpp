#include <bits/stdc++.h>

using namespace std;

class box
{
public:
    int w;
    int l;
    int h;
    box(int w, int l, int h) : w(w), l(l), h(h) {}
};

bool comparebox(box a, box b)
{
    if (a.w == b.w)
    {
        if (a.l == b.l)
        {
            return a.h > b.h;
        }
        else
        {
            return a.l < b.l;
        }
    }
    return a.w < b.w;
}

class Box
{
public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n)
    {
        // write code here
        vector<box> data;
        for (size_t i = 0; i < n; i++)
        {
            data.push_back(box(w[i], l[i], h[i]));
        }
        sort(data.begin(), data.end(), comparebox);
        vector<int> dp(n, 0);
        dp[0] = data[0].h;
        for (size_t i = 1; i < n; i++)
        {
            int j;
            for (j = i - 1; j >= 0; --j)
            {
                if (data[j].w < data[i].w && data[j].l < data[i].l)
                {
                    break;
                }
            }
            if (j >= 0)
            {
                dp[i] = dp[j] + data[i].h;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};

int main()
{
    vector<int> w{1, 1, 1};
    vector<int> l{1, 1, 1};
    vector<int> h{1, 1, 1};
    cout << Box().getHeight(w, l, h, 3) << endl;
    return 0;
}