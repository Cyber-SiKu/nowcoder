#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int target[1000005];
bool visit[1000005];
int father[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans;
    int the_next;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cin >> target[i];
        father[target[i]]++;
    }

    for (int i = 1; i < n + 1; i++) {
        if (father[i] == 0) {
            visit[i] = true;
            ans++;
            the_next = target[i];
            while (!visit[the_next]) {
                visit[the_next] = true;
                the_next = target[the_next];
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        if (visit[i] || i == target[i])
            continue;
        visit[i] = true;
        ans++;
        the_next = target[i];
        while (!visit[the_next]) {
            visit[the_next] = true;
            the_next = target[the_next];
        }
    }
    cout << ans << endl;

    memset(visit, false, sizeof(visit));
    ans = 0;
    queue<int> line;
    for (int i = 1; i < n + 1; i++)
        if (father[i] == 0)
            line.push(i);
    int head;
    while (!line.empty()) {
        head = line.front();
        line.pop();
        visit[head] = true;
        ans++;
        the_next = target[head];
        if (!visit[the_next]) {
            visit[the_next] = true;
            the_next = target[the_next];
            father[the_next]--;
            if (father[the_next] == 0) {
                line.push(the_next);
            }
        }
    }

    int lens;
    for (int i = 1; i < n + 1; i++) {
        if (visit[i] || i == target[i])
            continue;
        visit[i] = true;
        lens = 1;
        the_next = target[i];
        while (!visit[the_next]) {
            lens += 1;
            visit[the_next] = true;
            the_next = target[the_next];
        }
        ans += (lens >> 1);
    }
    cout << ans << endl;
    return 0;
}
