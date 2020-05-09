#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Access {
public:
    string path;
    char access;
    Access(char a, string p)
        : access(a)
        , path(p)
    {
    }
};

int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<string> paths;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        paths.push_back(tmp);
    }
    int T;
    cin >> T;
    vector<Access> access;
    for (int i = 0; i < T; i++) {
        string path;
        char a;
        cin >> a >> path;
        access.push_back(Access(a, path));
    }
    for (auto i : paths) {
        char ac = 'N'; // 找到
        string parent = "/";
        for (auto j : access) {
            if (j.path.size() > parent.size()) {
                string::size_type pos = i.find(j.path);
                if (pos == 0) {
                    if (i.size() > j.path.size() && i[j.path.size()] != '/') {
                        continue;
                    }
                    /* j是i的上级目录或是i */
                    ac = j.access;
                    parent = j.path;
                    if (i.size() == j.path.size()) { // 字符串相等
                        break;
                    }
                }
            } else if (j.path.size() == parent.size() && j.path.compare(parent) == 0) {
                // j 是 i 的上级目录
                ac = j.access;
            }
        }
        cout << ac << endl;
    }

    return 0;
}