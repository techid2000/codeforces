#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL n,l,cn,rs;
LL dp[20][20][2];
char nu[20];

LL f1(LL i,LL j,LL k) {
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if(i==l) {
        if(j<=3) return dp[i][j][k]=1;
        else return dp[i][j][k]=0;
    }
    LL d=nu[i]-'0';
    LL s=0;
    if(k==0) {
        for(LL p=0;p<=d;p++) {
            if(p==d) {
                s+=f1(i+1, p==0?j:j+1,0);
            } else {
                s+=f1(i+1, p==0?j:j+1,1);
            }
        }
    } else {
        for(LL p=0;p<=9;p++) {
            if(p==0){
                s+=f1(i+1, j, 1);
            } else {
                s+=f1(i+1, j+1, 1);
            }
        }
    }
    return dp[i][j][k]=s;
}
int main() {
    scanf("%lld",&n);
    while(n--) {
        rs = 0;
        scanf(" %s",nu);
        l=strlen(nu);
        memset(dp,-1,sizeof dp);
        rs -= f1(0,0,0);
        cn = 0;
        for(LL i=0;i<l;i++) {
            if(nu[i]!='0') {
                cn++;
            }
        }
        if(cn <= 3) rs++;
        scanf(" %s",nu);
        l=strlen(nu);
        memset(dp,-1,sizeof dp);
        rs += f1(0,0,0);
        printf("%lld\n",rs);
    }
    return 0;
}