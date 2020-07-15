/**
 * 运行时间：3ms
 * 占用内存：412k
 * 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> prime = { 1, 2, 3, 5, 7 }; // 保存10以内的素数

public:
    /**
     * 
     * @param x string字符串 字符串从前到后分别是从上到下排列的n张扑克牌
     * @return string字符串
     */
    string Orderofpoker(string x);
};

string Solution::Orderofpoker(string x)
{
    string ret;
    int begin = 0, end = x.size() - 2;
    size_t i = x.size() / 2; // i 表示当前剩余牌数
    size_t pos = prime.size() - 1; // 保存比当前牌数小的最大素数的位置
    while (this->prime[pos] > i) {
        pos--;
    }

    for (; i > 0; i--) {
        if (i == this->prime[pos]) {
            // 当前牌数是素数
            pos--;
            ret.insert(ret.end(), x.begin() + begin, x.begin() + begin + 2);
            begin += 2;
        } else {
            // 当前牌数是非素数
            ret.insert(ret.end(), x.begin() + end, x.begin() + end + 2);
            end -= 2;
        }
    }
    return ret;
}

int main(int argc, char* argv[])
{
    string s;
    cin >> s;
    cout << Solution().Orderofpoker(s) << endl;
    return 0;
}
