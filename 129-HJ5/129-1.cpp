#include <iostream>
#include <string>

using namespace std;

int hex2dec(string hex)
{
    int ret = 0;
    for (size_t i = 2; i < hex.size(); i++) {
        ret = ret * 16;
        if (hex[i] <= '9' && hex[i] >= '0') {
            ret += hex[i] - '0';
        } else {
            ret += (hex[i] - 'A' + 10);
        }
    }

    return ret;
}

int main()
{
    string hex;
    while (cin >> hex) {
        cout << hex2dec(hex) << endl;
    }
    return 0;
}