/**
 * 运行时间：35ms
 * 占用内存：8100k
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string change(string s)
    {
        // write code here
        string ret;
        string last;
        // int count = 0;
        for (const char& i : s) {
            if (i == 'a') {
                last += i;
            } else {
                // ret.push_back(i);
                ret += i;
            }
        }
        ret += last;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution().change("abcavv") << endl;

    return 0;
}
