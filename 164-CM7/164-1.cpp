#include <iostream>
#include <vector>

using namespace std;

class Clearer
{
public:
    vector<vector<int>> clearZero(vector<vector<int>> mat, int n)
    {
        vector<vector<int>> ret(mat);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    for (size_t k = 0; k < n; k++)
                    {
                        ret[i][k] = 0;
                    }
                    for (size_t k = 0; k < n; k++)
                    {
                        ret[k][j] = 0;
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> data{{1, 2, 3}, {0, 1, 2}, {0, 0, 1}};
    vector<vector<int>> ret = Clearer().clearZero(data, data.size());
    for (size_t i = 0; i < ret.size(); i++)
    {
        for (size_t j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}