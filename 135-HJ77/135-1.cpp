#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<string> getOut(stack<char> s, queue<char> data)
{
    vector<string> ret;

    if (data.empty()) {
        // 输入数据为空
        string tmp;
        while (!s.empty()) {
            tmp.push_back(s.top());
            s.pop();
        }
        ret.push_back(tmp);
    } else if (s.empty()) {
        // 输入数据不空，但是s空时
        s.push(data.front());
        data.pop();
        ret = getOut(s, data);
    } else {
        // 输入栈均不为空时
        // 1. 元素出栈输出
        stack<char> s_1 = s;
        queue<char> q_1 = data;
        char show = s_1.top();
        s_1.pop();
        vector<string> ret_1 = getOut(s_1, q_1);
        for (string& i : ret_1) {
            i.insert(i.begin(), show);
        }
        ret.insert(ret.begin(), ret_1.begin(), ret_1.end());
        // 2. 不出栈接着输入元素
        stack<char> s_2 = s;
        queue<char> q_2 = data;
        s.push(q_2.front());
        q_2.pop();
        vector<string> ret_2 = getOut(s_2, q_2);
        ret.insert(ret.begin(), ret_2.begin(), ret_2.end());
    }

    return ret;
}

int main()
{
    int n;
    while (cin >> n) {
        queue<char> data;
        for (size_t i = 0; i < n; i++) {
            char x;
            cin >> x;
            data.push(x);
        }
        stack<char> s;
        vector<string> output = getOut(s, data);
        sort(output.begin(), output.end());
        for (const string& i : output) {
            for (const char& j : i) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}