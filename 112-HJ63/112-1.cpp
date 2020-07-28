#include <iostream>
#include <string>

using namespace std;

double getGCRatio(const string& str)
{
    int GC_number = 0;
    for (const char& i : str) {
        if (i == 'G' || i == 'C') {
            ++GC_number;
        }
    }
    return double(GC_number) / double(str.size());
}

int main()
{
    string str;
    int len;
    while (cin >> str >> len) {
        double max_ratio = 0.0;
        string max_GC_str = "";
        for (size_t i = 0; i + len <= str.size(); ++i) {
            string subStr = str.substr(i, len);
            double subStr_GC = getGCRatio(subStr);
            if (subStr_GC > max_ratio) {
                max_ratio = subStr_GC;
                max_GC_str = subStr;
            }
        }

        cout << max_GC_str << endl;
    }

    return 0;
}