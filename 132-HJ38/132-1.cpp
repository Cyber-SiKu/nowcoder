#include <cmath>
#include <cstdio>

int main()
{
    int height;
    while (scanf("%d", &height)) {
        /* code */
        printf("%0.6f\n", double(height * 23) / 8.0);
        printf("%0.6f\n", double(height) / 32.0);
    }

    return 0;
}