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
        int count = 0;
        for (const char& i : s) {
            if (i == 'a') {
                count++;
            } else {
                // ret.push_back(i);
                ret += i;
            }
        }
        for (size_t i = 0; i < count; i++) {
            // ret.push_back('a');
            ret += 'a';
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution().change("abcavv") << endl;

    return 0;
}
