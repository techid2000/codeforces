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
const int N = 200005;
int n,a1[N],a2[N],ch[N],now;
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  foru(i,1,n+1) {
    scanf("%d%d",&a1[i],&a2[i]);
  }
  if(n==3) {
    printf("1 2 3");
    return 0;
  }
  now=1;
  rep(i,n) {
    if(!ch[now]) {
      ch[now]=1;
      printf("%d ",now);
      auto x=a1[now],y=a2[now];
      if(a1[y]==x || a2[y]==x) {
        swap(x,y);
      }
      if(!ch[x]) {
        ch[x]=1;
        printf("%d ",x);
      }
      now=y;
    }
  }
  return 0;
}