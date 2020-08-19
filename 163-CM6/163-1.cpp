/*
思路：第一步：先将矩阵以次对角线互换 （如果是逆时针则为主对角线） 
    第二步：交换第i行到第n-i-1行

*/
#include <iostream>
#include <vector>

using namespace std;

class Transform {
public:
    vector<vector<int>> transformImage(vector<vector<int>> mat, int n)
    {
        for (size_t i = 0; i < n - 1; i++) {
            for (size_t j = 0; j < n - i - 1; j++) {
                swap(mat[i][j], mat[n - j - 1][n - i - 1]);
            }
        }
        for (size_t i = 0; i < n / 2; i++) {
            for (size_t j = 0; j < n; j++) {
                swap(mat[i][j], mat[n - i - 1][j]);
            }
        }
        return mat;
    }
};

int main()
{
    vector<vector<int>> data { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
    vector<vector<int>> ret = Transform().transformImage(data, data.size());
    for (size_t i = 0; i < ret.size(); i++) {
        for (size_t j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}