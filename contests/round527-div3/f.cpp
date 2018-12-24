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
const LL Node=200005;
LL n,u,v,sum,Max;
vector<int>t[Node];
LL a[Node],A[Node],B[Node];
void dfs(LL x,LL p) {
  A[x]+=a[x];
  if(t[x].size()==1&&t[x][0]==p)
    return;
  for(auto y:t[x]){
    if(y==p)
      continue;
    dfs(y,x);
    A[x]+=A[y];
    B[x]+=B[y];
  }
  B[x]+=A[x]-a[x];
}
void dfs2(LL x,LL p,LL v,LL c) {
  Max = max(Max, v);
  for(auto y:t[x]) {
    if(y==p)
      continue;
    dfs2(y,x,v+(c+A[x]-A[y])-A[y],c+A[x]-A[y]);
  }
}
int main() {
  debugMode();
  //Code here
  scanf("%lld",&n);
  foru(i, 1, n+1) {
    scanf("%lld",&a[i]);
  }
  rep(i,n-1) {
    scanf("%lld %lld",&u,&v);
    t[u].push_back(v);
    t[v].push_back(u);
  }
  dfs(1,0);
  dfs2(1,0,B[1],0);
  printf("%lld\n",Max);
  return 0;
}