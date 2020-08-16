#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

long ip2Int(string ip) {
    regex split("\\.");
    vector<string> points(sregex_token_iterator(ip.begin(), ip.end(), split, -1), sregex_token_iterator());
    long ret = 0;
    for (string i : points) {
        ret = 256 * ret + stoi(i);
    }
    return ret;
}

int main() {
    string mask, ip1, ip2;
    while (cin >> mask >> ip1 >> ip2) {
        long mask_i = ip2Int(mask);
        long ip1_i = ip2Int(ip1);
        long ip2_i = ip2Int(ip2);
        bool ans = ((ip1_i & mask_i) == (ip2_i & mask_i));
        if (ans) {
            cout << 0 << endl;
        }else{
            cout << 2 << endl;
        }
    }
    return 0;
}
