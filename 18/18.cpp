#include <bits/stdc++.h>
using namespace std;

int n, m, Min = INT_MAX;

void F(int* a, vector<int> t, int d, int num)
{
    if (num == m) {
        vector<int> v;
        set<int> s;
        for (int i = 0; i < m; i++)
            s.insert(t[i]);
        for (int i = 0; i < n; i++) {
            if (s.find(a[i]) != s.end())
                s.erase(a[i]);
            else
                v.push_back(a[i]);
        }
        int sum = 0;
        for (int i = 0; i < t.size(); i++)
            for (int j = 0; j < v.size(); j++)
                sum += abs(t[i] - v[j]);
        Min = min(Min, sum);
        return;
    }
    for (int j = d; j < n; j++) {
        t.push_back(a[j]);
        F(a, t, j + 1, num + 1);
        t.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> t;
    F(a, t, 0, 0);
    cout << Min << endl;
    return 0;
}