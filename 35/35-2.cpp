#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int max_length;

public:
    Solution(string str1, string str2);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(string str1, string str2)
{
    if (str1.length() < str2.length()) {
        // 保证str1最长
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    max_length = 0;
    for (int i = str2.length(); i > 0; i--) {
        // 假设最长字串长度为 i
        for (int j = 0, e = str2.length(); j + i <= e; i++) {
            string sub = string(str2.begin() + j, str2.begin() + j + i);
            if (str1.find(sub) != str1.npos) {
                this->max_length = i;
                return;
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.max_length;
    return os;
}

int main(int argc, char* argv[])
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    Solution s(str1, str2);

    cout << s << endl;
    return 0;
}