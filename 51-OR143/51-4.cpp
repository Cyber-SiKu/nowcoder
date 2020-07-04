/**
 * 直接保存所有的数是否含有即可
 * 
 * 大量的时间浪费在io上
 * 
 * 运行时间：2602ms
 * 占用内存：2296k
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

const int MAXSIZE = 100000+1;

int main(int argc, char* argv[])
{
    int m, n;
    cin >> m >> n;
    vector<bool> data(MAXSIZE, false);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            int x;
            cin >> x;
            data[x] = true;
        }
    }
    int k;
    cin >> k;
    if (data[k] == true)
    {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;
    
    return 0;
}