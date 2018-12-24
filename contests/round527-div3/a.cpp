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
int main() {
  debugMode();
  //Code here
  int n,k,s,t;
  scanf("%d",&t);
  while(t--) {
    scanf("%d %d",&n,&k);
    s = -1;
    rep(i, k) {
      s++;
      rep(j, n/k) {
        putchar((char)(s+'a'));
      }
    }
    rep(u, n%k) {
      putchar((char)(s+'a'));
    }
    printf("\n");
  }
  return 0;
}