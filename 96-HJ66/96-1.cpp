#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    string input;
    string output;
    unordered_map<string, string> command2out;
    vector<string> command_list;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
    command2out["reset"] = "reset what";
    command_list.push_back("reset");

    command2out["reset board"] = "board fault";
    command_list.push_back("reset board");

    command2out["board add"] = "where to add";
    command_list.push_back("board add");

    command2out["board delet"] = "no board at all";
    command_list.push_back("board delet");

    command2out["reboot backplane"] = "impossible";
    command_list.push_back("reboot backplane");

    command2out["backplane abort"] = "install first";
    command_list.push_back("backplane abort");
}

Solution::~Solution()
{
}

void Solution::slove()
{
    output = "unkown command";
    regex re_space(" ");
    vector<string> commands(sregex_token_iterator(input.begin(), input.end(), re_space, -1), sregex_token_iterator());
    string command;
    if (commands.size() == 1) {
        // 一个字符串
        command = commands[0] + "[a-z]*";
    } else if (commands.size() == 2) {
        // 两个字符串
        command = commands[0] + "[a-z]* " + commands[1] + "[a-z]*";
    } else {
        // 字符串过多
        return;
    }

    regex re_command(command);
    vector<string> ans;
    for (string i : command_list) {
        if (regex_match(i, re_command)) {
            // 符合条件的命令
            ans.push_back(i);
        }
    }
    if (ans.size() == 1 && find(command_list.begin(), command_list.end(), ans[0]) != command_list.end()) {
        // 匹配的命令唯一,且存在
        output = command2out.at(ans[0]);
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.output;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    getline(is, s.input);
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
