class Stack
{
public:
    int getHeight(vector<int> men, int n)
    {
        // write code here
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i)
        {
            int j = i - 1;
            for (; j >= 0; --j)
            {
                if (men[j] < men[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};