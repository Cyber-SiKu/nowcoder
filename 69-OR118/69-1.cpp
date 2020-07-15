/**
 * 算法思想：
 *  B = [1 1    , A_n = [a_{n+q}, a_n]
 *       1 0]
 * => A_{n+1} = A_n * B 
*/

#include <cstring>
#include <iostream>

using namespace std;

class Solution {
private:
    int k;
    int out;
    static const int LENGTH = 2;
    int A[LENGTH] = { 1, 1 };
    int B[LENGTH][LENGTH] = { { 1, 1 }, { 1, 0 } };

public:
    Solution(/* args */);
    ~Solution();
    void slove();
    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);

protected:
    static void mul(int A[], int B[][LENGTH]);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    int e = this->k - 1;
    for (size_t i = 0; i < e; i++) {
        mul(this->A, this->B);
    }

    out = A[1];
}

void Solution::mul(int A[], int B[][Solution::LENGTH])
{
    int tmp[Solution::LENGTH];
    memcpy(tmp, A, Solution::LENGTH * sizeof(int));
    memset(A, 0, sizeof(int) * Solution::LENGTH);
    for (size_t i = 0; i < Solution::LENGTH; i++) {
        for (size_t j = 0; j < Solution::LENGTH; j++) {
            A[i] += (B[j][i] * tmp[j]);
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.k;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s << endl;
    return 0;
}