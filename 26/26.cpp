#include <cstdio>
#include <unordered_map>
using namespace std;

int nums[100005];

void solve(int n)
{
    long long pre = 0;
    unordered_map<int, int> left, rite;
    for (int i = n - 1; i >= 0; --i)
        rite[nums[i]]++;
    for (int i = 0; i < n - 1; ++i) {
        printf("%lld%c", pre += n - 2 * i - rite[nums[i]] + left[nums[i]], i == n - 2 ? '\n' : ' ');
        rite[nums[i]]--;
        left[nums[i]]++;
    }
}

int main()
{
    int n, i = 0;
    for (scanf("%d", &n); i < n; ++i)
        scanf("%d", nums + i);
    solve(n);
}