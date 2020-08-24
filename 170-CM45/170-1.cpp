#include <bits/stdc++.h>

using namespace std;

bool comStr(string a, string b)
{
    return a > b;
}

class Permutation
{
public:
    vector<string> getPermutation(string A)
    {
        // write code here
        vector<string> ret;
        sort(A.begin(), A.end());
        int T[26] = {0};
        for (int k = 0; k < A.length(); k++)
        {
            T[A[k] - 'A'] += 1;
        }
        int n = 1;
        for (int k = 0; k < 26; k++)
        {
            if (T[k] > 0)
                n *= T[k];
        }
        do
        {
            for (int k = 0; k < n; k++)
            {
                ret.push_back(A);
            }
        } while (next_permutation(A.begin(), A.end()));
        sort(ret.begin(), ret.end(), comStr);
        return ret;
    }
};

int main()
{
    string str("ABC");
    vector<string> out = Permutation().getPermutation(str);
    for (string i : out)
    {
        cout << i << endl;
    }

    return 0;
}