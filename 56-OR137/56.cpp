#include <iostream>
using namespace std;
int ans[1001][1001] = { 0 }; //设立一个二维数组用来记录心仪情况
int main()
{
    int n = 0, m = 0, i = 0, j = 0, x = 0, max_wu = 0;
    cin >> n >> m;
    int t = m + n; //总共t个人
    for (i = 1; i <= n; i++) //先对男生，即数组的前n个进行数据的输入
    {
        cin >> j; //心仪j个人
        for (int k = 0; k < j; k++) //分别是 哪些个 女生进行标记
        {
            cin >> x;
            ans[i][n + x] = 1; //注意，在这里标记的时候，因为按照行来女生是在男生后面，列对称
        }
    }
    for (; i <= t; i++) //然后对女生的行数的数据进行输入
    {
        cin >> j;
        for (int k = 0; k < j; k++) {
            cin >> x;
            ans[i][x] = 1;
        }
    }
    for (i = 1; i <= t; i++) //从第一个人开始，进行最多心仪数的判断
    { //注意，对于每一个人来说，自己对对方心仪，对方也对自己心仪算作一次
        int temp = 0; //其它情况，即只要是单向的心仪也均算做一次
        int up_line = 0;
        if (i <= n) //如果目前是男生，则只考虑女生，使j调到女生第一个
        {
            j = n + 1;
            up_line = t;
        } else //如果目前是女生，则只考虑男生，调到男生第一个，且上限为最后一个男生
        {
            j = 1;
            up_line = n;
        }
        for (; j <= up_line; j++) {
            if (ans[i][j] == 1 || ans[j][i] == 1) {
                temp = temp + 1;
            }
        }
        if (max_wu < temp) //进行在线的最大舞曲次数的更新
        {
            max_wu = temp;
        }
    }
    cout << max_wu << endl; //最后输出最大的舞曲次数
    return 0;
}