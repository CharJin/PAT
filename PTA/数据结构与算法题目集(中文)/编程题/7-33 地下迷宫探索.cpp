// https://pintia.cn/problem-sets/15/problems/860
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, st, a, b, cnt = 0;
bool vis[N] = {false};
set<int> e[N];
void dfs(int s) {
    cnt++;
    vis[s] = true;
    printf("%d ", s);
    bool hasNext = false;
    for (auto it : e[s]) {
        if (!vis[it]) {
            dfs(it);
            printf("%d%s", s, s == st ? "" : " ");
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &st);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].insert(b);
        e[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(st);
            break;
        }
    }
    if (cnt != n) printf(" 0");
    return 0;
}