#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const int MAX = 8;
    int n;
    while (cin >> n)
    {
        vector<string> input(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        vector<string> output;
        for (size_t i = 0; i < n; i++)
        {
            size_t j = 0;
            for (; j + MAX < input[i].size(); j += MAX)
            {
                string tmp(input[i].begin() + j, input[i].begin() + j + MAX);
                output.push_back(tmp);
            }
            string tmp(input[i].begin() + j, input[i].end());
            tmp.resize(MAX, '0');
            output.push_back(tmp);
        }

        for (size_t i = 0; i < output.size(); i++)
        {
            cout << output[i] << endl;
        }
    }

    return 0;
}