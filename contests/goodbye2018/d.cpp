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
inline void debugMode() {
#ifndef ONLINE_JUDGE
  freopen("iofiles/in.txt","r",stdin);
  freopen("iofiles/out.txt","w",stdout);
#endif
}
const LL mod = 998244353;
LL n,a,b,c,sum,ans;

LL fact(LL x) {
  LL ret = 1;
  for(LL i=1;i<=x;i++) {
    ret*=i;
    ret%=mod;
  }
  return ret;
}
int main() {
  debugMode();
  //Code here
  scanf("%lld",&n);
  a=0ll,c=1ll;
  for(b=n;b>=1ll;b--) {
    sum += (((a*(b-1))%mod)*c)%mod;
    a++, c*=b;
    a%=mod;
    c%=mod;
  }
  ans = (fact(n)+sum)%mod;
  printf("%lld\n",ans);
  return 0;
}