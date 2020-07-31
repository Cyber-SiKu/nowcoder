#include <deque>
#include <iostream>

using namespace std;

class Solution {
private:
    const int MOD = 998244353;

public:
    /**
     * 返回可以被压缩为长度为 N 的不同消息的数量
     * @param N int整型 数据包的总字节数
     * @return int整型
     */
    int messageCount(int N)
    {
        // write code here
        if (N < 5)
            return 0;
        deque<int> q = { 0, 0, 0, 0, 1 };
        for (int i = 6; i <= N; i++) {
            int t = (q.back() + q.front()) % 998244353;
            q.push_back(t);
            q.pop_front();
        }
        return q.back();
    }
};

int main(int argc, char* argv[])
{
    Solution s;

    cout << s.messageCount(4) << endl;
    cout << s.messageCount(10) << endl;
    cout << s.messageCount(11) << endl;
    cout << s.messageCount(15) << endl;
    cout << s.messageCount(16) << endl;
    cout << s.messageCount(20) << endl;

    return 0;
}
