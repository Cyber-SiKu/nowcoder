#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while (cin >> str) {
        string output = "-1";
        for (size_t i = 0; i < str.size(); i++) {
            if (str.find_last_of(str[i]) == str.find_first_of(str[i])) {
                output = string(1, str[i]);
                break;
            }
        }
        cout << output << endl;
    }

    return 0;
}