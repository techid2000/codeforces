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
char s[200005];
int n,a,b,ch;
LL sum;
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  scanf(" %s",s+1);
  foru(i, 1, n+1) {
    if(i==n || s[i]!=s[i+1]) {
      a=i;
      break;
    }
  }
  ford(i, n, 0) {
    if(i==1 || s[i]!=s[i-1]) {
      b=i;
      break;
    }
  }
  if(s[a]==s[b]) {
    printf("%lld\n",(1ll*(a+1)*(n-b+2))%mod);
  } else {
    printf("%lld\n",(1ll*a+n-b+2)%mod);
  }
  return 0;
}