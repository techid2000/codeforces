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
LL n,m;
set<LL>p,S;
int main() {
  debugMode();
  //Code here
  scanf("%lld",&n);
  m = n;
  foru(i,1,sqrt(n)+1) {
    if(n%i==0) {
      p.insert(1ll*i);
      p.insert(1ll*n/i);
    }
  }
  for(auto y:p) {
    auto N=1ll*(n-1)/y+1;
    S.insert(1ll*N*(2+(N-1)*y)/2);
  }
  for(auto y:S) {
    printf("%lld ",y);
  }
  return 0;
}