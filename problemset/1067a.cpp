//Author: techid2000
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a) for(int i=0;i<a;i++)
#define PII pair<int,int>
#define LL long long
#define minheap(x) x,vector<x>,greater<x>
#define X first
#define Y second
using namespace std;
const int mod = 998244353;

LL dp[2][205][2],ans;
int n,pre,now;
int a[200005];
void Mod(LL* x) {
    *x = ((*x % mod) + mod) % mod;
}

int main() {
    //Code here
    scanf("%d",&n);
    rep(i,n) {
        scanf("%d",a+i);
    }
    if(a[0]==-1) {
        foru(i, 1, 201) 
            dp[0][i][0] = 1ll;
    } else {
        dp[0][a[0]][0] = 1ll;
    }
    foru(j,1,201) {
        dp[0][j][0] += dp[0][j-1][0];
        Mod(&dp[0][j][1]);
    }
    foru(i, 1, n) {
        now = i % 2; pre = 1-now;
        memset(dp[now],0,sizeof dp[now]);
        if(a[i] == -1) {
            foru(j, 1, 201) {
                dp[now][j][1] = (dp[pre][200][1]-dp[pre][j-1][1]) + (dp[pre][j][0]-dp[pre][j-1][0]);
                dp[now][j][0] = dp[pre][j-1][0] + dp[pre][j-1][1];
                Mod(&dp[now][j][1]);
                Mod(&dp[now][j][0]);
            }
        } else {
            dp[now][a[i]][1] = (dp[pre][200][1]-dp[pre][a[i]-1][1]) + (dp[pre][a[i]][0]-dp[pre][a[i]-1][0]);
            dp[now][a[i]][0] = dp[pre][a[i]-1][0] + dp[pre][a[i]-1][1];
            Mod(&dp[now][a[i]][1]);
            Mod(&dp[now][a[i]][0]);
        }
        foru(j,1,201) {
            dp[now][j][0] += dp[now][j-1][0];
            dp[now][j][1] += dp[now][j-1][1];
            Mod(&dp[now][j][0]);
            Mod(&dp[now][j][1]);
        }
    }
    if(a[n-1] == -1) {
        ans = dp[(n-1)%2][200][1];
    } else {
        ans = dp[(n-1)%2][a[n-1]][1] - dp[(n-1)%2][a[n-1]-1][1];
    }
    // Mod(&ans);
    printf("%lld\n",ans);
    return 0;
}