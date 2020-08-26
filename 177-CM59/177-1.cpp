class Rank {
public:
    vector<int> getRankOfNumber(vector<int> A, int n)
    {
        // write code here
        vector<int> ret(n, 0);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (A[j] <= A[i]) {
                    ++ret[i];
                }
            }
        }
        return ret;
    }
};