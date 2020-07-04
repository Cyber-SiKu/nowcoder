/**
 * 直接保存所有的数是否含有即可
 * 
 * 大量的时间浪费在io上
 * 
 * 运行时间：821ms
 * 占用内存：5228k
*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAXSIZE = 100000+1;

int main(int argc, char* argv[])
{
    int m, n;
    scanf("%d %d", &m, &n);
    vector<bool> data(MAXSIZE, false);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            data[x] = true;
        }
    }
    int k;
    scanf("%d", &k);
    if (data[k] == true) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}