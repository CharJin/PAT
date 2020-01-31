// https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int father[N];
int findFather(int x) {
    if (x == father[x]) return x;
    int fa = findFather(father[x]);
    father[x] = fa;
    return fa;
}
void uni(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, k, h;
    map<int, int> hobbyToId;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &h);
            if (hobbyToId[h] != 0) uni(i, hobbyToId[h]);
            else hobbyToId[h] = i;
        }
    }
    map<int, int> mcnt;
    for (int i = 1; i <= n; i++) mcnt[findFather(i)]++;
    vector<int> ans;
    for (auto it : mcnt) ans.push_back(it.second);
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}
/*
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};     // 标记是否为某结点的根, 并记录根节点的个数
int hobby[maxn] = {0};      // 标记某人的爱好, [index:爱好,value:人物编号]

bool cmp(int a, int b){
    return a > b;
}

int findFather(int x){
    if (x == father[x]) return x;
    else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB){
        father[faA] = faB;
    }
}

int main(){
    int n, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        father[i] = i;                      // 初始化所有结点父结点为自己
    }
    for (int i = 1; i <= n; i++){
        scanf("%d: ", &k);
        int h;
        for (int j = 0; j < k; j++){
            scanf("%d", &h);
            if (hobby[h] == 0){              // 如果该兴趣无人喜欢,
则令people.i喜欢该活动h hobby[h] = i;
            }
            Union(i, findFather(hobby[h])); // 合并
        }
    }
    for (int i = 1; i <= n; i++){
        isRoot[findFather(i)]++;            // 根节点数量+1,
表示某个集合内结点个数
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++){
        if (isRoot[i] > 0){
            ans.push_back(isRoot[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    int len = ans.size();
    printf("%d\n", len);
    for (int i = 0; i < len; i++){
        printf("%d", ans[i]);
        if (i < len - 1) printf(" ");
    }
    return 0;
}
*/