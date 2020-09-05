
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

void trip0(string &s)
{ /* 去除字符串首的零 */
    while (!s.empty() && s[0] == '0')
        s.erase(s.begin());
}

string div_two(string s)
{ /* 大数除法 */
    string ans;
    int plus = 0; /* 这个是前一个数除后的余数 */
    for (int i = 0; i < s.length(); i++)
    {
        int now = plus * 10 + (s[i] - '0'); /* 当前的被除数转化成整数要加上前面的余数*10 */
        if (now >= 2)
        {                                       /* 如果当前被除数>=2的话，会留下余数 */
            ans.push_back(char(now / 2 + '0')); /* 得到的商 */
            plus = now % 2;                     /* 当前被除数除后的余数 */
        }
        else
        { /* 当前被除数小于2的话呢，商就是零，余数是本身 */
            ans.push_back('0');
            plus = now;
        }
    }
    trip0(ans); /* 去掉前导零，例如123/2，得到的是066 */
    return ans;
}

int main()
{
    string temp;
    while (cin >> temp)
    {
        string ans;
        trip0(temp);
        while (!temp.empty() && temp != "0")
        {
            int rail = (*(temp.end() - 1) - '0') % 2;
            ans.push_back(char(rail + '0'));
            temp = div_two(temp);
        }
        reverse(ans.begin(), ans.end());
        if (!ans.empty())
            cout << ans << endl;
        else
            printf("0\n");
    }
    return 0;
}