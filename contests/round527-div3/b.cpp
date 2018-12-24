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
int a[105],n,i,sum;
int main() {
  debugMode();
  //Code here
  scanf("%d",&n);
  rep(i, n)scanf("%d",a+i);
  sort(a, a+n);
  for(i=0; i<n; i+=2) {
    sum += a[i+1]-a[i];
  }
  printf("%d\n",sum);
  return 0;
}