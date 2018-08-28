#include <bits/stdc++.h>
using namespace std;
int a[4100][1210];
int cnt[4100];
int n,m,q,b,k,ti,tj;
int w[13];
char s[13];
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<m;i++) {
        scanf(" %s",s);
        b = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                b+=(1<<(n-i-1));
            }
        }
        cnt[b]++;
    }
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<(1<<n);j++) {
            b = 0;
            ti = i, tj = j;
            for(int k=n-1; k>=0; k--) {
                if((tj%2) == (ti%2)) {
                    b += w[k];
                }
                ti/=2;
                tj/=2;
            }
            a[i][b] += cnt[j];
        }
    }
    for(int i=0;i<(1<<n);i++) {
        for(int j=1; j<1210; j++) {
            a[i][j] += a[i][j-1];
        }
    }
    while(q--) {
        scanf(" %s %d",s,&k);
        b = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                b+=(1<<(n-i-1));
            }
        }
        printf("%d\n",a[b][k]);
    }
    return 0;
}