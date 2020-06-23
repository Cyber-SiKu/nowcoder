#include <cmath>
#include <iostream>
using namespace std;
int getlength(int num)
{
    int len = 0;
    while (num > 0) {
        ++len;
        num /= 10;
    }
    return len;
}
long getCount(int num)
{
    if (num < 1)
        return 0;
    int len = getlength(num);
    if (len == 1)
        return 1;
    long tmp = pow(10, len - 1);
    int first = num / tmp;
    int fcount = first == 1 ? num % tmp + 1 : tmp;
    long othercount = first * (len - 1) * (tmp / 10);
    return fcount + othercount + getCount(num % tmp);
}
int main()
{
    int num;
    long ans;
    cin >> num;
    ans = getCount(num);
    cout << ans << endl;
    return 0;
}