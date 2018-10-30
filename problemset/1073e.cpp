#include <bits/stdc++.h>
#define F first
#define S second
#define LL long long
using namespace std;

LL x, k;
LL L,R,res;
LL au[22];
pair <LL, LL> dp[22][1222][2][2];
const LL MOD = 998244353;

LL onecount(LL u) {
    if(u == 0) return 0;
    return (u%2 == 1) + onecount(u/2);
}

bool undef(pair<LL,LL> *p) {
    return (*p).F == -1 && (*p).S == -1;
}

pair<LL, LL> f(LL i,LL j,LL u,LL c) {
    if(onecount(j)>k)
        return dp[i][j][u][c] = {0,0};
    if(i==0) {
        if(onecount(j)<=k && u==1 && c==1)return dp[i][j][u][c] = {1,0};
        else return dp[i][j][u][c] = {0,0};
    }
    if(!undef(&dp[i][j][u][c])) return dp[i][j][u][c];
    LL d, inv;
    long long way = 0ll, sum = 0ll;
    pair <LL, LL> surf;
    if(u == 0) {
        for(d = 0; d <= 9; d++) {
            inv = (j | (1 << d));
            if(d < au[i]) {
                surf = f(i-1, inv, 1, (i-1==0 && d>0));   
                way += surf.F;
                sum += (surf.S*10 + surf.F*d);
                way %= MOD, sum %= MOD;
            }
            if(i>1 && d > 0) {
                surf = f(0,inv,1,1);
                way += surf.F;
                sum += (surf.S*10 + surf.F*d);
                way %= MOD, sum %= MOD;
            }
            surf = f(i-1,inv,0,(i-1==0 && d > 0));
            way += surf.F;
            sum += (surf.S*10 + surf.F*d);
            way %= MOD, sum %= MOD;
        }
    } else {
        inv = (j | (1 << au[i]));
        surf = f(i-1, inv, 1, (i-1==0 && au[i]>0)); 
        way += surf.F;
        sum += (surf.S*10 + surf.F*au[i]);
        way %= MOD, sum %= MOD;
    }
    return dp[i][j][u][c] = make_pair(way, sum);
}

LL allsum(LL u) {
    fill_n(&dp[0][0][0][0],22*1222*2*2,make_pair(-1,-1));
    LL N = 0, i, tmp = u, bm = 0;
    while(u > 0) {
        au[++N] = u%10;
        bm |= (1 << (u%10));
        u/=10;        
    }
    for(i=1; i<=N/2; i++)
        swap(au[i], au[N-i+1]);
    pair<LL,LL> ans = f(N,0,0,0);
    return (ans.S + (onecount(bm)<=k?tmp:0))%MOD;
}

int main()
{
    scanf("%lld%lld%lld",&L,&R,&k);
    res = allsum(R)-allsum(L-1);
    res %= MOD;
    while(res < 0) res += MOD;
    printf("%lld\n",res);
    return 0;
}