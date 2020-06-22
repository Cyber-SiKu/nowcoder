#include <stdio.h>
int main()
{
    int n, i, k, j = 0, a, temp;
    long int aa, b, c;
    scanf("%d", &n);
    scanf("%ld", &aa);
    int record[n];
    record[0] = 0;
    for (i = 0; i < n; i++) {
        scanf("%d %ld %ld\n", &a, &b, &c);
        if (aa >= b & aa <= c) {
            record[j] = a;
            j++;
        }
    }
    if (record[0] == 0)
        printf("null");
    else {
        for (i = 0; i < j; i++)
            for (k = i; k < j; k++) {
                if (record[i] > record[k]) {
                    temp = record[i];
                    record[i] = record[k];
                    record[k] = temp;
                }
            }
        for (i = 0; i < j; i++)
            printf("%d\n", record[i]);
    }
    return 0;
}