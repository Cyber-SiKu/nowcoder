#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    const int MAXSIZE = 26;
    string key;
    string data;
    string encrypt;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    vector<char> map(MAXSIZE, 0);
    vector<bool> isused(MAXSIZE, false);
    int pos = 0;
    // 形成密钥
    for (char& i : key) {
        if (isupper(i)) {
            i = tolower(i);
        }
        int pos_i = i - 'a';
        if (isused[pos_i] == false) {
            /* 字符尚未使用 */
            isused[pos_i] = true;
            map[pos] = i;
            ++pos;
        }
    }
    for (size_t i = 0; i < isused.size(); ++i) {
        if (isused[i] == false) {
            /* 字符尚未使用 */
            map[pos] = i + 'a';
            ++pos;
        }
    }

    encrypt.clear();
    for (const char& i : data) {
        // if (i == ' ') {
        //     encrypt.push_back(i);
        //     continue;
        // }

        encrypt.push_back(map[i - 'a']);
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.encrypt;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.key;
    is >> s.data;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s << endl;
    }
    return 0;
}
