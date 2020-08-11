#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const int& a, const int& b)
{
    return a > b;
}

class Subset {
public:
    vector<vector<int>> getSubsets(vector<int> A, int n)
    {
        // write code here
        vector<vector<int>> ret;
        if (A.size() <= 1) {
            ret.push_back(A);
            return ret;
        }
        sort(A.begin(), A.end(), compare);
        // i 表示选取的首个元素的位置
        vector<int> A_copy(A.begin() + 1, A.end());
        vector<vector<int>> tmp = getSubsets(A_copy, n - 1);
        vector<vector<int>> tmp_copy = tmp;

        // [A[i]...]
        int value = A[0];
        for (vector<int> j : tmp) {
            j.insert(j.begin(), value);
            ret.push_back(j);
        }
        ret.push_back(vector<int>(1, value));
        for (vector<int> j : tmp_copy) {
            ret.push_back(j);
        }

        return ret;
    }
};

int main()
{
    Subset s;
    vector<int> data { 123, 456, 789 };
    vector<vector<int>> output = s.getSubsets(data, data.size());
    for (vector<int>& i : output) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}