#include <bits/stdc++.h>
using namespace std;

int n,m,q,a,b;
char s[1005],t[1005];
int dp[1005];
int main() {
    scanf("%d%d%d",&n,&m,&q);
    scanf(" %s",s+1);
    scanf(" %s",t+1);
    for(int i=1; i<=n-m+1; i++) {
        if(!strncmp(&s[i],t+1,m)) {
            dp[i]=1;
        }
    }
    for(int i=1; i<=n; i++) {
        dp[i]+=dp[i-1];
    }
    while(q--) {
        scanf("%d%d",&a,&b);
        if(b-a+1 < m) printf("0\n");
        else printf("%d\n",dp[b-m+1]-dp[a-1]);
    }
    return 0;
}