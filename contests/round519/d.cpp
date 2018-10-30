#include <bits/stdc++.h>
using namespace std;

int n,m,i,j,a,b,con;
long long ans;
int f[100005];
map<pair<int,int>,int>ed;

int main() {
    scanf("%d%d",&n,&m);
    ans = n;
    for(i=0; i<m; i++) {
        if(i==0) {
            for(j=0;j<n;j++) {
                scanf("%d",&f[j]);
                if(j>0) ed[{f[j-1],f[j]}]++;
            }
        } else {
            scanf("%d",&b);
            for(j=1;j<n;j++) {
                scanf("%d",&a);
                ed[{b,a}]++;
                b=a;
            }
        }
    }
    for(i=1;i<n;i++) {
        if(ed[{f[i-1],f[i]}]!=m) {
            ans += (1LL)*(con)*(con+1)/2;
            con = 0;
        } else {
            con++;
        }
    }
    ans+=(1LL)*(con)*(con+1)/2;
    printf("%lld\n",ans);
    return 0;
}