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
LL n,x,y;
LL sx,sy,sa,sb;
int main() {
  debugMode();
  //Code here
  scanf("%lld",&n);
  rep(i, n) {
    scanf("%lld %lld",&x,&y);
    sx+=x, sy+=y;
  }
  rep(i, n) {
    scanf("%lld %lld",&x,&y);
    sa+=x, sb+=y;
  }
  printf("%lld %lld\n",(sx+sa)/(n),(sy+sb)/(n));
  return 0;
}