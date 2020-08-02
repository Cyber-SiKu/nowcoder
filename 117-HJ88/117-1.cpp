#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string str;
    vector<string> play1;
    vector<string> play2;
    vector<string> out;
    map<string, int> key_value;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
    key_value["3"] = 0;
    key_value["4"] = 1;
    key_value["5"] = 2;
    key_value["6"] = 3;
    key_value["7"] = 4;
    key_value["8"] = 5;
    key_value["9"] = 6;
    key_value["10"] = 7;
    key_value["J"] = 8;
    key_value["Q"] = 9;
    key_value["K"] = 10;
    key_value["A"] = 11;
    key_value["2"] = 12;
}

Solution::~Solution()
{
}

void Solution::slove()
{

    regex re("-");
    vector<string> data(sregex_token_iterator(str.begin(), str.end(), re, -1), sregex_token_iterator());

    regex rews(" ");
    play1 = vector<string>(sregex_token_iterator(data[0].begin(), data[0].end(), rews, -1), sregex_token_iterator());
    play2 = vector<string>(sregex_token_iterator(data[1].begin(), data[1].end(), rews, -1), sregex_token_iterator());

    if (play1.size() < play2.size()) {
        swap(play1, play2);
    }

    if (play2.size() == 2) {
        if (play2[0] == "joker") {
            out = play2;
            return;
        }
        if (play1.size() == 2) {
            if (play1[0] == "joker") {
                out = play1;
                return;
            }
        }
        out = play1;
    }
    if (play1.size() > play2.size()) {
        if (play2.size() == 4) {
            out = play2;
            return;
        }
        if (play1.size() == 4) {
            out = play1;
            return;
        }
        out = vector<string>(1, "ERROR");
        return;
    }
    if (play1.size() == play2.size()) {
        out = key_value[play1[0]] >= key_value[play2[0]] ? play1 : play2;
        return;
    }
    out = vector<string>(1, "ERROR");
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out[0];
    for (size_t i = 1; i < s.out.size(); i++) {
        os << " " << s.out[i];
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    string str;
    getline(is, s.str);
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
