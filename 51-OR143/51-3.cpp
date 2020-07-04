/**
 * 算法优化：
 *  1. new 占用时间过大 故对mn判断
 *  2. 改vector为 二维数组节省开辟内存的时间
 * 运行时间：2214ms
 * 占用内存：35584k
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAXSIZE = 3000;

int data[MAXSIZE][MAXSIZE];

class Solution {
private:
    string outs;

public:
    Solution(const int& m,const int& n, const int& k);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    bool findk(const int *data, int end, const int &k);
};

Solution::Solution(const int& m,const int& n, const int& k)
{
    outs = "false";
    for (size_t i = 0; i < m; i++) {
        if (data[i][n-1] < k) {
            continue;
        }
        
        if (data[i][0] > k) {
            break;
        }
        if (this->findk(*(data+i), n-1, k) == true)
        {
            outs = "true";
            break;
        }
                
    }
    
}

bool Solution::findk(const int * data, int end, const int &k)
{
    bool ret = false;
    int begin = 0;
    while (begin <= end) {
        int midle = (begin+end)/2;
        if (data[midle] == k){
            ret = true;
            break;
        } else if (data[midle] < k) {
            begin = midle;
        } else {
            end = midle;
        }
        
    }
    return ret;
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

int main(int argc, char* argv[])
{
    int m, n;
    cin >> m >> n;

    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            int x;
            cin >> x;
            data[i][j] = x;
        }
    }
    int k;
    cin >> k;
    Solution s(m, n, k);
    cout << s << endl;

    return 0;
}