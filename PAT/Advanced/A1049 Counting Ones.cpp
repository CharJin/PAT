#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int left = n / 10, right = 0, current = n % 10;
    for (int i = 1; right != n; i *= 10) {
        ans += left * i + (current == 0 ? 0 : current == 1 ? (right + 1) : i);
        right += current * i;
        current = left % 10;
        left /= 10;
    }
    printf("%d", ans);
    return 0;
}