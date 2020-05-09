#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int N, M;
    cin >> N >> M;
    vector<string> mobiles;
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        mobiles.push_back(tmp);
    }
    vector<string> substr;
    for (int i = 0; i < M; ++i) {
        string tmp;
        cin >> tmp;
        substr.push_back(tmp);
    }

    for (const string& i : substr) {
        int count = 0;
        for (const string& j : mobiles) {
            string::size_type pos = j.find(i);
            if (pos != string::npos) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}