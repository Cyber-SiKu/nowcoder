#include <stdio.h>
int x(int N, int n, int pri);
int main()
{
    int i, m, n;
    scanf("%d", &i);
    int count;
    while (i > 0) {
        scanf("%d %d", &m, &n);
        count = x(m, n, m);
        printf("%d\n", count);
        i--;
    }
    return 0;
}

int x(int N, int n, int pri) //剩余，n个,先前
{
    int f;
    if (N >= pri)
        f = pri;
    else
        f = N;

    int count = 0;
    if (N == 0 || N == 1 || n == 1)
        return 1;

    while (f >= N - N * (n - 1) / n) {
        count += x(N - f, n - 1, f);
        f--;
    }
    return count;
}