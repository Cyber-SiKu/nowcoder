#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        int M, A, B, N, i, j;
        scanf("%d %d", &M, &A);
        printf("%d %d\n", M, A);
        for (i = 1; i < m; i++) {
            scanf("%d %d", &N, &B);
            if (N == M)
                continue;
            else {
                for (j = 1; j < N - M; ++j) {
                    printf("%d %d\n", M + j, A + ((B - A) / (N - M)) * j);
                }
                printf("%d %d\n", N, B);
                M = N;
                A = B;
            }
        }
    }
    return 0;
}
