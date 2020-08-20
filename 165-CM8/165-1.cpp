#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        // write code here
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

int main() {
    ReverseEqual r;
    cout << r.checkReverseEqual("Hello world", "worldhello ") << endl;
    cout << r.checkReverseEqual("waterbottle", "erbottlewat ") << endl;
    return 0;
}
