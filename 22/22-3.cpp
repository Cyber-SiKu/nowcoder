/**
 * 函数 offset(n) 表示连续n个x下一个是y需要抵消多少次
 * 
 * 每消除一个xy 都会遗留下来一个yyx，所以前后x的数量不变，y增加1
 * 而到n+1时x要先消除offset(n)次形成xy...(连续的y)x...(连续的x)
 * 中间连续的y的数量为：offset(n)+1(原有一个y，消除了offset(n)次, 所以y增加了offset(n))
 * 后续x的数量显然为n (消除不增加x，然后每次+1)
 * 所以offset(n+1)=2*offset(n)+1
 * 
 * 运行时间：9ms
 * 占用内存：4448k
 * */

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    /* data */
    vector<long> vec_offset; // vec_offset[i]表示函数offset运算结果
    const int MAGIC_NUMBER = 1000000007;
    long number; // 记录数值

public:
    Solution(const string& str);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    // 表示连续n个x下一个是y需要抵消多少次
    int offset(int n);
};

Solution::Solution(const string& str)
    : number(0)
    , vec_offset { 0, 1, 3 }
{
    int count = 0;
    for (string::const_iterator i = str.cbegin(), e = str.cend(); i != e; i++) {
        if (*i == 'x') {
            // 当前元素 x
            count++;
        } else {
            // 当前元素为 y
            /* 前面count个x*/
            if (vec_offset.size() - 1 < count) {
                vec_offset.resize(count + 1, 0);
                this->number = (this->number + this->offset(count)) % MAGIC_NUMBER;
            } else {
                this->number = (this->number + vec_offset[count]) % MAGIC_NUMBER;
            }
            // 因为最后会保留count个x所以count无需清零
        }
    }
}

Solution::~Solution()
{
}

ostream&
operator<<(ostream& os, const Solution& s)
{
    os << s.number;
    return os;
}

int Solution::offset(int n)
{
    /**
     * 每消除一个xy 都会遗留下来一个yyx，所以前后x的数量不变，y增加1
     * 而到n+1时x要先消除offset(n)次形成xy...(连续的y)x...(连续的x)
     * 中间连续的y的数量为：offset(n)+1(原有一个y，消除了offset(n)次, 所以y增加了offset(n))
     * 后续x的数量显然为n (消除不增加x，然后每次+1)
     * 所以offset(n+1)=2*offset(n)+1
    */

    if (vec_offset[n] != 0) {
        // 数据已经保存
        return vec_offset[n];
    }
    // 数据尚未计算
    int tmp = (2 * offset(n - 1) + 1) % MAGIC_NUMBER;
    // 因为是递归计算所以直接push_back即可
    vec_offset[n] = tmp;
    return tmp;
    // return ((1 << n) + 1) % MAGIC_NUMBER;
}

int main(int argc, char* argv[])
{
    string str;
    cin >> str;

    Solution s(str);

    cout << s << endl;

    return 0;
}