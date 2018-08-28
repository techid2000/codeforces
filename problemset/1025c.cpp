#include <bits/stdc++.h>
using namespace std;
char s[200005];
int le,cnt,ma;
int main() {
    scanf(" %s",s);
    le = strlen(s);
    for(int i=0; i<le; i++) {
        s[i+le] = s[i];
    }
    for(int i=0; i<2*le; i++) {
        if(i>0 && s[i]!=s[i-1]) {
            cnt++;
            ma = max(ma, min(cnt,le));
        } else {
            cnt = 1;
            ma = max(ma, 1);
        }
    }
    printf("%d\n",ma);
    return 0;
}