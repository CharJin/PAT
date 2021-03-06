// https://pintia.cn/problem-sets/14/problems/806
#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int pos = 0;
    while (s[pos] == ' ') pos++;
    s = s.substr(pos, s.length() - pos);
    if (s.length() == 1) return 0;
    int cnt = 0;
    bool isfirst = true, isoutput = false;
    for (int i = 0; i <= s.length() - 2; i++) {
        if (s[i] == ' ') {
            if (!isoutput) {
                if (isfirst) {
                    printf("%d", cnt);
                    isfirst = false;
                } else
                    printf(" %d", cnt);
                cnt = 0;
                isoutput = true;
            }
        } else {
            isoutput = false;
            cnt++;
        }
    }
    if (s[s.length() - 2] != ' ') {
        if (isfirst) printf("%d", cnt);
        else printf(" %d", cnt);
    }
    return 0;
}